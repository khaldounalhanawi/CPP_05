/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:50:50 by kalhanaw          #+#    #+#             */
/*   Updated: 2026/04/24 16:54:02 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	test1()
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

void	test2()
{
	Bureaucrat	employee1 ("Ana", 33);
	AForm		*form1 = new ShrubberyCreationForm ("Store");

	employee1.signForm (*form1);
	employee1.executeForm (*form1);
}

int	main()
{
	// test1 ();
	test2 ();


	return (0);
}

