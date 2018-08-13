/**
 * @file filter.cpp
 * @brief Questão 8 da lista
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 **/
#include <iostream> /*< Biblioteca usada para cout, cin e andl */
#include <iterator>  /*< Biblioteca usada para begin e end */

int * filter(int * const first, int * const last){
    int *ponteiro_um = first;
    int *ponteiro_dois = first;
    int *ponteiro_tres = last;

    bool flag(false);
    while(ponteiro_um != ponteiro_tres){
        if(flag){
            if(ponteiro_dois < 0){
                ponteiro_dois++;
                continue;
            } else {
                int *ponteiro_fake = ponteiro_um;
                for(int i(0); (ponteiro_dois + i) != ponteiro_tres; ++i){
                    *ponteiro_fake = *(ponteiro_dois + i);
                    ponteiro_fake++;
                }                
                ponteiro_tres = ponteiro_fake;
                ponteiro_dois = ponteiro_um;
                flag = false;
                continue;
            }
        } else {
            if(*ponteiro_um < 0){
                ponteiro_dois = ponteiro_um + 1;
                flag = true;
                continue;
            } else {
                flag = false;
                ponteiro_um++;
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