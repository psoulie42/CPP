#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <map>
#include <exception>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _map;
		std::map<std::string, double> _ref;

		void checkLine(std::string line, double& value);
		void checkCSVLine(std::string line, double& value);

		void printResult(std::map<std::string, double>::iterator, std::map<std::string, double>::iterator);
		void printError(std::map<std::string, double>::iterator);

	public:
		std::string getDate(std::string line);
		void parseCSV();
		void parseInput(const std::string& filename);
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
