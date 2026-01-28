#include "BitcoinExchange.hpp"

// -------------- BITCOIN ECHANGE MEMBER FUNCTIONS -------------

void BitcoinExchange::processFile()
{
	std::map<string, double> ref = parseCSV();

	std::map<string, double>::iterator it = _map.begin();

	while (it != _map.end())
	{

	}
}

std::map<string, double> BitcoinExchange::ParseCSV()
{
	std::ifstream file("data.csv");
	if (!file)
		throw std::runtime_error("Rends moi mon fichier wsh");

	// parsing file
	std::map<string, double> ref;
	string line;
	struct tm time;
	double value;

	getline(file, line);

	if (line != "date | value\n")
	{
		checkCSVLine(line, &time, value);
		ref.insert({getDate(line), value});
	}

	while (getline(file, line))
	{
		checkCSVLine(line, &time, value);
		ref.insert({getDate(line), value});
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
	struct tm time;
	double value;

	getline(file, line);

	if (line != "date | value\n")
	{
		checkLine(line, &time, value);
		_map.insert({getDate(line), value});
	}

	while (getline(file, line))
	{
		checkLine(line, &time, value);
		_map.insert({getDate(line), value});
	}
}

void BitcoinExchange::checkLine(string line, struct tm* time, double& value)
{

	// checking if the format of a line corresponds to:
	// YYYY-MM-DD | value
	// (I know it's hideous)
	int i = 0;
	while (i < 4)
	{
		if (!isdigit(line[i]))
			throw BitcoinExchange::InvalidFormatException();
		i++;
	}
	if (line[i] != '-')
		throw BitcoinExchange::InvalidFormatException();
	i++;
	for (int i = 0; i < 2; i++)
	{
		if (!isdigit(line[i]))
			throw BitcoinExchange::InvalidFormatException();
	}
	if (line[i] != '-')
		throw BitcoinExchange::InvalidFormatException();
	for (int j = 0; j < 2; j++)
	{
		if (!isdigit(line[i]))
			throw BitcoinExchange::InvalidFormatException();
		i++;
	}
	if (line[i] != ' ' || line[++i] != '|' || line[++i] != ' ')
		throw BitcoinExchange::InvalidFormatException();
	while (line[i])
	{
		if (!isdigit(line[i]))
			throw BitcoinExchange::InvalidFormatException();
		i++;
	}
	
	// checking and assigning date
	char year[4], month[2], day[2];

	line.copy(year, 4, 0);
	line.copy(month, 2, 5);
	line.copy(day, 2, 7);

	time->tm_year = std::strtod(year, NULL);
	time->tm_mon = std::strtod(month, NULL) - 1;
	time->tm_mday = std::strtod(day, NULL);

	if (time->tm_year > 2025 || time->tm_year < 2009 ||
		time->tm_mon > 11 || time->tm_mon < 0 ||
		time->tm_mday > 31)
	{
		throw BitcoinExchange::InvalidFormatException();	
	}

	// checking and assigning value
	char* val;
	line.copy(val, 10, 13);

	value = std::strtod(val, NULL);
	if (value > 1000)
		throw BitcoinExchange::InvalidFormatException();	
}


string BitcoinExchange::getDate(string line)
{
	string ret;

	char s[20];
	line.copy(s, 10, 0);

	return (ret = s);
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
