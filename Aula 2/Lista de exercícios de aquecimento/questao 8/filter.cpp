/**
 * @file filter.cpp
 * @brief Questão 8 da lista
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 **/
#include <iostream> /*< Biblioteca usada para cout, cin e andl */

int * filter(const * int first, const * int last){
    int *ponteiro_um = first;
    int *ponteiro_dois = first;
    int *ponteiro_tres = last;

    bool flag(false);
    while(true){
        if(flag){
            if(ponteiro_dois < 0){
                ponteiro_dois++;
            }
        } else {
            if(*ponteiro_um < 0){
                ponteiro_dois = ponteiro_um + 1;
                flag = true;
                continue;
            } else {
                flag = false;
                ponteiro_um++;
            }
        }
    }
}

/**
 * @brief Função main
 * @param void void
 * @retunr 0
 **/
int main(void){
    int vetor_teste[] = {-2, -8, 6, 7, -3, 10, 1, 0, -3, 7};

    return 0;
}