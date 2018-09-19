#include <sstream>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int getInteger(std::string msg_){
    std::cout << msg_ << std::endl;
    int valor;
    std::cin >> valor;
    std::istringstream iss;
    iss >> valor >> std::ws;
    while(iss.fail() or !iss.eof()){
        std::cout << "Valor incorreto" << std::endl;
    }
    return valor;
}

int main(void){
    auto val = getInteger("Forneça um inteiro: ");
    std::cout << val << std::endl;

    return EXIT_SUCCESS;
}