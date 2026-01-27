#include "RPN.h"

int compute(char* rpn)
{
	int a;
	int b;
	stack<int> st;
	
	while (*rpn)
	{
		if (std::isdigit(*rpn))
			st.push(toInt(*rpn));

		else if (isop(*rpn))
		{
			if (st.size() < 2)
				throw std::invalid_argument("Error: Expected a digit!");
			
			b = st.top();
			st.pop();
			a = st.top();
			st.pop();

			st.push(nextVal(a, b, *rpn));
		}

		else
			throw std::invalid_argument("Error: Invalid input!");

		rpn++;
		skipSpace(&rpn);
	}

	if (st.size() > 1)
		throw std::invalid_argument("Error: Expected an operator!");
	return st.top();
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		cout << "This program needs a RPN expression as an argument to run." << endl;
		return 1;
	}

	try
	{
		cout << compute(av[1]) << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}

	return (0);
}
