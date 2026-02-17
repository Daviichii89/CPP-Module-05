#include "Bureaucrat.hpp"

void testValidBureaucrats() {
	std::cout << "\n--- TEST 1: Create valid bureaucrats ---" << std::endl;
	try {
		Bureaucrat b1("Alice", 1);
		Bureaucrat b2("Bob", 150);
		Bureaucrat b3("Charlie", 75);
		
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
	} catch (std::exception& e) {
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}
}

void testInvalidBureaucrats() {
	std::cout << "\n--- TEST 2: Create invalid bureaucrats ---" << std::endl;
	
	try {
		Bureaucrat b_bad1("TooHigh", 0);
		std::cout << "Test failed: expected exception for invalid grade 0" << std::endl;
	} catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "Exception caught correctly: " << e.what() << std::endl;
	}
	
	try {
		Bureaucrat b_bad2("TooLow", 151);
		std::cout << "Test failed: expected exception for invalid grade 151" << std::endl;
	} catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "Exception caught correctly: " << e.what() << std::endl;
	}
}

void testIncrementGrade() {
	std::cout << "\n--- TEST 3: Test incrementGrade ---" << std::endl;
	try {
		Bureaucrat b("David", 3);
		std::cout << "Before: " << b << std::endl;
		
		b.incrementGrade();
		std::cout << "After incrementing: " << b << std::endl;
		
		b.incrementGrade();
		std::cout << "After incrementing again: " << b << std::endl;
		
		std::cout << "Incrementing again one last time" << std::endl;
		b.incrementGrade();
		std::cout << "Test failed: expected exception when incrementing from grade 1" << std::endl;
	} catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "Exception caught correctly: " << e.what() << std::endl;
	}
}
	
void testDecrementGrade() {
	std::cout << "\n--- TEST 4: Test decrementGrade ---" << std::endl;
	try {
		Bureaucrat b("Eva", 148);
		std::cout << "Before: " << b << std::endl;
		
		b.decrementGrade();
		std::cout << "After decrementing: " << b << std::endl;
		
		b.decrementGrade();
		std::cout << "After decrementing again: " << b << std::endl;
		
		std::cout << "Decrementing again one last time" << std::endl;
		b.decrementGrade();
		std::cout << "Test failed: expected exception when decrementing from grade 150" << std::endl;
	} catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "Exception caught correctly: " << e.what() << std::endl;
	}
}
	
void testCopyAndAssignment() {
	std::cout << "\n--- TEST 5: Test copy constructor and assignment operator ---" << std::endl;
	try {
		Bureaucrat original("Original", 50);
		std::cout << "Original: " << original << std::endl;
		
		Bureaucrat copy(original);
		std::cout << "Copy: " << copy << std::endl;

		Bureaucrat assigned("Temp", 100);
		assigned = original;
		std::cout << "Assigned: " << assigned << std::endl;

		original.incrementGrade();
		std::cout << "\nAfter modifying original:" << std::endl;
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy (unchanged): " << copy << std::endl;
		std::cout << "Assigned (unchanged): " << assigned << std::endl;

	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

int main()
{
	std::cout << "===== TESTING BUREAUCRAT CLASS =====" << std::endl;

	testValidBureaucrats();
	testInvalidBureaucrats();
	testIncrementGrade();
	testDecrementGrade();
	testCopyAndAssignment();

	std::cout << "\n===== END OF TESTS =====" << std::endl;

	return 0;
}