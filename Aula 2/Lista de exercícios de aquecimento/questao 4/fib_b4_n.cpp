/**
 * @file fib_b4_n.cpp
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
    //sequencia_frib.clear(); /*< Apagar dados se existirem no vetor */
    /*! Adicionar os dois números iniciais */
    sequencia_frib.push_back(1);
    sequencia_frib.push_back(1);
    int interacao(0); /*< contador de interações */
    while(true){
        ++interacao; /*< Próxima interação */
        int somar(0);
        /*! Somar os dois números anteriores */
        for(int i(0); i<2; ++i){
            somar += sequencia_frib[interacao - i];
        }
        /*! Caso tenha atingido o número limite */
        if(somar >= ate_numero){
            break;
        } else {
            sequencia_frib.push_back(somar);
        }             
    }
}

/**
 * @brief Função main
 * @param void void
 * @retunr 0
 **/
int main(void){
    std::cout << "Digite número a analisar: " << std::endl;
    int numero; /*< Receber número digitado */
    std::cin >> numero;
    if(numero>=1){
        criar_lista_frib(numero); /*< Gerar lista */
        std::cout << "Números Fibonacci anteriores a este: " << std::endl;
        /*! Imprimir lista gerada*/
        for(int i : sequencia_frib){
            std::cout << i << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Não existem números Fibonacci anteriores a este" << std::endl;
    }    
    return 0;
}