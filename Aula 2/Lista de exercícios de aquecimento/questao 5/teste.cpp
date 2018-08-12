#include <iostream>
#include <vector>
#include <iterator>

void imprimir(int *inicial_p){
    for(int i(0); i<3; ++i){
        std::cout << *(inicial_p+i) << " ";
    }
}

int main(void){
    std::vector <int> elemento;
    elemento.push_back(1);
    elemento.push_back(2);
    elemento.push_back(3);

imprimir(&elemento.front());
    std::cout << std::endl;

}