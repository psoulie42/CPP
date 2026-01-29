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
		std::map<string, double> _ref;

		void checkLine(string line, struct tm* time, double& value);
		void checkCSVLine(string line, struct tm* time, double& value);

		void printResult(std::map<string, double>::iterator, std::map<string, double>::iterator);

	public:
		string getDate(string line);
		void parseCSV();
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
