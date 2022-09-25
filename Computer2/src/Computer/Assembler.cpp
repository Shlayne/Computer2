#include "Assembler.h"
#include <cassert>
#include <cctype>
#include <iostream>
#include <vector>

constexpr bool IsLineEnd(char c) noexcept
{
	return c == '\n' || c == '\r';
}

AssemblerOutput Assembler::Assemble(std::string_view source)
{
	if (source.empty())
		return AssemblerReturnCode_EffectivelyEmptySource;

	struct Label
	{
		std::string_view name;
		size_t lineNumber = 0;
	};

	std::vector<Label> labels;
	std::vector<std::vector<std::string_view>> tokens;
	{
		// Separate source code into lines while ignoring preceding whitespace, traling whitespace, and comments.
		struct Line
		{
			std::string_view contents;
			size_t number = 0;
		};

		std::vector<Line> lines;
		{
			size_t lastSourceIndex = source.size() - 1;

			// Get number of characters in line endings.
			size_t lineEndingCharCount = 1;
			{
				char c = source[0];
				size_t i = 0;
				// Find the end of the first line.
				while (!IsLineEnd(c) && i < lastSourceIndex)
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
					if (IsLineEnd(c))
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
					while (c != ';' && !IsLineEnd(c) && i < lastSourceIndex)
						c = source[++i];

					// Remove trailing whitespace.
					size_t lineEnd = i;
					while (lineEnd > lineBegin && std::isblank(source[--lineEnd]));

					// Add the line to the list of lines.
					size_t lineNumber = lineEndingsEncountered / lineEndingCharCount + 1;
					if (lineEndingCharCount == 2)
						assert(lineEndingsEncountered % 2 == 0);
					lines.emplace_back(std::string_view(source.begin() + lineBegin, source.begin() + (lineEnd + 1)), lineNumber);

					if (IsLineEnd(c))
						lineEndingsEncountered++;

					// If there's no more source code, stop looking.
					if (i >= lastSourceIndex)
						break;
				}

				// Get the first possible beginning of the next line.
				if (c == ';')
				{
					do c = source[++i];
					while (!IsLineEnd(c) && i < lastSourceIndex);

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
		{
			// test_program.asm reaches here with correct lines.
			// Now, tokenizing the line will work differently depending on the type of line.
			// For example, .db statements have whitespace after the .db, then a comma-separated list of values,
			// where the tokens would be ".db", then each value in order, whereas an instruction like "ldi a, 17 + 6"
			// would have the tokens "ldi", "a", "17 + 6", i.e., explicitly having spaces in the token.
			// Any instruction can be split by the first whitespace, then optional whitespace, a comma, and more whitespace,
			// then the rest of the line.

			// Also worth noting is that anything that expects an integer requires a constexpr evaluation,
			// i.e. using 23 in place of "17 + 6". This includes multiple numbers represented in any supported base,
			// which are binary, decimal, and hexadecimal.

			for (const auto& [line, lineNumber] : lines)
			{
				// If the line could be a label definition...
				if (line.ends_with(':'))
				{
					if (line.size() > 1)
					{
						// Evaluate this regex on line without using a regex because C++'s std::regex is ironically slow.
						// "^[._a-zA-Z][._a-zA-Z0-9]*:$"

						// If the first character in the label is valid...
						if (std::isalpha(line.front()) || line.front() == '.' || line.front() == '_')
						{
							// If the rest of the characters in the label are valid...
							for (size_t j = 1; j < line.size() - 1; j++)
							{
								char c = line[j];
								if (!(std::isalnum(c) || c == '.' || c == '_'))
									return { AssemblerReturnCode_InvalidLabelDefinition, lineNumber };
							}

							std::string_view newLabel = line.substr(0, line.size() - 1);

							// If the label doesn't yet exist...
							for (auto& [label, index] : labels)
								if (label == newLabel)
									return { AssemblerReturnCode_DuplicateLabelDefinition, lineNumber };

							// Label definition is valid, so add it to the list of labels.
							labels.emplace_back(newLabel, lineNumber);
						}
						else
							return { AssemblerReturnCode_InvalidLabelDefinition, lineNumber };
					}
					else
						return { AssemblerReturnCode_EmptyLabelDefinition, lineNumber };
				}
				// If the line could be an assembler directive...
				else if (line.starts_with('.'))
				{
					std::string_view directive = line.substr(1);
					directive = directive.substr(0, directive.find(' '));

					if (directive == "org")
					{

					}
					else if (directive == "db")
					{

					}
					else if (directive == "dw")
					{

					}
				}
			}
		}
	}

	return AssemblerReturnCode_Success;
}
