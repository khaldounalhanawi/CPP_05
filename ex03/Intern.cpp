#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern()
{
	return ;
}

Intern::Intern(const Intern& other)
{
	(void) other;
	return ;
}

Intern& Intern::operator=(const Intern& source)
{
	(void) source;
	return *this;
}

Intern::~Intern()
{
	return ;
}

AForm	*Intern::makeForm(std::string formName, std::string targetName)
{
	int							index = -1;
	const static std::string	actionsKeys[3] = {	"shrubbery creation",
													"robotomy request",
													"presidential pardon"};

	for (int i = 0; i < 3; i ++)
	{
		if (formName == actionsKeys[i])
		{
			index = i;
			break;
		}
	}

	switch (index)
	{
		case (-1):
			std::cout	<< "Intern could not find specified form." << std::endl;
			return (NULL);
		case (0):
			std::cout	<< "Intern creates shrubbery creation form." << std::endl;
			return (new ShrubberyCreationForm (targetName));
		case (1):
			std::cout	<< "Intern creates robotomy request form." << std::endl;
			return (new RobotomyRequestForm (targetName));
		case (2):
			std::cout	<< "Intern creates presidential pardon form." << std::endl;
			return (new PresidentialPardonForm (targetName));
	}
	return (NULL);
}
