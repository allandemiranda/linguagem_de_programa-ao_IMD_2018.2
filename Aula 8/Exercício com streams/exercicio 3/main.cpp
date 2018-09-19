#include <iostream>
#include <iomanip>
#include <sstream>

int getInteger(std::string msg_){
    std::cout << msg_ << std::endl;
    std::string input;        
    std::getline (std::cin,input);
    std::istringstream stream(input);
    int number;        
    stream >> number >> std :: ws;        
    return number;   
}

int main(void){
    auto val = getInteger("Forneça um inteiro: ");
    std::cout << val << std::endl;

    return EXIT_SUCCESS;
}