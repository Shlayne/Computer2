#pragma once

#include <string_view>

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
};

struct AssemblerOutput
{
	AssemblerReturnCode code = AssemblerReturnCode_Success;
	size_t line = 0;

	constexpr AssemblerOutput() noexcept = default;
	constexpr AssemblerOutput(AssemblerReturnCode code, size_t line = 0) noexcept
		: code(code), line(line) {}

	constexpr operator bool() const noexcept
	{
		return code == AssemblerReturnCode_Success;
	}
};

class Assembler
{
public:
	// Assumes line endings are one of LF, CRLF, or CR, and are consistent.
	// Otherwise, you could get errors reported on incorrect lines.
	static AssemblerOutput Assemble(std::string_view source);
private:
	Assembler() = delete;
	Assembler(const Assembler&) = delete;
	Assembler(Assembler&&) = delete;
	Assembler& operator=(const Assembler&) = delete;
	Assembler& operator=(Assembler&&) = delete;
	~Assembler() = delete;
};
