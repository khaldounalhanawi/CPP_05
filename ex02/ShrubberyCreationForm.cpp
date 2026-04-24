#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

void	create_tree_file (const std::string &target);

// ________________________ Constructors / destructor ________________________ //

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm ("ShrubberyCreationForm", 145, 137),
_target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
AForm ("ShrubberyCreationForm", 145, 137),
_target(other.getTarget ())
{
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

// ________________________ Operator overloads ________________________ //

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& source)
{
	if (this != &source)
		this->_target = source.getTarget ();
	return *this;
}

// ________________________ Setter & Getters ________________________ //

const std::string	&ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

// ________________________ Member functions ________________________ //

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	// 	** You must check that the form is signed
	if (!this->getSignatureStatus())
		throw (AForm::FormNotSignedException ());

	// ** and that the grade of the bureaucrat attempting to execute the form is high enough.
	if (executor.getGrade() > this->getExecutionGrade ())
		throw (AForm::NoClearanceException ());
	
	// Creates a file <target>_shrubbery in the working directory and writes ASCII trees inside it.
	create_tree_file (this->_target);

	std::cout	<< executor.getName()	<< " has successfully executed form "
				<< this->_target		<< std::endl;
}

// ________________________ Helper functions ________________________ //

#include <iostream>
#include <fstream>

void	create_tree_file (const std::string &target)
{
	std::ofstream file(target + "_shrubbery");

	if (file.is_open())
	{
		file <<
		"        /\\                /\\               /\\\n"
		"       /**\\              /**\\             /**\\\n"
		"      /****\\            /****\\           /****\\\n"
		"     /******\\          /******\\         /******\\\n"
		"    /********\\        /********\\       /********\\\n"
		"       ||                ||               ||\n"
		"\n"
		"               /\\\n"
		"              /**\\\n"
		"             /****\\\n"
		"            /******\\\n"
		"           /********\\\n"
		"              ||\n"
		"\n"
		"   _\\|/_\n"
		"   (> <)\n"
		"   /   \\\n";
	}
	else
		throw (std::runtime_error ("Couldn't create file.\n"));

	file.close ();
}


