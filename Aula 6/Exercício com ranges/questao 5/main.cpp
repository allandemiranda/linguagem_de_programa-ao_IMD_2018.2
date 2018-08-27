/**
 * @file main.cpp
 * @brief Questão 5 da lista exerccios_ranges.pdf
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 */
#include <iostream> // std::cout , std::cin 
#include <iterator> // std::begin() , std::end(), std::distance()

/**
 * @brief Função que calcula e retorna o produto escalar entre 2 vetores
 * 
 * @param a_first Ponteiros correspondente a posição inicial do vetor 'a' da operação
 * @param a_last Ponteiros correspondente a posição final do vetor 'a' da operação
 * @param b_first Ponteiros correspondente a posição inicial do vetor 'b' da operação
 * @return int retorna o resultado matemático da operação
 */
int dot_product(const int *a_first, const int *a_last, const int *b_first){
    int resultado(0);
    for(int i(0); i<std::distance(a_first, a_last); ++i){
        resultado += *(a_first+i) * *(b_first+i);
    }
    return resultado;
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