/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:50:55 by kalhanaw          #+#    #+#             */
/*   Updated: 2026/04/24 16:51:11 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdexcept>

// ________________________ Constructors / destructor ________________________ //

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

Bureaucrat::~Bureaucrat()
{
	return ;
}

const int	&Bureaucrat::getGrade() const
{
	return (this->_grade);
}

const std::string	&Bureaucrat::getName() const
{
	return (this->_name);
}

// ________________________ Operator overloads ________________________ //

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& source)
{
	if (this != &source)
		this->_grade = source.getGrade ();
		
	std::cout	<< this->_name	<< " === " << source.getName ()
				<< std::endl;

	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat &member)
{
	return (os	<< member.getName () 
				<< ", bureaucrat grade "
				<< member.getGrade () 
				<<".");
}

// ________________________ Member functions ________________________ //

void	Bureaucrat::incrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooHighException ();
	this->_grade ++;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooLowException ();
	this->_grade --;
}

void	Bureaucrat::signForm(AForm &form)
{
	try { form.beSigned(*this); }
	catch (AForm::GradeTooLowException)
	{
		std::cout	<< this->_name		<<	" couldn’t sign "
					<< form.getName ()	<< " because grade too low."
					<< std::endl;
		return ;
	}
	std::cout	<< this->_name		<<	" signed "
				<< form.getName ()	<< "."
				<< std::endl;
	return ;
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	try { form.execute (*this); }
	catch (std::exception &e)
	{
		std::cout	<< this->_name		<<	" couldn’t execute "
					<< form.getName ()	<< " because "
					<< e.what ()
					<< std::endl;
		return ;
	}
	return ;
}

// ________________________ Exception functions ________________________ //

const char *Bureaucrat::GradeTooLowException::what() const throw ()
{
	return	"Grade too LOW:\n"
			"it has to be higher than 0 and smaller/equal to 150!";
}

const char *Bureaucrat::GradeTooHighException::what() const throw ()
{
	return	"Grade too HIGH:\n"
			"it has to be higher than 0 and smaller/equal to 150!";
}
