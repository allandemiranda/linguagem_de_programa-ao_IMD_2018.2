/**
 * @brief Questão 7
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
    return *c_c > "aa";
};

// -------

using Predicate = bool (*)(const void *);

using byte = unsigned char;

/**
 * @brief all_of
 * 
 * @param first the range of elementos to examine
 * @param last the range of elementos to examine
 * @param size size of each element in the range in bytes
 * @param p unary predicate which return true for the required element
 * @return true if the predicate returns true for all elements in the range
 * @return false otherwise
 */
bool all_of ( const void * first , const void * last , size_t size , Predicate p ){
    byte *esquerda = static_cast<byte*>(const_cast<void*>(first));
    byte *direita = static_cast<byte*>(const_cast<void*>(last));    

    while(esquerda<direita){
        if(false == p(esquerda)){
            return false;
        }
        esquerda += size;
    }
    return true;
}

/**
 * @brief any_of
 * 
 * @param first the range of elementos to examine
 * @param last the range of elementos to examine
 * @param size size of each element in the range in bytes
 * @param p unary predicate which return true for the required element
 * @return true if unary predicate returns true for at least one element in the range
 * @return false otherwise
 */
bool any_of( const void * first , const void * last , size_t size , Predicate p ){
    if(std::distance(first,last) == 0){
        return true;
    }

    byte *esquerda = static_cast<byte*>(const_cast<void*>(first));
    byte *direita = static_cast<byte*>(const_cast<void*>(last));    

    while(esquerda<direita){
        if(p(esquerda)){
            return true;
        }
        esquerda += size;
    }
    return false;
}

/**
 * @brief none_of
 * 
 * @param first the range of elementos to examine
 * @param last the range of elementos to examine
 * @param size size of each element in the range in bytes
 * @param p unary predicate which return true for the required element
 * @return true if unary predicate returns true for no elements in the range
 * @return false otherwise
 */
bool none_of( const void * first , const void * last , size_t size , Predicate p ){
    byte *esquerda = static_cast<byte*>(const_cast<void*>(first));
    byte *direita = static_cast<byte*>(const_cast<void*>(last));    

    while(esquerda<direita){
        if(p(esquerda)){
            return false;
        }
        esquerda += size;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int A[] = {1,2,3,4,5,6,7,8,9};
    int numero = 7;

    //std::cout << *(int*)(find(std::begin(A), std::end(A), sizeof(int), &numero, STR_equal_to)) << std::endl;

    return 0;
}