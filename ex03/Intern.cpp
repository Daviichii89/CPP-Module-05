#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

namespace {

typedef AForm* (*FormCreator)(const std::string&);

static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

struct FormEntry {
    const char* name;
    FormCreator create;
};

static const FormEntry formTable[] = {
    {"shrubbery creation", createShrubbery},
    {"robotomy request", createRobotomy},
    {"presidential pardon", createPresidential}
};

static const size_t formTableSize = sizeof(formTable) / sizeof(formTable[0]);

}

Intern::Intern() {}

Intern::Intern(const Intern&) {}

Intern& Intern::operator=(const Intern&) {
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    for (size_t i = 0; i < formTableSize; ++i) {
        if (formName == formTable[i].name) {
            AForm* f = formTable[i].create(target);
            std::cout << "Intern creates " << f->getName() << std::endl;
            return f;
        }
    }
    std::cout << "Intern: unknown form name \"" << formName << "\"" << std::endl;
    return 0;
}
