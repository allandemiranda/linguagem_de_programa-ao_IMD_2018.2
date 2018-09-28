/**
 * @brief Questão 3
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
 * @brief function called copy that receives a range [ first ; last ) defined over an array and copies the range values into a new range beginning at d first
 * 
 * @param first the range of elementos to examine
 * @param last the range of elementos to examine
 * @param d_first the range of elementos to examine to copy vector
 * @param size size of each element in the range in bytes
 * @return void* Pointer to the memory area that contains the copy of the original range
 */
void * copy ( const void * first , const void * last , const void * d_first , size_t size ){
    byte *esquerda = static_cast<byte*>(const_cast<void*>(first));
    byte *direita = static_cast<byte*>(const_cast<void*>(last));
    byte *primeiro = static_cast<byte*>(const_cast<void*>(d_first));
    while(esquerda<direita){
        std::memcpy(primeiro,esquerda,size);
        primeiro+=size;
        esquerda+=size;
    }
    return const_cast<void*>(d_first);
}

int main(void){
    int A[9] = {1,2,3,4,5,6,7,8,9};
    int B[9] = {0,0,0,0,0,0,0,0,0};

    std::cout << "A" << std::endl;
    for(int i : A){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "B" << std::endl;
    for(int i : B){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    copy(std::begin(A), std::end(A), std::begin(B), 4);

    std::cout << "A" << std::endl;
    for(int i : A){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "B" << std::endl;
    for(int i : B){
        std::cout << i << " ";
    }
    std::cout << std::endl;

}