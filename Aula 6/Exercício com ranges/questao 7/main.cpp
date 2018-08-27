/**
 * @file main.cpp
 * @brief Questão 7 da lista
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 */
#include <iostream> // std::cout , std::cin 
#include <iterator> // std::begin() , std::end(), std::distance()

/**
 * @brief Função que copia os elementos no intervalo para outro intervalo iniciando
 * 
 * @param first Ponteiro que aponta para primeira posição do vetor a ser copiado
 * @param last Ponteiro que aponta para a posição seguinte do vetor a ser copiado
 * @param d_first Ponteiro que aponta para primeira posição do vetor que receberá a cópia
 * @return int* Retorna um ponteiro para a posição final do vetor copiado
 */
int * copy(const int *first, const int *last, int *d_first){
    for(auto *i(first); i<last; ++i, ++d_first){ /*< percorrer todo o vetor */
        *d_first = *i;
    }
    return d_first;
}

int main(void){
    int A[] = {1,2,3,4,5,}; // Vetor "fonte"
    int B[] = {0,0,0}; // Vetor "destino"

    // Copiar elementos 2, 3, e 4 para o início de B.
    auto b_last = copy(std::begin(A)+1, std::begin(A)+4, std::begin(B));

    // O comando abaixo deveria imprimir B com o conteudo 2, 3, 4.
    for(auto i(std::begin(B)); i != b_last; ++i){
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    return 0;
}