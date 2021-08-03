#pragma once

#include <ostream>
#include <stdio.h>
#include <string.h>

struct Token
{
	enum struct Type
	{
		CHAR,
		COLON,
		QUOTE,
		SEMICOLON,
		SPACE,
		NEWLINE,
		TAB
	};
	
	Type type;
	std::string value;

	Token(Type type, std::string value);
};

std::ostream &operator<<(std::ostream &, const Token &);