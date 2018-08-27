/**
 * @file main.cpp
 * @brief Questão 8 da lista exerccios_ranges.pdf
 * @copyright Allan de Miranda - BTI - IMD - UFRN - 2018.2
 */
#include <iostream> // std::cout , std::cin 
#include <iterator> // std::begin() , std::end(), std::distance()

/**
 * @brief Frunção que elimina repetições de elementos no intervalo preservando a ordem relativas dos elementos únicos que sobrarem
 * 
 * @param first Ponteiro inicial do vetor que denem o intervalo de elementos para examinar
 * @param last Ponteiro sequinte ao final do vetor que denem o intervalo de elementos para examinar
 * @return int* retorna um ponteiro após-o-final do intervalo resultante
 */
int * unique(int *first, int *last){
    for(auto *slow = first; slow <= last; ++slow){ /*< Percorra todo o vetor */
        if(slow == last){ // Verifique se já chegou ao final
            return slow;
        }
        bool flag(true);
        auto *fast = slow;
        while(flag){
            for(auto *before = (slow-1); before>=first; --before){ // Rode um vetor para ver se o número já seiu
                if(*before == *fast){
                    flag = false;
                    break;
                }
            }
            if(flag){
                *slow = *fast;
                break;
            } else { // Rode um vetor para frente para buscar um número que não saiu
                flag = true;
                fast++;
                if(fast == last){
                    return slow;
                }
            }
        }        
    }
}

int main(void){
    int A[] = {1, 2, 1, 2, 3, 3, 1, 2, 4, 5, 3, 4, 5};

    // aplique unique sobre A
    auto last = unique(std::begin(A), std::end(A));

    // O comando abaixo deverá imprimir A com o conteúdo 1, 2, 3, 4, 5.
    for(auto i(std::begin(A)); i != last; ++i){
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    // Mostre o novo tamanho de A, que seria 5.
    std::cout << ">>> O comprimento ( lógico ) de A após unique () é:   " << std::distance(std::begin(A), last) << " \n";

    return 0;
}