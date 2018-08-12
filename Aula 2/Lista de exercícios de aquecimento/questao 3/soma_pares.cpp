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
    while(true){
        if(tela==1){
            ++tela;
            std::cout << "Novo par de números: " << std::endl;
            std::cin >> numero_um;
        } else {
            if(tela==2){
                std::cin >> numero_dois;
                ++tela;
            } else {
                std::cout << "Somatório final: ";
                std::cout << soma_consecultivos(numero_um, numero_dois);
                std::cout << std::endl;
                tela=1;
            }
        }   
    }
    return 0;
}