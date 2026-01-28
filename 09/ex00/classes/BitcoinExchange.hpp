#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <map>
#include <exception>

using std::cout;
using std::endl;
using std::string;
using std::getline;

class BitcoinExchange
{
	private:
		std::map<string, double> _map;

		void BitcoinExchange::checkLine(string line, struct tm* time, double& value);
		string BitcoinExchange::getDate(string line);
		std::map<string, double> parseCSV();

	public:
		void parseInput(const string& filename);
		void processFile();

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange&);
		BitcoinExchange& operator=(const BitcoinExchange&);
		~BitcoinExchange();

	class InvalidFormatException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};
