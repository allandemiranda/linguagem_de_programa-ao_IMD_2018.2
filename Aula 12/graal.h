/**
 * @brief Questão 1
 * 
 * @file main.cpp
 * @author Allan de Miranda Silva
 * @date 2018-09-24
 */
#ifndef GRAAL_H
#define GRAAL_H

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cstring>

using byte = unsigned char;

// Para a questão 1
using Compare = bool (*)(const void *, const void *);

/**
 * @brief A function called min that finds and returns the first occurrence of the smallest element in a range [ first , last ) defined over a generic array.
 * 
 * @param first the range of elementos to examine.
 * @param last the range of elementos to examine.
 * @param size size of each element in the array in bytes.
 * @param cmp binary function that returns true if the first element is less than the second element, or false otherwise.
 * @return const void* 
 */
const void * min ( const void * first , const void * last , size_t size , Compare cmp ){
    byte *esquerda = static_cast<byte*>(const_cast<void*>(first));
    byte *direita = static_cast<byte*>(const_cast<void*>(last));
    byte *menor = static_cast<byte*>(const_cast<void*>(first));
    while(esquerda<direita){
        if(cmp(esquerda,menor)){
            std::memcpy(menor,esquerda,size);
        }
        esquerda += size;
    }
    return menor;
}

#endif
