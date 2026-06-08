#include "Span.hpp"

int    main()
{
    std::srand(std::time(0)); // setting seed for random numbers

    std::cout << "Given tests:" << std::endl;
    try
    {
        Span    sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan  = " << sp.longestSpan() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Full span:" << std::endl;
    try
    {
        Span    sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Span too small: " << std::endl;
    try
    {
        Span    sp(5);
        sp.addNumber(42);
        std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "10001 value span added with addRange: " << std::endl;

	try
    {
        Span            sp(10001);
        std::vector<int>    big;

        for (int i = 0; i < 10001; i++)
            big.push_back(std::rand() % 100000);
        sp.addRange(big.begin(), big.end());
        std::cout << "size        = " << big.size() << std::endl;
        std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan  = " << sp.longestSpan() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "addRange but Span is too small:" << std::endl;
    try
    {
        Span            sp(5);
        std::vector<int>    toomany;

        for (int i = 0; i < 10; i++)
            toomany.push_back(i);
        sp.addRange(toomany.begin(), toomany.end());
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}