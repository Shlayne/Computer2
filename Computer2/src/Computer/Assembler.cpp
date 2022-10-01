#include "Assembler.h"
#include <cctype>
#include <vector>

constexpr bool IsLineEnding(char c) noexcept
{
	return c == '\n' || c == '\r';
}

constexpr bool IsBinaryDigit(char c) noexcept
{
	return c == '0' || c == '1';
}

constexpr bool IsDecimalDigit(char c) noexcept
{
	return '0' <= c && c <= '9';
}

constexpr bool IsHexadecimalDigit(char c) noexcept
{
	return IsDecimalDigit(c) || ('A' <= c && c <= 'F') || ('a' <= c && c <= 'f');
}

constexpr bool IsAlpha(char c) noexcept
{
	return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

constexpr bool IsAlphanumeric(char c) noexcept
{
	return IsDecimalDigit(c) || ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

struct Assembler::Line : std::string_view
{
	size_t number = 0;
};

struct Assembler::TokenizedLine : std::vector<std::string_view>
{
	size_t number = 0;
};

AssemblerOutput Assembler::Assemble(std::string_view source)
{
	if (source.empty())
		return AssemblerReturnCode_EffectivelyEmptySource;

	enum class LabelVisibility : uint8_t
	{
		// Only accessible in this file. This is the default.
		Private,
		// Accessible in any file that includes this file.
		Protected,
		// Accessible in any file that includes this file or any file that
		// includes a file that includes a file ... that includes this file.
		Public
	};

	struct Label
	{
		std::string_view name;
		size_t lineNumber = 0;
		LabelVisibility visibility = LabelVisibility::Private;
	};

	std::vector<Label> labels;
	std::vector<TokenizedLine> tokenizedLines;
	{
		// Separate source code into lines while ignoring preceding whitespace, traling whitespace, and comments.
		std::vector<Line> lines;
		{
			size_t lastSourceIndex = source.size() - 1;

			// Get number of characters in line endings.
			size_t lineEndingCharCount = 1;
			{
				size_t i = 0;
				char c = source.front();
				// Find the end of the first line.
				while (!IsLineEnding(c) && i < lastSourceIndex)
					c = source[++i];

				if (i >= lastSourceIndex)
					return AssemblerReturnCode_EffectivelyEmptySource;

				// Check if the line ending is CRLF.
				if (c == '\r' && source[i + 1] == '\n')
					lineEndingCharCount++;
			}

			size_t lineEndingsEncountered = 0;
			size_t lineBegin = 0;
			while (true)
			{
				// Get first index of a non-whitespace character.
				size_t i = lineBegin;
				char c = source[i];
				while (std::isspace(c) && i < lastSourceIndex)
				{
					if (IsLineEnding(c))
						lineEndingsEncountered++;
					c = source[++i];
				}

				// If there's no more source code, stop looking.
				if (i >= lastSourceIndex)
					break;

				// If the line is not only a comment...
				if (c != ';')
				{
					// Cache the beginning of the line.
					lineBegin = i;

					// Find the end of the line.
					while (c != ';' && !IsLineEnding(c) && i < lastSourceIndex)
						c = source[++i];

					// Remove trailing whitespace.
					size_t lineEnd = i;
					while (lineEnd > lineBegin && std::isblank(source[--lineEnd]));

					// Add the line to the list of lines.
					size_t lineNumber = lineEndingsEncountered / lineEndingCharCount + 1;
					//if (lineEndingCharCount == 2)
					//	assert(lineEndingsEncountered % 2 == 0);
					lines.emplace_back(std::string_view(source.begin() + lineBegin, source.begin() + (lineEnd + 1)), lineNumber);

					if (IsLineEnding(c))
						lineEndingsEncountered++;

					// If there's no more source code, stop looking.
					if (i >= lastSourceIndex)
						break;
				}

				// Get the first possible beginning of the next line.
				if (c == ';')
				{
					do c = source[++i];
					while (!IsLineEnding(c) && i < lastSourceIndex);

					// If there's no more source code, stop looking.
					if (i >= lastSourceIndex)
						break;

					lineEndingsEncountered++;
				}
				lineBegin = i + 1;
			}

			if (lines.empty())
				return AssemblerReturnCode_EffectivelyEmptySource;
		}

		// Tokenize each line and find all label definitions.
		for (const Line& line : lines)
		{
			// If the line could be a label definition...
			if (line.ends_with(':'))
			{
				size_t lastSpace = line.find_last_of(" \t");
				std::string_view labelName = line.substr(lastSpace + 1, line.size() - (lastSpace + 2));
				if (!labelName.empty() && IsLabel(labelName))
				{
					// Check if the label doesn't yet exist...
					for (const Label& label : labels)
						if (label.name == labelName)
							return { AssemblerReturnCode_DuplicateLabelDefinition, line.number };

					// Get label visibility.
					LabelVisibility visibility = LabelVisibility::Private;
					if (lastSpace != std::string_view::npos)
					{
						std::string_view labelVisibility = line.substr(0, lastSpace);
						if (labelVisibility == "public")
							visibility = LabelVisibility::Public;
						else if (labelVisibility == "protected")
							visibility = LabelVisibility::Protected;
						else if (labelVisibility != "private")
							return { AssemblerReturnCode_InvalidLabelDefinition, line.number };
					}

					// Label definition is valid, so add it to the list of labels.
					labels.emplace_back(labelName, line.number, visibility);
				}
				else
					return { AssemblerReturnCode_InvalidLabelDefinition, line.number };
			}
			else // The line could be a directive, an instruction, or a syntax error.
			{
				// directives: origin, byte, word, include, macro, endmacro, if, elif, else, endif, define

				auto& tokenizedLine = tokenizedLines.emplace_back();
				tokenizedLine.number = line.number;

				size_t i = 0;
				char c = line.front();

				// Find the end of the first token.
				while (!std::isspace(c) && ++i < line.size())
					c = line[i];

				tokenizedLine.push_back(line.substr(0, i));

				// Find the rest of the tokens.
				while (i < line.size())
				{
					// Find the start of the current token.
					do c = line[++i];
					while (std::isspace(c) && i < line.size());

					size_t operandStart = i;

					// Find the end of the current token.
					while (c != ',' && ++i < line.size())
						c = line[i];

					size_t operandLength = i - operandStart;
					if (operandLength == 0)
						return { AssemblerReturnCode_InvalidOperand, line.number };

					tokenizedLine.push_back(line.substr(operandStart, operandLength));
				}
			}
		}
	}

	// Anything that expects an integer requires a constexpr evaluation, i.e. using 23 in
	// place of "17 + 6". This includes multiple numbers represented in any supported base,
	// which are binary, decimal, and hexadecimal.



	return AssemblerReturnCode_Success;
}

bool Assembler::IsLabel(std::string_view text)
{
	// Evaluate this regex: "^[_a-zA-Z][._a-zA-Z0-9]*$"

	// If the first character is not valid, text is not a label.
	if (!IsAlpha(text.front()) && text.front() != '_')
		return false;

	// Check the rest of the characters.
	for (size_t j = 1; j < text.size(); j++)
		if (char c = text[j]; !IsAlphanumeric(c) && c != '.' && c != '_')
			return false;

	return true;
}

bool Assembler::IsBinary(std::string_view text, std::string_view& tidiedNumber)
{
	// Evaluate this regex: "^(?:(?:0[bB]|%)[01]+|[01]+[bB])$"

	if (std::tolower(text.back()) == 'b')
	{
		if (text.size() < 2)
			return false;
		for (size_t i = 0; i < text.size() - 1; i++)
			if (char c = text[i]; !IsBinaryDigit(c))
				return false;
		tidiedNumber = text.substr(0, text.size() - 1);
		return true;
	}
	else if (text.front() == '%')
	{
		if (text.size() < 2)
			return false;
		for (size_t i = 1; i < text.size(); i++)
			if (char c = text[i]; !IsBinaryDigit(c))
				return false;
		tidiedNumber = text.substr(1, text.size() - 1);
		return true;
	}
	else if (text.front() == '0')
	{
		if (text.size() < 3 && std::tolower(text[1]) != 'b')
			return false;
		for (size_t i = 2; i < text.size(); i++)
			if (char c = text[i]; !IsBinaryDigit(c))
				return false;
		tidiedNumber = text.substr(2, text.size() - 2);
		return true;
	}
	return false;
}

bool Assembler::IsDecimal(std::string_view text, std::string_view& tidiedNumber)
{
	// Evaluate this regex: "^[0-9]+$"

	for (char c : text)
		if (!IsDecimalDigit(c))
			return false;
	tidiedNumber = text;
	return true;
}

bool Assembler::IsHexadecimal(std::string_view text, std::string_view& tidiedNumber)
{
	// Evaluate this regex: "^(?:(?:0[xX]|\$)[0-9a-fA-F]+|[0-9a-fA-F]+[hH])$"

	if (std::tolower(text.back()) == 'h')
	{
		if (text.size() < 2)
			return false;
		for (size_t i = 0; i < text.size() - 1; i++)
			if (char c = text[i]; !IsHexadecimalDigit(c))
				return false;
		tidiedNumber = text.substr(0, text.size() - 1);
		return true;
	}
	else if (text.front() == '$')
	{
		if (text.size() < 2)
			return false;
		for (size_t i = 1; i < text.size(); i++)
			if (char c = text[i]; !IsHexadecimalDigit(c))
				return false;
		tidiedNumber = text.substr(1, text.size() - 1);
		return true;
	}
	else if (text.front() == '0')
	{
		if (text.size() < 3 && std::tolower(text[1]) != 'x')
			return false;
		for (size_t i = 2; i < text.size(); i++)
			if (char c = text[i]; !IsHexadecimalDigit(c))
				return false;
		tidiedNumber = text.substr(2, text.size() - 2);
		return true;
	}
	return false;
}

uint8_t Assembler::GetBase(std::string_view text, std::string_view& tidiedNumber)
{
	if (text.empty())
		return 0;
	if (IsBinary(text, tidiedNumber))
		return 2;
	if (IsDecimal(text, tidiedNumber))
		return 10;
	if (IsHexadecimal(text, tidiedNumber))
		return 16;
	return 0;
}
