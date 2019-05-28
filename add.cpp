#include <iostream>
#include <string>

int main(){
    std::string str1;
    std::string str2;
    char op;
    std::cout << "Equation: ";
    std::cin >> str1 >> op >> str2;

 
    int x = std::stoi(str1);
    int y = std::stoi(str2);

    switch (op)
    {
    case '+':
        std::cout << x + y << std::endl;
        break;
    case '-':
        std::cout << x - y << std::endl;
        break;
    case '*':
        std::cout << x * y << std::endl;
        break;
    case '/':
        std::cout << x / y << std::endl;
        break;
    
    default:
        std::cout << "Bad operator " + op << std::endl;
        break;
    }

    return 0;        
}