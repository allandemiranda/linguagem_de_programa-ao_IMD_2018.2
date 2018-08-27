/**
 * @file main.cpp
 * @brief Questão 2 da lista exerccios_ranges.pdf
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 */
#include <iostream> // std::cout , std::cin 
#include <iterator> // std::begin() , std::end(), std::distance()

/**
 * @brief retorna um ponteiro para a primeira ocorrência do menor elemento no intervalo
 * 
 * @param first Aponta para o primeiro elemento a analisar
 * @param last Aponta para o elemento seguinte ao últimmo a ser analisado
 * @return const int* retorna o ponteiro para o menor inteiro do intervalo analisado
 */
const int * min(const int *first, const int *last){
    const int *menor(first); //*< Ponteiro com a ponisão do menor elemento analisado */
    for(const int *i(first+1); i<last; ++i){ // Para analisar o intervalo dado
        if(*i<*menor){ // Se menor que o menor já determinado
            menor = i; // Modifique a posição para a nova posição
        }
    }
    return menor;
}

int main(void){
    int A[] = {1, 2, -3, -4, 5, -6};

    auto result = min(std::begin(A), std::end(A)); // resposta = (-6)
    std::cout << *result << std::endl;

    result = min(std::begin(A), std::begin(A)+5); // resposta = (-4)
    std::cout << *result << std::endl;

    return 0;
}