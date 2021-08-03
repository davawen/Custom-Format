#include "parser.hpp"

Parser::Parser(std::string &text) : text(text) {}

void Parser::tokenize()
{
	int pos = 0;
	
	// The first pass separate the control characters from the rest
	std::vector<Token> singleTokens;
	singleTokens.reserve(text.length());
	
	while(true)
	{
		char chr = text[pos];
		
		if(!chr) break;
		
		std::string newchr;
		
		switch(chr)
		{
			case '\\': // Escape character
				pos++;
				newchr = text[pos];
				singleTokens.push_back(Token(Token::Type::CHAR, newchr));
				break;
			case ' ':
				singleTokens.push_back(Token(Token::Type::SPACE, " "));
				break;
			case ':':
				singleTokens.push_back(Token(Token::Type::COLON, ":"));
				break;
			case ';':
				singleTokens.push_back(Token(Token::Type::SEMICOLON, ";"));
				break;
			case '\"':
				singleTokens.push_back(Token(Token::Type::QUOTE, "\""));
				break;
			case '\n':
				singleTokens.push_back(Token(Token::Type::NEWLINE, "\n"));
				break;
			case '\t':
				singleTokens.push_back(Token(Token::Type::TAB, "\t"));
				break;
			default:
				newchr = chr;
				singleTokens.push_back(Token(Token::Type::CHAR, newchr));
				break;
		}
		
		pos++;
	}

	// Join grouped tokens together
	
	std::string currentValue;
	
	for(auto &token : singleTokens)
	{
		switch(token.type)
		{
			case Token::Type::CHAR:
				currentValue += token.value;
				break;
			default:
				if(!currentValue.empty())
				{
					tokens.push_back( Token( Token::Type::CHAR, currentValue ) );
					currentValue.clear();
				}
				tokens.push_back(std::move(token));
				break;
		}
	}
}

KeyValue *Parser::parse()
{
	KeyValue *head = new KeyValue("", nullptr, true);
	
	/// false -> reading a key
	/// true -> reading a value
	bool isValue = false;
	
	for(auto &token : tokens)
	{
		
	}
	
	return head;
}