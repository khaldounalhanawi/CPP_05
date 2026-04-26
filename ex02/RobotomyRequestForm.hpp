/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:25:22 by kalhanaw          #+#    #+#             */
/*   Updated: 2026/04/24 17:00:12 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm (std::string target);
		RobotomyRequestForm (RobotomyRequestForm const &copy);
		~RobotomyRequestForm ();

		// Operator overrides
		RobotomyRequestForm &operator=(RobotomyRequestForm const &source);

		// Setters & Getters
		const std::string	&getTarget() const;

		// Member functions
		void	execute(Bureaucrat const &executor) const;
};

#endif