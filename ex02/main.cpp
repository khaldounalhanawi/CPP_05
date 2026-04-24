/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:50:50 by kalhanaw          #+#    #+#             */
/*   Updated: 2026/04/24 16:33:03 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
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
	form1->execute (employee1);

	delete form1;
	return (0);
}

