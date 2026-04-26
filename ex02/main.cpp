/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:50:50 by kalhanaw          #+#    #+#             */
/*   Updated: 2026/04/26 13:27:56 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void	test0()
{
	Bureaucrat	employee1 ("Ana", 15);
	AForm		*form2;
	AForm		*form1 = NULL;

	form2 =  new ShrubberyCreationForm ("home");
	form1 = form2;

	std::cout<< "************" << std::endl;
	std::cout<< *form1 << std::endl;
	std::cout<< "************" << std::endl;

	employee1.signForm (*form1);
	employee1.executeForm (*form1);

	delete form1;
}

void	test1()
{
	Bureaucrat	employee1 ("Ana", 33);
	AForm		*form1 = new ShrubberyCreationForm ("Store");

	employee1.executeForm (*form1);
	delete form1;
}

void	test2()
{
	{
		Bureaucrat	employee1 ("Ana", 33);
		AForm		*form1 = new PresidentialPardonForm ("thief");

		employee1.signForm (*form1);
		employee1.executeForm (*form1);
		delete form1;
	}
	{
		Bureaucrat	employee1 ("Powerfull Ana", 1);
		AForm		*form1 = new PresidentialPardonForm ("thief");
		
		employee1.signForm (*form1);
		employee1.executeForm (*form1);
		delete form1;
	}
}

void	test3()
{
	Bureaucrat	employee ("Ana", 1);
	AForm		*form1 = new RobotomyRequestForm ("Store");

	employee.signForm (*form1);
	employee.executeForm (*form1);
	delete form1;
}

int	main(int argc, char **argv)
{
	int	index;
	void (*tests[])() = {test0, test1, test2, test3};

	if (argc != 2)
		return (1);

	index = *argv[1] - '0';
	tests[index]();

	return (0);
}

