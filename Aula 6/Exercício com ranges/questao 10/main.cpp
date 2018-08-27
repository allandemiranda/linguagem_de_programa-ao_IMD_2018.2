/**
 * @file main.cpp
 * @brief Questão 10 da lista exerccios_ranges.pdf
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 */
#include <iostream> // std::cout , std::cin 
#include <iterator> // std::begin() , std::end(), std::distance()

/**
 * @brief 
 * 
 * @param first Ponteiros que denem o intervalo de elementos para examinar
 * @param last Ponteiros que denem o intervalo de elementos para examinar
 * @param pivot aponta para o elemento-referência dentro do intervalo usado para rearranjar os elementos do vetor
 */
void partition(int *first, int *last, int *pivot){

}

int main(void){
    int A[] = {-5, 7, 10, 7, 8, 9, 1, 7, -2, 3}; // Vetor de teste

    partition(std::begin(A), std::end(A), 3);

    // Retornar [ -5; 3; -2; 1; 7; 7; 7; 9; 8; 10 ]
    for(auto i : A){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    return 0;
}