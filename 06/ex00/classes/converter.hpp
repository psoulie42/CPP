#pragma once

#include <iostream>
#include <string>
#include <limits>

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
