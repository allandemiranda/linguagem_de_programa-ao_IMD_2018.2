/**
 * @file main.cpp
 * @brief Questão 8 da lista
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 */
#include <iostream> // std::cout , std::cin 
#include <iterator> // std::begin() , std::end(), std::distance()

/**
 * @brief Frunção que elimina repetições de elementos no intervalo preservando a ordem relativas dos elementos úunicos que sobrarem
 * 
 * @param first Ponteiro inicial do vetor que denem o intervalo de elementos para examinar
 * @param last Ponteiro sequinte ao final do vetor que denem o intervalo de elementos para examinar
 * @return int* retorna um ponteiro após-o-final do intervalo resultante
 */
int * unique(int *first, int *last){

}

int main(void){
    int A[] = {1, 2, 1, 2, 3, 3, 1, 2, 4, 5, 3, 4, 5};

    // aplique unique sobre A
    auto last = unique(std::begin(A), std::end(A));

    // O comando abaixo deverá imprimir A com o conteúdo 1, 2, 3, 4, 5.
    for(auto i(std::begin(A)); i != last; ++i){
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    // Mostre o novo tamanho de A, que seria 5.
    std::cout << ">>> O comprimento ( lógico ) de A apos unique () é:   " << std::distance(std::begin(A), last) << " \n";

    return 0;
}