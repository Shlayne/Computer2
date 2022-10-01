#pragma once

#include <string_view>
#include <vector>

using AssemblerReturnCode = uint16_t;
enum AssemblerReturnCode_ : AssemblerReturnCode
{
	AssemblerReturnCode_Success = 0,

	// Warnings
	AssemblerReturnCode_EffectivelyEmptySource = 0x1000,

	// Errors
	AssemblerReturnCode_EmptyLabelDefinition = 0x2000,
	AssemblerReturnCode_InvalidLabelDefinition,
	AssemblerReturnCode_DuplicateLabelDefinition,
	AssemblerReturnCode_InvalidDirective,
	AssemblerReturnCode_InvalidOperand,
	AssemblerReturnCode_InvalidStringLiteral,
};

struct AssemblerProgramSection
{
	uint16_t origin = 0;
	std::vector<uint8_t> assembly;
};

struct AssemblerOutput
{
	AssemblerReturnCode returnCode = AssemblerReturnCode_Success;
	size_t lineNumber = 0; // Only relevant if returnCode is not AssemblerReturnCode_Success.
	std::vector<AssemblerProgramSection> sections; // Only relevant if returnCode is AssemblerReturnCode_Success.

	constexpr AssemblerOutput() noexcept = default;
	constexpr AssemblerOutput(AssemblerReturnCode returnCode, size_t lineNumber = 0, std::vector<AssemblerProgramSection>&& sections = {}) noexcept
		: returnCode(returnCode), lineNumber(lineNumber), sections(std::move(sections)) {}

	constexpr operator bool() const noexcept
	{
		return returnCode == AssemblerReturnCode_Success;
	}
};

class Assembler
{
public:
	// Assumes line endings are one of LF, CRLF, or CR, and are consistent.
	// Otherwise, you could get errors and warnings reported on incorrect lines.
	// NOTE: the data source points to must stay alive for the duration of this function.
	static AssemblerOutput Assemble(std::string_view source);
private:
	struct Line;
	struct TokenizedLine;
private:
	static bool IsLabel(std::string_view text);
	static bool IsBinary(std::string_view text, std::string_view& tidiedNumber);
	static bool IsDecimal(std::string_view text, std::string_view& tidiedNumber);
	static bool IsHexadecimal(std::string_view text, std::string_view& tidiedNumber);
	static uint8_t GetBase(std::string_view text, std::string_view& tidiedNumber);
private:
	Assembler() = delete;
	Assembler(const Assembler&) = delete;
	Assembler(Assembler&&) = delete;
	Assembler& operator=(const Assembler&) = delete;
	Assembler& operator=(Assembler&&) = delete;
	~Assembler() = delete;
};
