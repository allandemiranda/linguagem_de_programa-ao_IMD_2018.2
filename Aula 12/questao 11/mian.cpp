/**
 * @brief Questão 11
 * 
 * @file main.cpp
 * @author Allan de Miranda Silva
 * @date 2018-09-24
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstring>

/* Sort function for int */
int STR_sort_comp( const void *a, const void *b ){
    const int * a_ = static_cast< const int * >(a);
    const int * b_ = static_cast< const int * >(b);
    if( *a_ < *b_ ){
        return -1;
    } else if( *a_ > *b_ ){
        return 1;
    } else {
        return 0;
    }
}

// ------

using ComparePred = int (*)(const void *, const void *);

using byte = unsigned char;

/**
 * @brief Sort
 * 
 * @param ptr pointer to the array to sort 
 * @param count number of elements in the array 
 * @param size size of each element in the array in bytes
 * @param comp comparison function which returns ​a negative integer value if the first argument is less than the second, a positive integer value if the first argument is greater than the second and zero if the arguments are equal.
 */
void sort( void *ptr, std::size_t count, std::size_t size, ComparePred comp ){
    byte * primeiro = static_cast<byte*>(ptr);
    byte swap[size];
    size_t min;
    for (size_t i = 0; i < (count); ++i){        
        min = i;
        for(size_t j = (i+1); j < count; ++j) {
            if(comp(primeiro+(j*size),primeiro+(min*size))==(-1)){
                min = j;
            }
        }
        if(i != min) {       
            std::memcpy(swap,primeiro+(i*size),size);
            std::memcpy(primeiro+(i*size),primeiro+(min*size),size);
            std::memcpy(primeiro+(min*size),swap,size);
        }
    } 
}

int main(){
    int A[] = {5,1,4,2,3,8,7,9,6};

    for(int i : A){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    sort(std::begin(A),std::distance(std::begin(A),std::end(A)),sizeof(int),STR_sort_comp);

    for(int i : A){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}