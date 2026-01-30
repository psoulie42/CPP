#include "BitcoinExchange.hpp"

// -------------- BITCOIN ECHANGE MEMBER FUNCTIONS -------------

void BitcoinExchange::processFile()
{
	parseCSV();

	std::map<string, double>::iterator it = _map.begin();
	std::map<string, double>::iterator it2;
	
	while (it != _map.end())
	{
		it2 = _ref.begin();
		while (it2 != _ref.end() && it2->first < it->first)
			it2++;

		if (it->second == -1)
			printError(it);
		else
			printResult(it, it2);

		it++;
	}
}

void BitcoinExchange::printError(std::map<string, double>::iterator it)
{
	std::tm time;
	double val;

	try
	{
		checkLine(it->first, &time, val);
	}
	catch (std::exception& e)
	{
		cout << e.what() << endl;
	}
}

void BitcoinExchange::printResult(std::map<string, double>::iterator it, std::map<string, double>::iterator it2)
{
	for (int i = 0; i < 10; i++)
		cout << it->first[i];
	cout << " => " << it->second << " = " << it->second * it2->second << endl;
}

void BitcoinExchange::parseCSV()
{
	std::ifstream file("data.csv");
	if (!file)
		throw std::runtime_error("Rends moi mon fichier wsh");

	// parsing file
	string line;
	std::tm time;
	double value = 0;

	getline(file, line);

	if (line != "date,exchange_rate")
	{
		checkCSVLine(line, &time, value);
		_ref.insert(std::pair<string, double>(line, value));
	}

	while (getline(file, line))
	{
		checkCSVLine(line, &time, value);
		_ref.insert(std::pair<string, double>(line, value));
	}
}

void BitcoinExchange::parseInput(const string& filename)
{
	// opening file
	std::ifstream file(filename);
	if (!file)
		throw std::runtime_error("Error: Couldn't open file!");

	// parsing file
	string line;
	std::tm time;
	double value = 0;

	getline(file, line);

	if (line != "date | value")
	{
		try
		{
			checkLine(line, &time, value);
		}
		catch(const std::exception& e)
		{
			_map.insert(std::pair<string, double>(line, -1));
		}
		
		_map.insert(std::pair<string, double>(line, value));
	}
	
	while (getline(file, line))
	{
		try
		{
			checkLine(line, &time, value);
		}
		catch(const std::exception& e)
		{
			_map.insert(std::pair<string, double>(line, -1));
		}

		_map.insert(std::pair<string, double>(line, value));
	}
}

void BitcoinExchange::checkCSVLine(string line, std::tm* time, double& value)
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
	char year[4], month[2], day[2];

	line.copy(year, 4, 0);
	line.copy(month, 2, 5);
	line.copy(day, 2, 7);

	time->tm_year = std::strtod(year, NULL);
	time->tm_mon = std::strtod(month, NULL) - 1;
	time->tm_mday = std::strtod(day, NULL);

	if (time->tm_year < 2009 ||
		time->tm_year != std::strtod(year, NULL) ||
		time->tm_mon != std::strtod(month, NULL) - 1 ||
		time->tm_mday != std::strtod(day, NULL))
	{
		throw std::invalid_argument("Error: Invalid date! (CSV)");	
	}

	// checking and assigning value
	char val[11];
	line.copy(val, 10, 11);

	value = std::strtod(val, NULL);
	if (value > 1000)
		throw BitcoinExchange::InvalidFormatException();	
}

void BitcoinExchange::checkLine(string line, std::tm* time, double& value)
{
	// checking if the format of a line corresponds to:
	// YYYY-MM-DD | value
	bool dot = false;
	for (int i = 0; line[i]; i++)
	{
		// check if the date has the correct format
		if (i == 4 || i == 7)
		{
			if (line[i] != '-')
				throw std::invalid_argument("Bad date format: -");
		}
		else if (i < 10 && !isdigit(line[i]))
			throw std::invalid_argument("Bad date format: digits");
		
		// check if there's a separation in the right place
		else if (i == 10 && (line[i] != ' ' || line[i + 1] != '|' || line[i + 2] != ' '))
			throw std::invalid_argument("Bad line format");

		// check if the value actually is a number
		else if (i > 12 && dot && !isdigit(line[i]))
			throw std::invalid_argument("Value must be a positive float or int");
		else if (i > 12 && !isdigit(line[i]) && line[i] != '.')
			throw std::invalid_argument("Value must be a positive float or int");
		else if (i > 12 && line[i] == '.')
			dot = true;
	}

	// checking and assigning date
	char year[5], month[3], day[3];

	line.copy(year, 4, 0);
	line.copy(month, 2, 5);
	line.copy(day, 2, 8);

	std::tm time1 = {};

	time1.tm_year = std::strtod(year, NULL) - 1900;
	time1.tm_mon = std::strtod(month, NULL) - 1;
	time1.tm_mday = std::strtod(day, NULL);

	std::tm time2 = time1;
	std::mktime(&time2);
	if (time1.tm_year != time2.tm_year ||
		time1.tm_mon != time2.tm_mon ||
		time1.tm_mday != time2.tm_mday)
	{
		throw BitcoinExchange::InvalidFormatException();
	}

	// checking and assigning value
	char val[11];
	line.copy(val, 10, 13);

	value = std::strtod(val, NULL);
	if (value > 1000)
		throw BitcoinExchange::InvalidFormatException();	
}

string BitcoinExchange::getDate(string line)
{
	string ret;

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
