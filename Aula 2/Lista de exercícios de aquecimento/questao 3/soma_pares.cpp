/**
 * @file soma_pares.cpp
 * @brief Questão 3 da lista
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 **/
#include <iostream> /*< Biblioteca usada para cout, cin e andl */

/**
 * @brief Função para retornar a somatória consecultiva
 * @param inicial Número inicial da interação
 * @param sequencia Número de sequencias a anlisar
 * @return Somatória dos números em sequencia
 **/
int soma_consecultivos(const int inicial, const int sequencia){
    int somatorio(0); /*< Manter o somatório dos números em sequência */
    /*! montar a linha do somatório */
    for(int i(0); i<sequencia; ++i){
        somatorio += (inicial + i); /*< Somatório */
    }
    return somatorio;
}

/**
 * @brief Função main
 * @param void void
 * @retunr 0
 **/
int main(void){
    int tela(1); /*< Apontador da tela */
    int numero_um; /*< Receberá o primeiro número */
    int numero_dois; /*< Receberá a quantidade da sequência a anlisar */
    int numero; /*< Para ser recebido no cin do while */
    std::cout << "Novo par de números: " << std::endl;
    while(std::cin >> numero){
        if(tela==1){
            ++tela; /*< Pular para tela 2 na próxima interação */            
            numero_um = numero; 
        } else {          
            numero_dois = numero;                
            std::cout << "Somatório final: ";
            std::cout << soma_consecultivos(numero_um, numero_dois); /*< Resultado final */
            std::cout << std::endl;
            std::cout << "Novo par de números: " << std::endl;
            tela=1; /*< voltar para tela 1 */         
        }   
    }
    return 0;
}