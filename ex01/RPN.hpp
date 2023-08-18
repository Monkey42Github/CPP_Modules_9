#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cctype>


int     ReversePolishNotation(std::string rpnExpression);
int     calculate(int op1, int op2, char op);
bool    is_caractvalid(std::string test);
bool    is_symbole(const char c);



#endif