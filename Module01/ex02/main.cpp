#include <iostream>

int main(void)
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string& stringREF = brain;

    std::cout << "Address of string : " << &brain << std::endl;
    std::cout << "Address in string ptr : " << stringPTR << std::endl;
    std::cout << "Address in string ref : " << &stringREF << std::endl;
    std::cout << "String value : " << brain << std::endl;
    std::cout << "Pointer value : " << *stringPTR << std::endl;
    std::cout << "Reference value: " << stringREF << std::endl;

    return (0);
}