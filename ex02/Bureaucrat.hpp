/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:50:45 by kalhanaw          #+#    #+#             */
/*   Updated: 2026/04/24 14:35:21 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat (std::string name, int grade);
		Bureaucrat (Bureaucrat const &copy);
		~Bureaucrat ();

		// Operator overrides
		Bureaucrat &operator=(Bureaucrat const &source);

		// Setters & Getters
		const int			&getGrade() const;
		const std::string	&getName() const;

		// Member functions
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(AForm &form);

		// Exceptions
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw ();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw ();
		};
};

std::ostream	&operator<<(std::ostream &os, Bureaucrat &member);

#endif
