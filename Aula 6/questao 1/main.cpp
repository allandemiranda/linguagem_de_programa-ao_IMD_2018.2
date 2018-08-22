/**
 * @file main.cpp
 * @brief Questão 1 da lista
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 */
#include <iostream> // std::cout , std::cin 
#include <iterator> // std::begin() , std::end();

/**
 * @brief Função que nega o sinal de todos os elementos no intervalo
 * 
 * @param first Aponta para primeira posição do vetor
 * @param last  Aponta para posição seuinte a última posição do vetor
 */
void negate(int * first, int * last){
    for(int i(0); i<std::distance(first, last);  ++i){
        if(*(first+i)<0){ // Verificar se o número é negativo
            *(first+i) = *(first+i) * (-1); /*< Transformar o número em positivo */
        }
    }
}

int main(void){
    int Vet[] = {1, 2, -3, -4, 5, -6};

    //** Testes usados **//

    // Nega todo o vetor.
    negate(std::begin(Vet), std::end(Vet));
    // Nega do 3º até o último elemento do vetor.
    negate(std::begin(Vet)+2, std::end(Vet));
    // Nega apenas o 4º elemento do vetor.
    negate(std::begin(Vet)+3, std::begin(Vet)+4);

    // Imprimir o vetor com as modificações
    for(int i(0); i<std::distance(std::begin(Vet), std::end(Vet)); ++i){
        std::cout << Vet[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
