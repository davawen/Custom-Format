#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <stdio.h>

#include "parser.hpp"

std::string getFile(const char *filename)
{
	FILE *file = fopen(filename, "r");
	
	std::string str;
	char ch;
	while((ch = fgetc(file)) != EOF)
		str += ch;
	
	fclose(file);
	
	return str;
}

int main(/* int argc, char *argv[] */)
{
	std::string content = getFile("./assets/test.jjj");
	
	Parser parser = Parser(content);
	
	parser.tokenize();
	
	for(auto &token : parser.tokens)
	{
		std::cout << token << std::endl;
	}
	
	// std::cout << content << std::endl;
	
	// std::cout << "Hey!!" << std::endl;
	
	return 0;
}
