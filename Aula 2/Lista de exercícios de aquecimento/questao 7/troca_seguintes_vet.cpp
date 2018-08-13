/**
 * @file troca_seguinte_vet.cpp
 * @brief Questão 7 da lista
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 **/
#include <iostream> /*< Biblioteca usada para cout, cin e andl */
#include <algorithm> /*< Biblioteca usada para swap(a,b) -> (b,a) */

#define  INTEIROS 20 /*< Quantidade de elementos a ser criados no vetor */

/**
 * @brief Função para receber o elementos do vetor
 * @param Aponta para a posição inicial do vetor a ser usado na função
 **/
void receber_elementos(int *inicial){
    for(int i(0); i<INTEIROS; ++i){
        std::cin >> *(inicial + i);
    }
}

/**
 * @brief Função para imprimir todos os elementos do vetor
 * @param Aponta para a posição inicial do vetor a ser usado na função
 **/
void imprimir_elementos(int *inicial){
    for(int i(0); i<INTEIROS; ++i){
        std::cout << *(inicial + i) << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Função para trocar as posições dos elementos do vetor
 * @param Aponta para a posição inicial do vetor a ser usado na função
 **/
void trocar_posicao(int *inicial){
    for(int i(0), j(INTEIROS-1); i<j; ++i, --j){
        std::iter_swap((inicial+i),(inicial+j));
    }
}

/**
 * @brief Função main
 * @param void void
 * @retunr 0
 **/
int main(void){
    int B[INTEIROS];
    std::cout << "Digite os " << INTEIROS << " elementos ao vetor: " << std::endl;
    receber_elementos(&B[0]);
    std::cout << "Lista de elementos adicionado: " << std::endl;
    imprimir_elementos(&B[0]);
    trocar_posicao(&B[0]);
    std::cout << "Lista de elementos com posição trocada: " << std::endl;
    imprimir_elementos(&B[0]);
    return 0;
}