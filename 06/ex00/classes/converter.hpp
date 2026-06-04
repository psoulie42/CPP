#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <stdlib.h>

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INF_NAN
};

class ScalarConverter
{
	public:
		static void convert(const std::string& n);
};
