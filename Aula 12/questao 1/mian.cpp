/**
 * @brief Questão 1
 * 
 * @file main.cpp
 * @author Allan de Miranda Silva
 * @date 2018-09-24
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstring>

/**
 * @brief binary function
 * 
 * @param first 
 * @param second 
 * @return true that returns true if the first element is less than the second element
 * @return false otherwise
 */
bool comp_ints(const void *a, const void *b){
    const int * aa = (const int *) a;
    const int * bb = (const int *) b;

    return *aa < *bb;
}

// ------

using byte = unsigned char;

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

int main(int argc, char const *argv[])
{
    int A[] = {2,3,4,5,6,7,1,8,9,10};
    std::cout <<
    *((const int *) min(std::begin(A), std::end(A), 4, comp_ints))
    << std::endl;
    return 0;
}