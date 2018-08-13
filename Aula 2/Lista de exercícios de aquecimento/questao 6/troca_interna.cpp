/**
 * @file troca_interna.cpp
 * @brief Questão 6 da lista
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 **/
#include <iostream> /*< Biblioteca usada para cout, cin e andl */
#include <vector> /*< Biblioteca usada para vetores dinâmicos */
#include <algorithm> /*< Biblioteca usada para swap(a,b) -> (b,a) */

#define  INTEIROS 20 /*< Quantidade de elementos a ser criados no vetor */

void receber_elementos(int *inicial){
    for(int i(0); i<INTEIROS; ++i){
        std::cin >> *(ininial + i);
    }
}

void imprimir_elementos(int *inicial){
    for(int i(0); i<INTEIROS; ++i){
        std::cout << *(inicial + i);
    }
    std::cout << std::endl;
}

void trocar_posicao(int *inicial){
    for(int i(0), j(INTEIROS-1); i!=j; ++i, --j){
        std::swap(*(inicial+i),*(inicial+j));
    }
}
/**
 * @brief Função main
 * @param void void
 * @retunr 0
 **/
int main(void){
    int A[INTEIROS];
    receber_elementos(&A[0]);
    imprimir_elementos(&A[0]);
    trocar_posicao(&A[0]);
    imprimir_elementos(&A[0]);
    return 0;
}