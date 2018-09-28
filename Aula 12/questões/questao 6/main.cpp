/**
 * @brief Questão 6
 * 
 * @file main.cpp
 * @author Allan de Miranda Silva
 * @date 2018-09-24
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstring>

/* Equalite function for string */
bool STR_equal_to( const void *a, const void *b )
{ 
	const int *a_ = static_cast< const int * >(a);
	const int *b_ = static_cast< const int * >(b);

    return *a_ == *b_;
};

// -------

using Equal = bool (*)(const void *, const void *);

using byte = unsigned char;

/**
 * @brief function called find that receives a range [ first ; last ) over an array,
 * a target value, and returns a pointer (iterator) to the first element in the range that is
 * equal to the value passed to the function
 * 
 * @param first the range of elementos to examine
 * @param last the range of elementos to examine
 * @param size size of each element in the range in bytes
 * @param value value to compare the elements to
 * @param eq binary function that returns true if the elements are equal, or false otherwise
 * @return const void* Pointer to the first element equal to value or last if no such element is found
 */
const void * find(const void * first, const void * last, size_t size, const void * value, Equal eq){
    byte *esquerda = static_cast<byte*>(const_cast<void*>(first));
    byte *direita = static_cast<byte*>(const_cast<void*>(last));
    byte *valor = static_cast<byte*>(const_cast<void*>(value));

    while(esquerda<direita){
        if(eq(esquerda,valor)){
            return esquerda;
        }
        esquerda += size;
    }

    esquerda -= size;
    return esquerda;

}

int main(int argc, char const *argv[])
{
    int A[] = {1,2,3,4,5,6,7,8,9};
    int numero = 7;

    std::cout << *(int*)(find(std::begin(A), std::end(A), sizeof(int), &numero, STR_equal_to)) << std::endl;

    return 0;
}