#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
	
	public:
		ShrubberyCreationForm (std::string target);
		ShrubberyCreationForm (ShrubberyCreationForm const &copy);
		~ShrubberyCreationForm ();

		// Operator overrides
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &source);

		// Setters & Getters
		const std::string	&getTarget() const;

		// Member functions
		void	execute(Bureaucrat const &executor) const;

};

#endif