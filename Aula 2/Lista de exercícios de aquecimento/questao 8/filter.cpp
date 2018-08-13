/**
 * @file filter.cpp
 * @brief Questão 8 da lista
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 **/
#include <iostream> /*< Biblioteca usada para cout, cin e andl */
#include <iterator>  /*< Biblioteca usada para begin e end */

/**
 * @brief Função para filtrar valores negativos do vertor
 * @param first Aponta para posição inicial do vetor
 * @param last Aponta para posição final do vetor
 * @return Retorna a posição final do vetor
 **/
int * filter(int * const first, int * const last){
    int *ponteiro_um = first; /*< Ponteiro first ou ponteiro devagar */
    int *ponteiro_dois = first; /*< Ponteiro que analisa negativos */
    int *ponteiro_tres = last; /*< Ponteiro que aponta para o final do vetor */
    bool flag(false); /*< Marcar se está em um processo de analise de negativos ou de reordenamento do vetor */
    while(ponteiro_um != ponteiro_tres){ /* Quando poteiro lento chegar ao final do vetor, é poque já foi todo analisado */
        if(flag){ /* Qunado é encontrado um número negativo no vetor */
            if(ponteiro_dois < 0){ /* Se ainda existirem mais números negativos... */
                ponteiro_dois++; /* ande o vetor de analise */
                continue;
            } else { /* Caso não exista mais núemros negativos ... */
                int *ponteiro_fake = ponteiro_um; /*< Ponteiro para ajudar na troca de posições entre os elementos do vetor */
                for(int i(0); (ponteiro_dois + i) != ponteiro_tres; ++i){ /* inicie o reordenamento nevessário */
                    *ponteiro_fake = *(ponteiro_dois + i);
                    ponteiro_fake++;
                }                
                ponteiro_tres = ponteiro_fake; /* Ajuste a posição do ponteiro final */
                ponteiro_dois = ponteiro_um; /* Ajuste a posição do ponteiro de análise */
                flag = false;
                continue;
            }
        } else { /* Quando não foi encontrado ainda números negativos */ 
            if(*ponteiro_um < 0){ /* Caso encontre um número negativo */
                ponteiro_dois = ponteiro_um + 1;
                flag = true; /* Modigique o tipo de analise */
                continue;
            } else { /* Caso ainda não encontre um número negativo */
                flag = false;
                ponteiro_um++; /* Prociga a busca no próximo elemento do vetor */
                continue;
            }
        }
    }
    return ponteiro_tres;
}

/**
 * @brief Função main
 * @param void void
 * @retunr 0
 **/
int main(void){
    int vetor_teste[] = {-2, -8, 6, 7, -3, 10, 1, 0, -3, 7};
    int *last;
    last = filter(std::begin(vetor_teste), std::end(vetor_teste));
    for(int i(0); (std::begin(vetor_teste) + i) != last; ++i){
        std::cout << vetor_teste[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}