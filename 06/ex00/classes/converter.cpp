#include "converter.hpp"

static Type inputType(const std::string& n)
{
	if (n.empty())
		return INF_NAN;

	// check for char
	if (n.size() == 0 && !isdigit(n.c_str()[0]))
		return CHAR;
	
	// check for int
	char* end;
	long val = std::strtol(n.c_str(), &end, 10);
	if (*end == 0)
	{
		if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
			return INF_NAN;
		else
			return	INT;
	}

	// check for float
	std::strtof(n.c_str(), &end);
	if (*end == 'f')
		return FLOAT;
	
	// check for double
	std::strtod(n.c_str(), &end);
	if (*end == 0)
		return DOUBLE;
	
	// none of the above
	return INF_NAN;
}

void	ScalarConverter::convert(const std::string& n)
{
	char	charVal;
	int		intVal;
	float	floatVal;
	double	doubleVal;
	bool	isValidInt = true;
	
	switch (inputType(n))
	{
		case 0:
			charVal = n[0];
			intVal = static_cast<int>(charVal);
			floatVal = static_cast<float>(charVal);
			doubleVal = static_cast<double>(charVal);
			break;
		case 1:
			intVal = std::strtol(n.c_str(), NULL, 10);
			charVal = static_cast<char>(intVal);
			floatVal = static_cast<float>(intVal);
			doubleVal = static_cast<double>(intVal);
			break;
		case 2:
			floatVal = std::strtof(n.c_str(), NULL);
			charVal = static_cast<char>(floatVal);
			intVal = static_cast<int>(floatVal);
			doubleVal = static_cast<double>(floatVal);
			break;
		case 3:
			doubleVal = std::strtod(n.c_str(), NULL);
			charVal = static_cast<char>(doubleVal);
			intVal = static_cast<int>(doubleVal);
			floatVal = static_cast<float>(doubleVal);
			break;
		default:
			floatVal = std::numeric_limits<float>::quiet_NaN();
			doubleVal = std::numeric_limits<double>::quiet_NaN();
			isValidInt = false;
	}
	// print char
	if (isValidInt == false || intVal < 0 || intVal > 127)
		std::cout << "char: invalid" << std::endl;
	else if (intVal < 32 || intVal > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << charVal << "'" << std::endl;
	// print int
	if (isValidInt == true && doubleVal >= std::numeric_limits<int>::min() && doubleVal < std::numeric_limits<int>::max())
		std::cout << "int: " << intVal << std::endl;
	else
		std::cout << "int: invalid" << std::endl;
	// print float
	std::cout << "float: " << floatVal << "f" << std::endl;
	// print double
	std::cout << "double: " << doubleVal << std::endl;
}
