/**
 * @brief Questão 3
 * 
 * @file main.cpp
 * @author Allan de Miranda Silva
 * @date 2018-09-25
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstring>

using byte = unsigned char;


void * clone ( const void * first , const void * last , size_t size ){
    byte *esquerda = static_cast<byte*>(const_cast<void*>(first));
    byte *direita = static_cast<byte*>(const_cast<void*>(last));

    byte *v_clone = new(byte[std::distance(esquerda,direita)]);


    while(esquerda<direita){
        std::memcpy(v_clone,esquerda,size);
        v_clone+=size;
        esquerda+=size;
    }

    return v_clone;
}

int main(void){
    int A[9] = {1,2,3,4,5,6,7,8,9};
    
    std::cout << "A" << std::endl;
    for(int i : A){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    int *teste = (int*)clone(std::begin(A), std::end(A), 4);


    std::cout << "B" << std::endl;
    for(int i(0); i<9; ++i){
        std::cout << *(teste+i) << " ";
    }
    std::cout << std::endl;

}