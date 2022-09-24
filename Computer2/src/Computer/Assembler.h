#pragma once

#include <string_view>

class Assembler
{
public:
	static void Assemble(std::string_view source);
private:
	Assembler() = delete;
	Assembler(const Assembler&) = delete;
	Assembler(Assembler&&) = delete;
	Assembler& operator=(const Assembler&) = delete;
	Assembler& operator=(Assembler&&) = delete;
	~Assembler() = delete;
};
