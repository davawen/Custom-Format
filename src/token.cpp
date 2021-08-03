#include "token.hpp"

Token::Token(Token::Type type, std::string value)
{
	this->type = type;
	this->value = value;
}

std::ostream &operator<<(std::ostream &os, const Token &token)
{
	os << "TYPE: " << (int)token.type << " | VALUE: '" << token.value << '\'';
	
	return os;
}