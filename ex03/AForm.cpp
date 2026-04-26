/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:00:40 by kalhanaw          #+#    #+#             */
/*   Updated: 2026/04/24 10:47:58 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
# include "Bureaucrat.hpp"

// ________________________ Constructors / destructor ________________________ //

AForm::AForm(std::string name, int signatureGrade, int executionGrade):
_name(name),
_signatureGrade(signatureGrade),
_executionGrade(executionGrade),
_signatureStatus (false)
{
	if (signatureGrade < 1 || executionGrade < 1)
		throw AForm::GradeTooLowException ();
	else if (signatureGrade > 150 || executionGrade > 150)
		throw AForm::GradeTooHighException ();
	
	std::cout	<< this->_name	<< " has been created!"
				<< std::endl;
	return ;
}

AForm::AForm(const AForm& other):
_name (other.getName() + "_copy"),
_signatureGrade(other.getSignatureGrade ()),
_executionGrade(other.getExecutionGrade ())
{
	this->_signatureStatus = other.getSignatureStatus ();
	return ;
}

AForm::~AForm()
{
	return;
}

// ________________________ Operator overloads ________________________ //


AForm	&AForm::operator=(const AForm& source)
{
	if (this != &source)
		this->_signatureStatus = source.getSignatureStatus ();
	return *this;
}

std::ostream	&operator<<(std::ostream &os, AForm &Aform)
{
	return (os	<< "Name: "				<< Aform.getName ()
				<< "\nSignature status: "	<< Aform.getSignatureStatus ()
				<< "\nSignature grade: "	<< Aform.getSignatureGrade ()
				<< "\nExecution grade: "	<< Aform.getExecutionGrade ());
}

// ________________________ Setter & Getters ________________________ //

const std::string	&AForm::getName() const
{
	return (this->_name);
}

const int			&AForm::getSignatureGrade() const
{
	return (this->_signatureGrade);
}

const int			&AForm::getExecutionGrade() const
{
	return (this->_executionGrade);
}

bool				AForm::getSignatureStatus() const
{
	return (this->_signatureStatus);
}

// ________________________ Member functions ________________________ //

void	AForm::beSigned(Bureaucrat &agent)
{
	if (agent.getGrade () > this->_signatureGrade)
		throw AForm::GradeTooLowException ();

	this->_signatureStatus = true;
	return ;
}

// ________________________ Exception functions ________________________ //

const char *AForm::GradeTooLowException::what() const throw ()
{
	return	"Grade too LOW:"
			"it has to be higher than 0 and smaller/equal to 150!";
}

const char *AForm::GradeTooHighException::what() const throw ()
{
	return	"Grade too HIGH:\n"
			"it has to be higher than 0 and smaller/equal to 150!";
}

const char *AForm::FormNotSignedException::what() const throw ()
{
	return	"Form not signed!";
}

const char *AForm::NoClearanceException::what() const throw ()
{
	return	"Permission denied! Has no clearance.";
}
