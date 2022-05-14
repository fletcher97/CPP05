#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

void
tesBureaucrat()
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
}

void
testForm()
{
	// CONSTRUCTORS
	try
	{
		Form f("Contract", 0, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form f("Contract", 151, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form f("Contract", 42, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form f("Contract", 42, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form f1("Contract", 150, 42);
		Form f2("Contract", 1, 42);
		Form f4("Contract", 42, 150);
		Form f3("Contract", 42, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// SIGN
	Bureaucrat b("Smit", 42);

	{
		Form f = Form("Contract", 43, 1);
		b.signForm(f);
		std::cout << "Signed: " << (f.isSigned() ? "Yes" : "No") << std::endl;
	}{
		Form f = Form("Contract", 42, 1);
		b.signForm(f);
		std::cout << "Signed: " << (f.isSigned() ? "Yes" : "No") << std::endl;
	}{
		Form f = Form("Contract", 41, 1);
		b.signForm(f);
		std::cout << "Signed: " << (f.isSigned() ? "Yes" : "No") << std::endl;
	}

}

int main()
{
	//tesBureaucrat();
	testForm();
	return 0;
}
