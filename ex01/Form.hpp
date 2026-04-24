/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 11:05:42 by kalhanaw          #+#    #+#             */
/*   Updated: 2026/04/24 11:05:44 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_signatureGrade;
		const int			_executionGrade;
		bool				_signatureStatus;

	public:
		Form (std::string name, int signatureGrade, int executionGrade);
		Form (Form const &copy);
		~Form ();

		// Operator overrides
		Form &operator=(Form const &source);

		// Setters & Getters
		const std::string	&getName() const;
		const int			&getSignatureGrade() const;
		const int			&getExecutionGrade() const;
		bool				getSignatureStatus() const;

		// Member functions
		void	beSigned(Bureaucrat &agent);

		// Exception classes
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, Form &object);

#endif
