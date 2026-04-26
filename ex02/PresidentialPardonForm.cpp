/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:25:02 by kalhanaw          #+#    #+#             */
/*   Updated: 2026/04/24 16:25:03 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// ________________________ Constructors / destructor ________________________ //

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm ("PresidentialPardonForm", 25, 5),
_target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
AForm ("PresidentialPardonForm", 25, 5),
_target(other.getTarget ())
{
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

// ________________________ Operator overloads ________________________ //

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& source)
{
	if (this != &source)
		this->_target = source.getTarget ();
	return *this;
}

// ________________________ Setter & Getters ________________________ //

const std::string	&PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

// ________________________ Member functions ________________________ //

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	// 	** You must check that the form is signed
	if (!this->getSignatureStatus())
		throw (AForm::FormNotSignedException ());

	// ** and that the grade of the bureaucrat attempting to execute the form is high enough.
	if (executor.getGrade() > this->getExecutionGrade ())
		throw (AForm::NoClearanceException ());

	std::cout	<< this->_target	<< " has has been pardoned by Zaphod Beeblebrox"
				<< std::endl;

	std::cout	<< executor.getName()	<< " has successfully executed form "
				<< this->getName()		<< std::endl;
}
