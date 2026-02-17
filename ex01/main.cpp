#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "===== TEST 1: Sign form with sufficient grade =====" << std::endl;
    try {
        Bureaucrat bob("Bob", 50);
        Form form("28B", 75, 50);
        std::cout << bob << std::endl;
        std::cout << form << std::endl;
        bob.signForm(form);
        std::cout << form << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 2: Sign form with insufficient grade =====" << std::endl;
    try {
        Bureaucrat low("LowGrade", 100);
        Form form("28C", 50, 25);
        std::cout << low << std::endl;
        std::cout << form << std::endl;
        low.signForm(form);
        std::cout << form << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 3: Invalid form grades =====" << std::endl;
    try {
        Form bad("Bad", 0, 50);
    } catch (Form::GradeTooHighException& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    try {
        Form bad2("Bad2", 50, 151);
    } catch (Form::GradeTooLowException& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    return 0;
}
