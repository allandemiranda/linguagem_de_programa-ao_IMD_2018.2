/**
 * @file menor_elemento.cpp
 * @brief Questão 5 da lista
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 **/
#include <iostream> /*< Biblioteca usada para cout, cin e andl */
#include <vector> /*< Biblioteca usada para vetores dinâmicos */

std::vector <int> Vet; /*< vetor dinÂmico com todos os elementos */

/**
 * @brief Função para adicionar n elementos ao vetor de elementos para analise
 **/
void preencher_vetor(void){
    int numero;
    while(std::cin >> numero){
        Vet.push_back(numero);
    }
}

/**
 * @brief Função para verificar qual o menor elemento e retorna sua posição
 * @param inicial_p Aponta para posição inicial do vetor
 * @param final_p Aponta para posição final do vetor
 * @return Retorna um ponteiro da posição do menor elemento encontrado primeiro
 **/
int * verificador_valor_menor(int * const inicial_p, int const *final_p){
    int valor = *inicial_p;
    int *posicao = inicial_p;
    for(int i(1); i<(final_p-inicial_p); ++i){
        if(valor>*(inicial_p+i)){
            valor = *(inicial_p + i);
            posicao = (inicial_p + i);
        }
    }
    return posicao;
}

/**
 * @brief Função para verificar qual a posição do menor elemento
 * @param inicial_p Ponteiro que aponta para o primeiro elemento do vetor
 * @param posicao_memoria Posição da memoria do menor valor
 * @return Retorna a posição no vetor que é ocupada pela posicao_memoria 
 **/
int verificar_posicao_menor(int const *inicial_p, int * const posicao_memoria){
    int posicao(0);
    while(true){
        if(inicial_p==posicao_memoria){
            break;
        } else {
            inicial_p++;
            ++posicao;
        }
    }
    return posicao;
}

/**
 * @brief Função main
 * @param void void
 * @retunr 0
 **/
int main(void){
    std::cout << "Adicione números ao vetor: " << std::endl;
    /*! receber n números */
    preencher_vetor(); /*< Iniciar preencimento do vetor */
    int *menor_valor = (verificador_valor_menor(&Vet.front(), &Vet.back()+1));
    std::cout << "Menor valor: " << *menor_valor << std::endl;
    std::cout << "Posição: " << verificar_posicao_menor(&Vet.front(), menor_valor) << std::endl;
    return 0;
}