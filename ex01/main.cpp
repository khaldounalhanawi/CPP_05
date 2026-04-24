/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:50:50 by kalhanaw          #+#    #+#             */
/*   Updated: 2026/04/24 11:04:18 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	a ("Adam", 5);
	Bureaucrat	b ("Eve", 4);
	Form		f1 ("onboarding", 150, 10);
	Form		f2 ("Secret Strategy", 5, 1);
	Form		f3 (f1);

	f3 = f2;
	std::cout	<< "\n--------\n"
				<< f1
				<< "\n--------\n"
				<< f2
				<< "\n--------\n"
				<< f3
				<< "\n--------"
				<< std::endl;


	a.signForm (f1);
	a.signForm (f2);
	b.signForm (f1);
	b.signForm (f2);

	b.incrementGrade ();
	b.incrementGrade ();
	b.signForm (f2);

	std::cout << "\n************** decrement test *****\n"<< std::endl;

	std::cout << "\n>>>>>>>";
	std::cout << b << std::endl;
	std::cout << "\n";

	for (int i = 0; i < 7; i ++)
	{
		try {b.decrementGrade ();}
		catch (std::exception &e)
		{
			std::cout << "@decrement attempt "<< i << " :\n"<< e.what() << std::endl;
		}
	}

	std::cout << "\n>>>>>>>";
	std::cout << b << std::endl;
	std::cout << "\n";

	for (int i = 0; i < 153; i ++)
	{
		try {b.incrementGrade ();}
		catch (std::exception &e)
		{
			std::cout << "@increment attempt "<< i << " :\n"<< e.what() << std::endl;
		}
	}
	std::cout << "\n>>>>>>>";
	std::cout << b << std::endl;

	return (0);
}

