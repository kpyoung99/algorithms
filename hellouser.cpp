#include <iostream>
#include <string>

int main(){
    //Get name
    std::string firstName, lastName;
    std::cout << "Name? ";
    std::cin >> firstName >> lastName;

    //Greeting
    const std::string greeting = "* Hello, " + firstName + " " + lastName + "! *";
    const std::string stars(greeting.size(), '*');

    //Print
    std:: cout << stars << std::endl;
    std:: cout << greeting << std::endl;
    std:: cout << stars << std:: endl;

    return 0;
}