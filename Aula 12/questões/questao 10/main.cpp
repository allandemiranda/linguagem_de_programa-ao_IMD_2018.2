/**
 * @brief Questão 10
 * 
 * @file main.cpp
 * @author Allan de Miranda Silva
 * @date 2018-09-24
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstring>

/* Predicate function for int */
bool STR_bigg_than( const void *c ){ 
	const int *c_c = static_cast< const int * >(c);
    return *c_c < 5;
};

// ------

using Predicate = bool (*)(const void *);

using byte = unsigned char;

/**
 * @brief function called partition that receives a a range [ first ; last ) over
 * an array, reorders the elements in the range [ first , last ) in such a way that all
 * elements for which a given predicate p returns true precede the elements for which
 * predicate p returns false
 * 
 * @param first the range of elementos to examine
 * @param last the range of elementos to examine
 * @param size size of each element in the range in bytes
 * @param p unary predicate which return true for the required element
 * @return void* A pointer to the begining of the range for which predicate p return false
 */
void * partition( void * first , void * last , size_t size , Predicate p ){
    byte * salvador = static_cast<byte*>(first);

    byte * ultimo = static_cast<byte*>(last);

    while(salvador<ultimo){
        if(p(salvador)){
            salvador+=size;            
        } else {
            byte * busca_frente = salvador+size;
            while(busca_frente<ultimo){
                if(p(busca_frente)){
                    byte troca[size];
                    std::memcpy(troca,salvador,size);
                    std::memcpy(salvador,busca_frente,size);
                    std::memcpy(busca_frente,troca,size);
                    salvador+=size;
                    break;
                }
                busca_frente+=size;
            }
            if(busca_frente == ultimo){
                return salvador;
            }
        }        
    }
}

int main(int argc, char const *argv[])
{
    int A[] = {4,7,2,1,8,9,3,2,1,5,7,3,9,0};

    for(int i : A){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    int *last = (int*)(partition(std::begin(A),std::end(A),sizeof(int), STR_bigg_than));

    for(int *i(std::begin(A)); i<last; i++){
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    for(int i : A){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}