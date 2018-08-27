/**
 * @file main.cpp
 * @brief Questão 10 da lista exerccios_ranges.pdf
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 */
#include <iostream> // std::cout , std::cin 
#include <iterator> // std::begin() , std::end(), std::distance()
#include <algorithm> // std::swap

/**
 * @brief que realiza uma rotação à esquerda nos elementos do intervalo [ first , last ), preservando a ordem relativas dos elementos
 * 
 * @param first Ponteiro para o início do intervalo original 
 * @param n_first Ponteiro para o elemento que deve aparecer no início do intervalo rotacionado
 * @param last Ponteiros para o nal do intervalo original
 */
void rotate(int *first, int *n_first, int *last){
    for(auto *i(n_first), *j(first); j<last; ++i, ++j){
        if(i<last){ // Rotacione até o elemento desejado
            std::swap(*i, *j);
        } else {
            for(auto *k(j+1); k<last; ++k){ // Ordene os demais elementos não rotacionados
                if(*j>*k){
                    std::swap(*j, *k);
                }                
            }
        }        
    }
}

int main(void){
    int A[] = {1, 2, 3, 4, 5, 6, 7};

    // aplicar rotate , de maneira que 3 passe a ser o novo " primeiro " elemento em A.
    rotate(std::begin(A), std::begin(A)+2, std::end(A));

    // O comando abaixo deveria imprimir A com o conteúdo 3, 4, 5, 6, 7, 1, 2
    for(auto i(std::begin(A)); i != std::end(A); ++i){
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    return 0;
}