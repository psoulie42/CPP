#include "ShrubberyCreationForm.hpp"

// ------------- SCF MEMBER FUNCTIONS -------------

void SCF::_performAction() const
{
	std::ofstream fout;
	fout.open(_target + "_shrubbery", std::ios::out);

	fout << std::endl;
    fout << "                 .o00o				      '.o00o			" << std::endl;
    fout << "               o000000oo			    'o000000oo			" << std::endl;
    fout << "              00000000000o			   '00000000000o		" << std::endl;
    fout << "             00000000000000		  '00000000000000		" << std::endl;
    fout << "          oooooo  00000000  o88o'oooooo  00000000  o88o	" << std::endl;
    fout << "       ooOOOOOOOoo  ```''  888'ooOOOOOOOoo  ```''  888888	" << std::endl;
    fout << "     OOOOOOOOOOOO'.qQQQQq. `'OOOOOOOOOOOO'.qQQQQq. `88888'	" << std::endl;
    fout << "    oOOOOOOOOOO'.QQQQQQQQQQ'OOOOOOOOOO'.QQQQQQQQQQ/.888880'" << std::endl;
    fout << "    OOOOOOOOOO'.QQQQQQQQQQ'OOOOOOOOO'.QQQQQQQQQQ/ /8888800'" << std::endl;
    fout << "     OOOOOOOOO QQQQQQQQQQ/'OOOOOOOOO QQQQQQQQQQ/ /QQ8QQQQ'	" << std::endl;
	fout << "       OOOOOOOOO `QQQQQQ/ /Q'OOOOOOOOO `QQQQQQ/ /QQQQQQQ'	" << std::endl;
    fout << "         OO:F_P:O `QQQ/  /Q''OO:F_P:O `QQQQQ/  /QQQQQQQQ'	" << std::endl;
    fout << "            \\\\. \\ |  // |			 '\\\\. \\ |  // |			" << std::endl;
    fout << "            d\\ \\\\\\|_////			 'd\\ \\\\\\|_////			" << std::endl;
    fout << "            qP| \\\\ _' `|Ob			 'qP| \\\\ _' `|Ob		" << std::endl;
    fout << "               \\  / \\  \\Op			    '\\  / \\  \\Op		" << std::endl;
    fout << "               |  | O| |			    '|  | O| |			" << std::endl;
    fout << "       _       /\\. \\_/ /'_' /			 \\. \\_/ /\\			" << std::endl;
    fout << "        `---__/|_\\\\   //|  ' `---__/|_\\\\   //|  __			" << std::endl;
    fout << "              `-'  `-'`-'-'		   '`-'  `-'`-'-'		" << std::endl;
}

// ------------- CONSTRUCTORS & DESTRUCTORS -------------

SCF::SCF(): AForm("Shrubbery Creation Form", 145, 137), _target("your old Peugeot 206") {}

SCF::SCF(std::string target): AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

SCF::SCF(const SCF& b): AForm("Shrubbery Creation Form", 145, 137), _target(b._target) {}

SCF::~SCF() {}

// -------------- OPERATOR OVERLOADS -------------

SCF& SCF::operator=(const SCF& r)
{
	this->_target = r._target;
	std::cout << "These forms dont really support assignment operators, please create them another way." << std::endl;
	return *this;
}
