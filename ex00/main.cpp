#include "Bureaucrat.hpp"

// error throw tests
// int	main()
// {
// 	try 
// 	{
// 		Bureaucrat a("Samir", -3);
// 		Bureaucrat b("Rosa", 177);
// 		Bureaucrat c("karim", 12);
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// 	return (0);
// }

int	main()
{
	Bureaucrat a("Adam", 149);
	Bureaucrat b("Eve", 4);
	Bureaucrat c(b);
	Bureaucrat d(c);
	
	b = a;
	std::cout	<< a << "\n";
	std::cout	<< b << "\n";

	a.incrementGrade ();
	std::cout	<< a << "\n";

	try	{	a.incrementGrade ();	}
	catch (const std::exception &e)
	{
		std::cout	<< e.what() << std::endl;
		std::cout	<< "incrementation denied!" << std::endl;
	}

	std::cout	<< a << "\n";

	try {Bureaucrat cc("hola", -2);}
	catch (const std::exception &e)
	{
		std::cout	<< "creation denied!" << std::endl;
		std::cout	<< e.what() << std::endl;
	}

	return (0);
}