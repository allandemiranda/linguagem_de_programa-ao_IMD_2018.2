/**
 * @file main.cpp
 * @brief Questão 10 da lista exerccios_ranges.pdf
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 */
#include <iostream> // std::cout , std::cin 
#include <iterator> // std::begin() , std::end(), std::distance()
#include <algorithm> // std::swap

/**
 * @brief Função que rearranja (movimenta) os elementos do intervalo com base em no valor apontado por pivot. 
 * 
 * @param first Ponteiros que denem o intervalo de elementos para examinar
 * @param last Ponteiros que denem o intervalo de elementos para examinar
 * @param pivot aponta para o elemento-referência dentro do intervalo usado para rearranjar os elementos do vetor
 */
void partition(int *first, int *last, int *pivot){
    auto numero_p = *pivot; /*< Coletar número do pivot */
    for(auto *i(first); i<last; ++i){ /*< buscar valores */
        if(*i<numero_p){ /*< comparar com o pivot */
            continue;
        } else {
            for(auto *j(last-1); j>i; --j){
                if(*j<numero_p){
                    std::swap(*i, *j);
                    break;
                }
            }
        }
    }
}

int main(void){
    int A[] = {-5, 7, 10, 7, 8, 9, 1, 7, -2, 3}; // Vetor de teste

    partition(std::begin(A), std::end(A), std::begin(A)+3);

    // Retornar (0)(1)(2)(3)<->(4)(5)(6)(7)(8)(9)
    for(auto i : A){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}