#include "BitcoinExchange.hpp"

// -------------- BITCOIN ECHANGE MEMBER FUNCTIONS -------------

void BitcoinExchange::processFile()
{
	parseCSV();

	std::map<std::string, double>::iterator it = _map.begin();
	std::map<std::string, double>::iterator it2;
	
	while (it != _map.end())
	{
		it2 = _ref.begin();
		while (it2 != _ref.end() && getDate(it->first) >= getDate(it2->first))
			it2++;

		if (it->second == -1)
			printError(it);
		else if (it2 != _ref.begin())
			printResult(it, --it2);
		else
			printResult(it, it2);

		it++;
	}
}

void BitcoinExchange::printError(std::map<std::string, double>::iterator it)
{
	double val = 0;

	try
	{
		checkLine(it->first, val);
	}
	catch (std::exception& e)
	{
		std::cout << it->first << ": " << e.what() << std::endl;
	}
}

void BitcoinExchange::printResult(std::map<std::string, double>::iterator it, std::map<std::string, double>::iterator it2)
{
	for (int i = 0; i < 10; i++)
		std::cout << it->first[i];
	std::cout << " => " << it->second << " = " << it->second * it2->second << std::endl;
}

void BitcoinExchange::parseCSV()
{
	std::ifstream file("data.csv");
	if (!file)
		throw std::runtime_error("Rends moi mon fichier wsh");

	// parsing file
	std::string line;
	double value = 0;

	std::getline(file, line);

	if (line != "date,exchange_rate")
	{
		checkCSVLine(line, value);
		_ref.insert(std::pair<std::string, double>(line, value));
	}

	while (std::getline(file, line))
	{
		checkCSVLine(line, value);
		_ref.insert(std::pair<std::string, double>(line, value));
	}
}

void BitcoinExchange::parseInput(const std::string& filename)
{
	// opening file
	std::ifstream file(filename.c_str());
	if (!file)
		throw std::runtime_error("Error: Couldn't open file!");

	// parsing file
	std::string line;
	double value = 0;

	std::getline(file, line);

	if (line != "date | value")
	{
		try
		{
			checkLine(line, value);
		}
		catch(const std::exception& e)
		{
			_map.insert(std::pair<std::string, double>(line, -1));
		}
		
		_map.insert(std::pair<std::string, double>(line, value));
	}
	
	while (std::getline(file, line))
	{
		try
		{
			checkLine(line, value);
		}
		catch(const std::exception& e)
		{
			_map.insert(std::pair<std::string, double>(line, -1));
		}

		_map.insert(std::pair<std::string, double>(line, value));
	}
}

void BitcoinExchange::checkCSVLine(std::string line, double& value)
{

	// checking if the format of a line corresponds to:
	// YYYY-MM-DD,value
	if (line.size() < 12)
		throw BitcoinExchange::InvalidFormatException();
	
	bool dot = false;
	for (int i = 0; line[i]; i++)
	{
		// check if the date has the correct format
		if (i == 4 || i == 7)
		{
			if (line[i] != '-')
			throw std::invalid_argument("Bad CSV date format: -");
		}
		else if (i < 10 && !isdigit(line[i]))
			throw std::invalid_argument("Bad CSV date format: digits");
		
		// check if there's a comma in the right place
		else if (i == 10 && line[i] != ',')
			throw BitcoinExchange::InvalidFormatException();

		// check if the value actually is a number
		else if (i > 10 && dot && !isdigit(line[i]))
			throw BitcoinExchange::InvalidFormatException();
		else if (i > 10 && !isdigit(line[i]) && line[i] != '.')
			throw BitcoinExchange::InvalidFormatException();
		else if (i > 10 && line[i] == '.')
			dot = true;
	}

	// checking and assigning date
	std::string year(line, 0, 4), month(line, 5, 2), day(line, 8, 2);

	std::tm time1 = {};

	time1.tm_year = std::strtod(year.c_str(), NULL) - 1900;
	time1.tm_mon = std::strtod(month.c_str(), NULL) - 1;
	time1.tm_mday = std::strtod(day.c_str(), NULL);

	std::tm time2 = time1;
	std::mktime(&time2);
	if (time1.tm_year != time2.tm_year ||
		time1.tm_mon != time2.tm_mon ||
		time1.tm_mday != time2.tm_mday)
	{
		throw std::invalid_argument("Error: Invalid date! (CSV)");	
	}

	// checking and assigning value
	std::string val(line, 11, 10);

	value = std::strtod(val.c_str(), NULL);
}

void BitcoinExchange::checkLine(std::string line, double& value)
{
	// checking if the format of a line corresponds to:
	// YYYY-MM-DD | value
	bool dot = false;
	if (line.size() < 14)
		throw std::invalid_argument("Line too short");

	for (int i = 0; line[i]; i++)
	{
		// check if the date has the correct format
		if (i == 4 || i == 7)
		{
			if (line[i] != '-')
				throw std::invalid_argument("Invalid date format: -");
		}
		else if (i < 10 && !isdigit(line[i]))
			throw std::invalid_argument("Invalid date format: digits");
		
		// check if there's a separation in the right place
		else if (i == 10 && (line[i] != ' ' || line[i + 1] != '|' || line[i + 2] != ' '))
			throw std::invalid_argument("Invalid line format");

		// check if the value actually is a number
		else if (i == 13 && !isdigit(line[i]))
			throw std::invalid_argument("Value must be a positive float or int");
		else if (i > 12 && dot && !isdigit(line[i]))
			throw std::invalid_argument("Value must be a positive float or int");
		else if (i > 12 && !isdigit(line[i]) && line[i] != '.')
			throw std::invalid_argument("Value must be a positive float or int");
		else if (i > 12 && line[i] == '.')
			dot = true;
	}

	// checking and assigning date
	std::string year(line, 0, 4), month(line, 5, 2), day(line, 8, 2);

	std::tm time1 = {};

	time1.tm_year = std::strtod(year.c_str(), NULL) - 1900;
	time1.tm_mon = std::strtod(month.c_str(), NULL) - 1;
	time1.tm_mday = std::strtod(day.c_str(), NULL);

	std::tm time2 = time1;
	std::mktime(&time2);
	if (time1.tm_year != time2.tm_year ||
		time1.tm_mon != time2.tm_mon ||
		time1.tm_mday != time2.tm_mday)
	{
		throw std::invalid_argument("Date doesn't exist");
	}

	// checking and assigning value
	std::string val(line, 13, 10);

	value = std::strtod(val.c_str(), NULL);
	if (value > 1000)
		throw std::invalid_argument("Value can't be > 1000");	
}

std::string BitcoinExchange::getDate(std::string line)
{
	std::string ret;

	for (int i = 0; i < 10; i++)
	{
		ret += line[i];
	}

	return (ret);
}

const char* BitcoinExchange::InvalidFormatException::what() const throw()
{
	return ("Error: Invalid input format");
}


// -------------- CONSTRUCTORS & DESTRUCTORS -------------

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& b): _map(b._map) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& r)
{
	if (this == &r)
		return *this;
	
	_map = r._map;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}
