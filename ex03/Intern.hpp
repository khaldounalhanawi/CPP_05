#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
	public:
		Intern ();
		Intern (Intern const &copy);
		~Intern ();

		// Operator overrides
		Intern &operator=(Intern const &source);

		// Member functions
			AForm	*makeForm(std::string formName, std::string targetName);
};

#endif
