#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    std::cout << "===== Intern creates forms =====" << std::endl;
    Intern someRandomIntern;
    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        Bureaucrat b("Alice", 40);
        b.signForm(*rrf);
        b.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "\n===== Intern creates shrubbery form =====" << std::endl;
    AForm* scf = someRandomIntern.makeForm("shrubbery creation", "garden");
    if (scf) {
        Bureaucrat b("Bob", 100);
        b.signForm(*scf);
        b.executeForm(*scf);
        delete scf;
    }

    std::cout << "\n===== Intern creates presidential pardon =====" << std::endl;
    AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur");
    if (ppf) {
        Bureaucrat b("President", 1);
        b.signForm(*ppf);
        b.executeForm(*ppf);
        delete ppf;
    }

    std::cout << "\n===== Unknown form name =====" << std::endl;
    AForm* unknown = someRandomIntern.makeForm("coffee request", "Kitchen");
    if (unknown)
        delete unknown;

    return 0;
}
