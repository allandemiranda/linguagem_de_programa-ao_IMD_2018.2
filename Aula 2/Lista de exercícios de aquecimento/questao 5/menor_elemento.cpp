/**
 * @file menor_elemento.cpp
 * @brief Questão 5 da lista
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 **/
#include <iostream> /*< Biblioteca usada para cout, cin e andl */
#include <vector> /*< Biblioteca usada para vetores dinâmicos */

std::vector <int> elementos; /*< vetor dinÂmico com todos os elementos */

/**
 * @brief Função para adicionar n elementos ao vetor de elementos para analise
 **/
void preencher_vetor(void){
    int numero;
    while(std::cin >> numero){
        elementos.push_back(numero);
    }
}

struct dados {
    int valor;
    int posicao;
} analise;

int verificar_menor(const int *inicio_p, const int *final_p){
    analise.posicao = 0;
    analise.valor = *inicio_p;
    for(int i(1); i < (inicio_p-final_p); ++i){
        if(analise.valor > *(inicio_p + i)){
            analise.posicao = i;
            analise.valor = *(inicio_p + i);
        }
    }
    return analise;
}


/**
 * @brief Função main
 * @param void void
 * @retunr 0
 **/
int main(void){
    std::cout << "Adicione números ao vetor: " << std::endl;
    int numero;
    while(std::cin >> numero){
        elementos.push_back(numero);
    }
    int valores_menores = verificar_menor(elementos.begin(), elementos.end());
    std::cout << "Valor: " << valores_menores.valor << " ";
    std::cout << "Posição: " << valores_menores.posicao << std::endl;
    return 0;
}