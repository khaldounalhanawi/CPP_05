/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 11:05:42 by kalhanaw          #+#    #+#             */
/*   Updated: 2026/04/24 11:05:44 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const int			_signatureGrade;
		const int			_executionGrade;
		bool				_signatureStatus;

	public:
		AForm (std::string name, int signatureGrade, int executionGrade);
		AForm (AForm const &copy);
		virtual ~AForm ();

		// Operator overrides
		AForm &operator=(AForm const &source);

		// Setters & Getters
		const std::string	&getName() const;
		const int			&getSignatureGrade() const;
		const int			&getExecutionGrade() const;
		bool				getSignatureStatus() const;

		// Member functions
		void			beSigned(Bureaucrat &agent);
		virtual void	execute(Bureaucrat const & executor) const = 0;

		// Exception classes
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class	FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw ();
		};
		class	NoClearanceException : public std::exception
		{
			public:
				virtual const char *what() const throw ();
		};
};

std::ostream	&operator<<(std::ostream &os, AForm &object);

#endif



/*
In all cases, the base class Form must be an abstract class and should therefore be
renamed AForm.

Keep in mind that the form’s attributes need to remain private and that they belong to the base class.

Add the following concrete classes:
• ShrubberyCreationForm:	Required grades: sign 145, exec 137
							Creates a file <target>_shrubbery in the working directory and writes ASCII trees
							inside it.
• RobotomyRequestForm:		Required grades: sign 72, exec 45
							Makes some drilling noises, then informs that <target> has been robotomized
							successfully 50% of the time. Otherwise, it informs that the robotomy failed.
• PresidentialPardonForm:	Required grades: sign 25, exec 5
							Informs that <target> has been pardoned by Zaphod Beeblebrox.

All of them take only one parameter in their constructor:
	the target of the form. For example, "home" if you want to plant shrubbery at home.

Now, add the 	___execute(Bureaucrat const & executor) const___	member function to
the 			___base form____ 									and implement a function to execute the form’s action in the concrete classes.

	** You must check that the form is signed
	** and that the grade of the bureaucrat attempting to execute the form is high enough.
	** Otherwise, throw an appropriate exception.

Whether you check the requirements in every concrete class or in the base class (and
then call another function to execute the form) is up to you. However, one way is more
elegant than the other.

Lastly, add the 	___executeForm(AForm const & form) const___	member function to the
					___Bureaucrat class___.

** It must attempt to execute the form.
** If successful, print something like:
	<bureaucrat> executed <form>
** If not, print an explicit error message.

*/