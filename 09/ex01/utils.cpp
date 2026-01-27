#include "RPN.h"

int toInt(char c)
{
	return (c - 48);
}

int isop(char c)
{
	if (c == '*' || c == '+' || c == '-' || c == '/')
		return 1;
	return 0;
}

void skipSpace(char** str)
{
	while (std::isspace(**str))
		(*str)++;
}

int nextVal(int val, int next, char op)
{
	switch (op)
	{
		case '+':
			return val + next;
		
		case '-':
			return val - next;

		case '*':
			return val * next;

		case '/':
			if (next == 0)
				throw std::invalid_argument("Error: You tried to divide by zero!");
			return val / next;
		
		default:
			throw std::runtime_error("wtf");
	}
}
