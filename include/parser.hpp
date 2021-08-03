#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "token.hpp"
#include "key.hpp"

class Parser
{
	private:
		KeyValue *parseObject();
	
	public:
		std::string &text;
		
		std::vector<Token> tokens;
		
		Parser(std::string &text);
		
		void tokenize();
		
		KeyValue *parse();
};