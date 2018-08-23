/**
 * @file main.cpp
 * @brief Questão 3 da lista
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 */
#include <iostream> // std::cout , std::cin 
#include <iterator> // std::begin() , std::end(), std::distance()
#include <algorithm> // std::swap

/**
 * @brief Função que inverte a ordem dos elementos no intervalo
 * 
 * @param first Aponta para o primeiro elemento a analisar
 * @param last Aponta para o elemento seguinte ao últimmo a ser analisado
 */
void reverse(int *first, int *last){
    for(int i(0), j(std::distance(first,last)-1); i<j; ++i, --j){ // enquanto 'i' cresce o 'j' desce o vetor em direções opostas
        std::swap(*(first+i),*(first+j));
    }
}

int main(void){
    int A[] = {1, 2, 3, 4, 5};

    // Aplicar reverse sobre todo o vetor
    reverse(std::begin(A), std::end(A));

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