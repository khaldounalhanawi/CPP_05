/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm copy.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:25:02 by kalhanaw          #+#    #+#             */
/*   Updated: 2026/04/26 12:40:04 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

void	make_noise (void);
void	robotomize (std::string	target);

// ________________________ Constructors / destructor ________________________ //

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
AForm ("RobotomyRequestForm", 72, 45),
_target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
AForm ("RobotomyRequestForm", 145, 137),
_target(other.getTarget ())
{
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

// ________________________ Operator overloads ________________________ //

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& source)
{
	if (this != &source)
		this->_target = source.getTarget ();
	return *this;
}

// ________________________ Setter & Getters ________________________ //

const std::string	&RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

// ________________________ Member functions ________________________ //

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	// 	** You must check that the form is signed
	if (!this->getSignatureStatus())
		throw (AForm::FormNotSignedException ());

	// ** and that the grade of the bureaucrat attempting to execute the form is high enough.
	if (executor.getGrade() > this->getExecutionGrade ())
		throw (AForm::NoClearanceException ());

	// make noise and robotomize
	make_noise ();
	robotomize (this->_target);

	std::cout	<< executor.getName()	<< " has successfully executed form "
				<< this->getName()		<< std::endl;
}

// ________________________ Helper functions ________________________ //
# include <ctime>

void	make_noise(void)
{
	std::cout	<< "><><>< Bbbbzzzz zZaap BBbbbzz ><><><"
				<< std::endl;
}

void	robotomize(std::string	target)
{
	bool				dice;
	static std::string	msg[2] = {	(target + " has failed to robotomize"),
									(target + " has been successfully robotomized!")};

	std::srand (std::time (0));
	dice = std::rand () % 2;

	std::cout	<< msg[dice]
				<< std::endl;
	return ;
}
