#include <iostream>

#include "Bureaucrat.hpp"

int main()
{
	// PROMOTE
	try
	{
		Bureaucrat a("Smit", 10);
		while (42)
		{
			a.promote();
			std::cout << a << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// DEMOTE
	try
	{
		Bureaucrat a("Smit", 130);
		while (42)
		{
			a.demote();
			std::cout << a << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// CONSTRUCTOR
	try
	{
		Bureaucrat a("Smit", -10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat a("Smit", 1000);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
