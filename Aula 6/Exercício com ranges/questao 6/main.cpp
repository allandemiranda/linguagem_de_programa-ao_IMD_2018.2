/**
 * @file main.cpp
 * @brief Questão 6 da lista exerccios_ranges.pdf
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 */
#include <iostream> // std::cout , std::cin 
#include <iterator> // std::begin() , std::end(), std::distance()

/**
 * @brief Função para "compacta" os elementos no intervalo
 * 
 * @param first Aponta para primeiro elemento do vetor
 * @param last Aponta para posição sequinte a última posição do vetor
 * @return int* Retorna um ponteioro para posição seguinte da compactação
 */
int * compact(int * const first, int * const last){    
    int *fast = first; /*< Ponteiro que caminhará sobre o vetor de forma rápida */ 
    for(int *slow = first; slow <= last; ++slow){ /*< Percorra todo o vetor */                 
        if(slow == last){ /*< Verificar se a compactação chegou ao fim */
            return slow;
        }
        while(true){ /*< Buscar próximo positivo apra compactação */
            if(fast == last){ /*< Verificar se a compactação chegou ao fim */
                return slow;
            }            
            if(*fast > 0){
                *slow = *fast;
                fast++;
                break;                
            } else {
                fast++;                
            }            
        } 
    }
}

int main(void){
    int A[] = {-2, -8, 2, 7, -3, 10, 1, 0, -3, 7}; /*< Vetor teste */
    int * posicao = compact(std::begin(A), std::end(A)); /*< Compactar */

    // Números ordenados
    for(int *i(std::begin(A)); i<posicao; ++i){
        std::cout << *i << " ";
    }  
    std::cout << std::endl;

    // Parte do vetor não ordenada
    for(int *i(posicao); i<std::end(A); ++i){
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    return 0;
}