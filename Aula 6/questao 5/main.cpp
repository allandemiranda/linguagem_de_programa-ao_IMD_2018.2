/**
 * @file main.cpp
 * @brief Questão 5 da lista
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 */
#include <iostream> // std::cout , std::cin 
#include <iterator> // std::begin() , std::end();

int dot_product(const int *a_first, const int *a_last, const int *b_first){

}

int main(void){
    // Desejamos multiplicar a=[1, 3, -5] * b = [4, -2, -1]
    int Vet[] = {1, 3, -5, 4, -2, -1 }; // Os dois vetores armazenados no mesmo arranjo

    auto result = dot_product(std::begin(Vet), std::begin(Vet)+3, // Vetor a
                              std::begin(Vet)+3);                 // Vetor b

    // O comando a baixo deveria imprimir 3 , se correto.
    std::cout << ">>> O resultado é: " << result << std::endl;
    // [1 ,3 , -5]*[4 , -2 , -1] = (1)*(4)+(3)*(-2)+(-5)*(-1)
    //                           = 4 - 6 + 5
    //                           = 3

    return 0;
}