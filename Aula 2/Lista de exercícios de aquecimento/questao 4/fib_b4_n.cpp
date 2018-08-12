/**
 * @file soma_pares.cpp
 * @brief Questão 4 da lista
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 **/
#include <iostream> /*< Biblioteca usada para cout, cin e andl */
#include <vector> /*< Biblioteca usada para vetores dinâmicos */

std::vector <int> sequencia_frib; /*< Quardará a sequencia de Fibonacci até o número solicitado */

/**
 * @brief Funação para criar a lista de números Fibonacci solicitada
 * @param ate_numero A lista deve gerar núemros Fibonacci menores que este
 **/
void criar_lista_frib(const int ate_numero){
    sequencia_frib.clear();
    sequencia_frib.push_back(1);
    sequencia_frib.push_back(1);
    int interacao(0);
    while(true){
        ++interacao;
        int somar(0);
        for(int i(0); i<2; ++i){
            somar += sequencia_frib[interacao - i];
        }
        if(somar >= ate_numero){
            break;
        }
        sequencia_frib.push_back(somar);        
    }
}

/**
 * @brief Função main
 * @param void void
 * @retunr 0
 **/
int main(void){
    std::cout << "Digite número a analisar: " << std::endl;
    int numero;
    std::cin >> numero;
    criar_lista_frib(numero);
    std::cout << "Números Fibonacci anteriores a este: " << std::endl;
    for(int i : sequencia_frib){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}