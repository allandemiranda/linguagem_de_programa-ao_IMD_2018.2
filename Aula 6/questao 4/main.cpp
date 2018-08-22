/**
 * @file main.cpp
 * @brief Questão 4 da lista
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 */
#include <iostream> // std::cout , std::cin 
#include <iterator> // std::begin() , std::end();

/**
 * @brief Função que que multiplica um inteiro passado por parâmetro por todos os elementos no intervalo
 * 
 * @param first Aponta para o primeiro elemento a analisar
 * @param last Aponta para o elemento seguinte ao últimmo a ser analisado
 * @param scalar Valor inteiro a ser multiplicado pelos elementos do intervalo
 */
void scalar_multiplication(int *first, int *last, int scalar){

}

int main(void){
    int Vet[] = {1, 2, -3, -4, 5, -6};

    scalar_multiplication(std::begin(Vet), std::end(Vet), 3);
    // O vetor resultante será:
    for(int i(0); i<std::distance(std::begin(Vet), std::end(Vet)); ++i){
        std::cout << Vet[i] << " ";
    }
    std::cout << std::endl;
    // { 3, 6, -9, -12, 15, -18 }.

    return 0;
}