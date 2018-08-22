/**
 * @file main.cpp
 * @brief Questão 3 da lista
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 */
#include <iostream> // std::cout , std::cin 
#include <iterator> // std::begin() , std::end();

int main(void){
    int A[] = {1, 2, 3, 4, 5};

    // Aplicar reverse sobre todo o vetor
    reverse(std::begin(A), std::endl(A));

    // O comando a baixo deverá imprimir o vetor A com o conteúdo 5, 4, 3, 2, 1
    for(auto i(std::begin(A)); i != std::end(A); ++i){
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    // Aplicar reverse sobre parte do vetor
    reverse(std::begin(A)+1, std::begin(A)+4);

    // O comando a baixo deverá imprimir o vetor A com o conteúdo 5, 2, 3, 4, 1
    for(auto i(std::begin(A)); i != std::end(A); ++i){
        std::cout << *i << " ";
    }
    std::cout << std::endl;    

    return 0;
}