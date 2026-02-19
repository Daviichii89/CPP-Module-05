#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    std::cout << "===== ShrubberyCreationForm =====" << std::endl;
    try {
        Bureaucrat b("Bob", 100);
        ShrubberyCreationForm f("home");
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
        b.executeForm(f);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== RobotomyRequestForm =====" << std::endl;
    try {
        Bureaucrat b("Alice", 40);
        RobotomyRequestForm f("Bender");
        b.signForm(f);
        b.executeForm(f);
        b.executeForm(f);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== PresidentialPardonForm =====" << std::endl;
    try {
        Bureaucrat b("President", 1);
        PresidentialPardonForm f("Arthur");
        b.signForm(f);
        b.executeForm(f);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== Execute without signing =====" << std::endl;
    try {
        Bureaucrat b("Low", 1);
        ShrubberyCreationForm f("garden");
        b.executeForm(f);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== Execute with grade too low =====" << std::endl;
    try {
        Bureaucrat b("Low", 10);
        PresidentialPardonForm f("Someone");
        b.signForm(f);
        b.executeForm(f);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
