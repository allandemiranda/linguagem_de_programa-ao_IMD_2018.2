/**
 * @brief Questão 9
 * 
 * @file main.cpp
 * @author Allan de Miranda Silva
 * @date 2018-09-24
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstring>

/* Equalite function for int */
bool INT_equal_to( const void *a, const void *b )
{ 
	const int *a_ = static_cast< const int * >(a);
	const int *b_ = static_cast< const int * >(b);

    return *a_ == *b_;
};

// -------

using Equal = bool (*)(const void *, const void *);

using byte = unsigned char;

/**
 * @brief function called unique that receives a a range [ first ; last ) over an
 * array, reorders the elements in the range [ first , last ) in such a way that all unique
 * elements should appear at the beginning of the range
 * 
 * @param first the range of elementos to examine
 * @param last the range of elementos to examine
 * @param size size of each element in the range in bytes
 * @param eq binary function that returns true if the elements are equal, or false otherwise
 * @return void* A pointer to the address just past the last element of the range with unique elements.
 */
void * unique( void * first , void * last , size_t size , Equal eq ){
    byte * busca_frente = static_cast<byte*>(first);
    byte * salvador = static_cast<byte*>(first);
    
    byte * ultimo = static_cast<byte*>(last);

    while(busca_frente<ultimo){
        byte * busca_anteriores = static_cast<byte*>(first);
        while(busca_anteriores<salvador){
            if(eq(busca_frente,busca_anteriores)){
                busca_frente+=size;
                busca_anteriores = static_cast<byte*>(first);
                continue;                
            }
            busca_anteriores+=size;
        }
        std::memcpy(salvador,busca_frente,size);
        busca_frente+=size;
        salvador+=size;
    }
    return salvador-=size;
}

int main(int argc, char const *argv[])
{
    int A[] = {1,2,3,4,3,5,6,7,1,8,9,1,5};

    for(int i : A){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    int *last = (int*)(unique(std::begin(A),std::end(A),sizeof(int),INT_equal_to));

    for(int *i(std::begin(A)); i<last; i++){
        std::cout << *i << " ";
    }
    std::cout << std::endl;


    return 0;
}