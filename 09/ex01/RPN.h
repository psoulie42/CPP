#include <iostream>
#include <string>
#include <stack>
#include <exception>
#include <stdexcept>

using std::cout;
using std::endl;
using std::stack;
using std::exception;

int toInt(char c);
int isop(char c);
void skipSpace(char** str);
void charCheck(char c);
void opCheck(int op, char c);
std::string parseStr(char* str);
int nextVal(int val, int next, char op);
