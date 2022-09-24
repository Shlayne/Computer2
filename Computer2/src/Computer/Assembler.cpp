#include "Assembler.h"
#include <cctype>
#include <vector>

void Assembler::Assemble(std::string_view source)
{
	if (source.empty())
		return;

	std::vector<std::vector<std::string_view>> tokens;
	{
		// Separate source code into lines while ignoring preceding whitespace, traling whitespace, and comments.
		std::vector<std::string_view> lines;
		{
			size_t lastSourceIndex = source.size() - 1;
			size_t lineBegin = 0;

			while (true)
			{
				// Get first index of a non-whitespace character.
				size_t i = lineBegin;
				char c = source[i];
				while (std::isspace(c) && i < lastSourceIndex)
					c = source[++i];

				// If there's no more source code, stop looking.
				if (i >= lastSourceIndex)
					break;

				// If the line is not only a comment...
				if (c != ';')
				{
					// Cache the beginning of the line.
					lineBegin = i;

					// Find the end of the line.
					while (c != ';' && c != '\n' && c != '\r' && i < lastSourceIndex)
						c = source[++i];

					// Remove trailing whitespace.
					size_t lineEnd = i;
					while (lineEnd > lineBegin && std::isblank(source[--lineEnd]));

					// Add the line to the list of lines.
					lines.emplace_back(source.begin() + lineBegin, source.begin() + (lineEnd + 1));

					// If there's no more source code, stop looking.
					if (i >= lastSourceIndex)
						break;
				}

				// Get the first possible beginning of the next line.
				if (c == ';')
				{
					do c = source[++i];
					while (c != '\n' && c != '\r' && i < lastSourceIndex);

					// If there's no more source code, stop looking.
					if (i >= lastSourceIndex)
						break;
				}
				lineBegin = i + 1;
			}
		}

		// Tokenize each line.
		{
			// test_program.asm reaches here with correct lines.
			// Now, tokenizing the line will work differently depending on the type of line.
			// For example, .db statements have whitespace after the .db, then a comma-separated list of values,
			// where the tokens would be ".db", then each value in order, whereas an instruction like "ldi a, 17 + 6"
			// would have the tokens "ldi", "a", "17 + 6", i.e., explicitly having spaces in the token.
			// Any instruction can be split by the first whitespace, then optional whitespace, a comma, and more whitespace,
			// then the rest of the line.

			// Also worth noting is that anything that expects an integer requires a constexpr evaluation,
			// i.e. using 23 in place of "17 + 6". This includes adding numbers represented in any supported base,
			// which are binary, decimal, and hexidecimal.
		}
	}
}
