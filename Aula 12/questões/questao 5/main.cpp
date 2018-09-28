/**
 * @brief Questão 5
 * 
 * @file main.cpp
 * @author Allan de Miranda Silva
 * @date 2018-09-24
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstring>

/* Predicate function for string */
bool STR_bigg_than( const void *c ){ 
	const std::string *c_c = static_cast< const std::string * >(c);
    return *c_c < "aa";
};

// ------

using Predicate = bool (*)(const void *);

using byte = unsigned char;

/**
 * @brief function called find if that receives a range [ first ; last ) over an array, and returns a pointer (iterator) to the first element in the range for which a given predicate p returns true
 * 
 * @param first the range of elementos to examine
 * @param last the range of elementos to examine
 * @param size size of each element in the range in bytes
 * @param p unary predicate which return true for the required element
 * @return const void* Pointer to the first element satisfying the condition or last if no such element is found
 */
const void * find_if(const void * first , const void * last , size_t size , Predicate p ){
    byte *esquerda = static_cast<byte*>(const_cast<void*>(first));
    byte *direita = static_cast<byte*>(const_cast<void*>(last));

    while(esquerda<direita){
        if(p(esquerda)){
            return esquerda;
        }
        esquerda += size;
    }

    esquerda -= size;
    return esquerda;

}

int main(int argc, char const *argv[])
{
    std::string A[] = {"abc", "bb", "cb", "aa", "dd", "dd", "ff"};

    std::cout << *(std::string *)(find_if(std::begin(A), std::end(A), sizeof(std::string), STR_bigg_than)) << std::endl;
    return 0;
}