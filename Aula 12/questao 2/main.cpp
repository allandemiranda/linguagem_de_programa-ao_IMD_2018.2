/**
 * @brief Questão 2
 * 
 * @file main.cpp
 * @author Allan de Miranda Silva
 * @date 2018-09-25
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstring>

using byte = unsigned char;

/**
 * @brief Function called reverse that reverses the order of the elements located in a range defined over a generic array
 * 
 * @param first the range of elementos to examine
 * @param last the range of elementos to examine
 * @param size size of each element in the array in bytes
 */
void reverse ( void * first , void * last , size_t size ){
    byte *primeiro = static_cast<byte*>(first);
    byte *segundo = static_cast<byte*>(last);
    //byte *temporario;
    segundo-=size;

    while(primeiro<segundo){       
        //std::memcpy(temporario,primeiro,size);
        //std::memcpy(primeiro,segundo,size);
        //std::memcpy(segundo,temporario,size);
        std::swap(*primeiro, *segundo);
        primeiro+=size;
        segundo-=size; 
    }
}

int main(void){
    int A[] = {1,2,3,4,5,6,7,8,9};

    for(int i : A){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    reverse(std::begin(A), std::end(A), 4);

    for(int i : A){
        std::cout << i << " ";
    }
    std::cout << std::endl;

}