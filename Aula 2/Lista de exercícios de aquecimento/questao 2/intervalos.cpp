/**
 * @file intervalos.cpp
 * @brief Questão 2 da lista
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 **/
#include <iostream> /*< Biblioteca usada para cout, cin e andl */
#include <vector> /*< Biblioteca usada para vetores dinâmicos */

std::vector <int> lista_de_numeros; /*< Vetor dinâmico para salvar números */

/**
 * @brief Função para armazenar números
 */
void armazenar_numero(void){
    int numero; /*< numeros a serem digitados */
    std::cout << "Entre com os valores inteiros (Ctrl+d p/ encerrar): " << std::endl;
    while(std::cin >> numero){
        lista_de_numeros.push_back(numero); /*! Adicionar número ao vetor dinâmico */
    }
}

/**
 * @brief Função para retornar porcentagem do intervalo
 * @param valor_inicial_inclusive Número inicial a ser avaliado inclusive
 * @param valor_final_inclusive Número final a ser avaliado inclusive
 * @return Retorna a porcentagem
 **/
float porcentagem_por_intervalo(const int valor_inicial_inclusive, const int valor_final_inclusive){
    int cont(0); /*< Contador de interações qu estão dentro do intervalo */
    /*! Verificar todos os intens da lista e contar quais estão entre os intervalo */
    for(int i : lista_de_numeros){
        /*! verifica se o número do vetor pertence ao intervalo */
        if((i >= valor_inicial_inclusive) and (i <= valor_final_inclusive)){
            ++cont;
        }
    }
    size_t tamanho = lista_de_numeros.size(); /*< Quantidade total de elementos para calcular a porcentagem */
    return ( (float) cont / (float) tamanho);
}

/**
 * @brief Função main
 * @param void void
 * @retunr 0
 **/
int main(void){
    /*** [0; 25), [25; 50), [50; 75) e [75; 100] ***/
    int intervalos[] = {0,24,25,49,50,74,75,100}; /*< Intervalos a serem analisados */
    int tamanho = sizeof(intervalos)/sizeof(int); /*< Tamanho do vetor intervalo a ser analisado */
    /*! Armazenar números para serem analisados */
    armazenar_numero();
    std::cout << std::endl;
    /*! Verificar intervalos e calcular porcentagem */
    for(int i(0); i<tamanho; i+=2){
        std::cout << "Intervalo [" << intervalos[i] << ", " << intervalos[i+1] << "] = ";
        /*! Calculando porcentagem do intervalo */
        std::cout << porcentagem_por_intervalo(intervalos[i], intervalos[i+1]) * 100 << "% " << std::endl;
    }

    return 0;
}