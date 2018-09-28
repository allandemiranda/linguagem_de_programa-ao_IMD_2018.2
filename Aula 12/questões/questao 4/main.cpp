/**
 * @brief Questão 4
 * 
 * @file main.cpp
 * @author Allan de Miranda Silva
 * @date 2018-09-24
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstring>

using byte = unsigned char;

/**
 * @brief function called clone that receives a range defined over an array and returns a pointer to a new array containing a copy of the original range
 * 
 * @param first the range of elementos to examine
 * @param last the range of elementos to examine
 * @param size size of each element in the range in bytes
 * @return void* Pointer to the memory area that contains the copy of the original range
 */
void * clone( const void * first , const void * last , size_t size ){
    byte *esquerda = static_cast<byte*>(const_cast<void*>(first));
    byte *direita = static_cast<byte*>(const_cast<void*>(last));
    byte *clone_um = new(byte[std::distance(esquerda,direita)]);
    byte *clone_dois = new(byte[std::distance(esquerda,direita)]);
    for(byte i(0); i<(std::distance(esquerda,direita)); ++i){
        *(clone_um+i) = *(esquerda+i);
    }    
    std::memcpy(clone_dois, clone_um, std::distance(esquerda,direita));
    return clone_dois;
}

int main(void){
    int A[9] = {1,2,3,4,5,6,7,8,9};
    
    std::cout << "A" << std::endl;
    for(int i : A){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    int *teste = (int*)clone(std::begin(A), std::end(A), 4);

    std::cout << std::endl;
    std::cout << "B" << std::endl;
    for(int i(0); i<9; ++i){
        std::cout << *(teste+i) << " ";
    }
    std::cout << std::endl;

}