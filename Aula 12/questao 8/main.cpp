/**
 * @brief Questão 8
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
 * @brief equal
 * 
 * @param first 
 * @param last 
 * @param s_first 
 * @return true if the first range if equal to the range
 * @return false otherwise
 */
bool equal(const void * first , const void * last , const void * s_first){
    byte *esquerda = static_cast<byte*>(const_cast<void*>(first));
    byte *direita = static_cast<byte*>(const_cast<void*>(last));

    byte *esquerda_segundo = static_cast<byte*>(const_cast<void*>(s_first));

    while(esquerda<direita){
        if(*esquerda == *esquerda_segundo){
            ++esquerda;
            ++esquerda_segundo;            
        } else {
            return false;
        }
    }
    return true;
}

/**
 * @brief equal (2)
 * 
 * @param first 
 * @param last 
 * @param s_first 
 * @param s_last 
 * @return true if the first range if equal to the range
 * @return false otherwise
 */
bool equal(const void * first , const void * last , const void * s_first, const void * s_last){
    byte *esquerda = static_cast<byte*>(const_cast<void*>(first));
    byte *direita = static_cast<byte*>(const_cast<void*>(last));

    byte *esquerda_segundo = static_cast<byte*>(const_cast<void*>(s_first));
    byte *direita_segundo = static_cast<byte*>(const_cast<void*>(s_last));

    if(std::distance(esquerda,direita) == std::distance(esquerda_segundo,direita_segundo)){   
        while(esquerda<direita){
            if(*esquerda == *esquerda_segundo){
                ++esquerda;
                ++esquerda_segundo;                
            } else {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    int A[] = {1,2,3,4,5,6,7,8,9};
    int B[] = {1,2,3,4,5,6,7,8,9};

    if(equal(std::begin(A),std::end(A),std::begin(B))){
        std::cout << "EQUAL 1 OK" << std::endl;
    }

    if(equal(std::begin(A),std::end(A),std::begin(B),std::end(B))){
        std::cout << "EQUAL 2 OK" << std::endl;
    }

    return 0;
}