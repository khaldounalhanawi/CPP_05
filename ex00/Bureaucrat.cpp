#include "Bureaucrat.hpp"
#include <stdexcept>

const char *Bureaucrat::GradeTooLowException::what() const throw ()
{
	return	"Grade entered too LOW:\n"
			"it has to be higher than 0 and smaller/equal to 150!";
}

const char *Bureaucrat::GradeTooHighException::what() const throw ()
{
	return	"Grade entered too HIGH:\n"
			"it has to be higher than 0 and smaller/equal to 150!";
}

Bureaucrat::Bureaucrat(std::string name, int grade):
_name(name),
_grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException ();
	else if (grade > 150)
		throw Bureaucrat::GradeTooHighException ();

	std::cout	<< _name	<< " has been created"
				<< std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):
_name(other.getName() + "_copy")
{
	std::cout	<< this->_name	<< " has been created Via Copy"
				<< std::endl;

	this->_grade = other.getGrade ();
	return ;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& source)
{
	if (this != &source)
		this->_grade = source.getGrade ();
		
	std::cout	<< this->_name	<< " === " << source.getName ()
				<< std::endl;

	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const int	&Bureaucrat::getGrade() const
{
	return (this->_grade);
}

const std::string	&Bureaucrat::getName() const
{
	return (this->_name);
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat &member)
{
	return (os	<< member.getName () 
				<< ", bureaucrat grade "
				<< member.getGrade () 
				<<".");
}