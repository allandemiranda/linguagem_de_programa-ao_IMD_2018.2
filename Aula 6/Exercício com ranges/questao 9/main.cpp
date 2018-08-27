/**
 * @file main.cpp
 * @brief Questão 9 da lista exerccios_ranges.pdf
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 */
#include <iostream> // std::cout , std::cin 
#include <iterator> // std::begin() , std::end(), std::distance()
#include <cassert> // assert()

enum ball_t {B=0, W=1}; // Black and White.

/**
 * @brief Função que ordene os elementos
 * 
 * @param first Ponteiros que denem o intervalo de elementos para ordenar
 * @param last Ponteiros que denem o intervalo de elementos para ordenar
 * @return ball_t* retorna um ponteiro para o início da região das bolas BRANCAS
 */
ball_t * sort_marbles(ball_t *first, ball_t *last){
    for(auto *i = first; i<last; ++i){ /*< Ordenar o vetor */
        for(auto *j = i + 1; j<last; ++j){
            if(*i>*j){
                std::swap(*i, *j);
            }            
        }
    }
    for(auto *i = first; i<last; ++i){ /*< Verificar posição da mudança de cor */ 
        if(*i != *(i+1)){
            i++;
            return i;
        }
    }
}

int main(void){
    ball_t A[] = {W, B, B, W, W, B, W}; // input
    auto size_A = sizeof(A) / sizeof(ball_t);
    ball_t A_sorted[] = {B, B, B, W, W, W, W}; // expected output
    auto result = sort_marbles(std::begin(A), std::end(A));

    // White marbles shoud start at position 3 whithin the array
    assert(std::distance(std::begin(A), result) == 3);
    // Validate answer
    for(auto i(0u); i < size_A; ++i){
        assert(A[i] == A_sorted[i]);
    }

    return 0;
}