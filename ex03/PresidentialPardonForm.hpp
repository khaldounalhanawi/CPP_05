/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:00:43 by kalhanaw          #+#    #+#             */
/*   Updated: 2026/04/24 17:00:44 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm (std::string target);
		PresidentialPardonForm (PresidentialPardonForm const &copy);
		~PresidentialPardonForm ();

		// Operator overrides
		PresidentialPardonForm &operator=(PresidentialPardonForm const &source);

		// Setters & Getters
		const std::string	&getTarget() const;

		// Member functions
		void	execute(Bureaucrat const &executor) const;
};

#endif