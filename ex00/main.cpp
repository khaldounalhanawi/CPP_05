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
	Bureaucrat a("Adam", 12);
	Bureaucrat b("Eve", 4);
	Bureaucrat c(b);
	Bureaucrat d(c);
	
	b = a;
	std::cout	<< a << "\n";
	std::cout	<< b << "\n";
	
	return (0);
}