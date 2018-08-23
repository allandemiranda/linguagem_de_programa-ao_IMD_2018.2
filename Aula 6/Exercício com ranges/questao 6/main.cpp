/**
 * @file main.cpp
 * @brief Questão 6 da lista
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 */
#include <iostream> // std::cout , std::cin 
#include <iterator> // std::begin() , std::end(), std::distance()

int * compact(int *first, int *last){
    int *fast = first;
    for(int *i(first); i<last; ++i){
        if(fast==last){
            return i;
        }
        if(*i < 0){
            while(true){
                if(fast<i){
                    fast = i;
                } 
                fast++;
                if(fast==last){
                    break;
                } else {
                    if(*fast > 0){
                        *i = *fast;
                        break;
                    } else {
                        continue;
                    }
                }
                
            }
        }        
    }
}

int main(void){
    int A[] = {-2, -8, 2, 7, -3, 10, 1, 0, -3, 7};
    int * posicao = compact(std::begin(A), std::end(A));

    for(int *i(std::begin(A)); i<std::end(A); ++i){
        if(i==posicao){
            std::cout << "(" << *i << ") " << std::endl;
        } else {
            std::cout << *i << " ";
        }
    }
    std::cout << std::endl;    
}