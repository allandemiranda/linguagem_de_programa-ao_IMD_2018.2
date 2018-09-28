// Generic Array Algorithms Library - graal.h
#ifndef _GRAAL_H_
#define _GRAAL_H_

#include <cstring>  // memcpy, memset, memmove

namespace graal
{

    // Basic unit of manipulation.
    using byte = unsigned char;

    // Basic predicate type function pointer
    using Predicate = bool (*) ( const void * );

    // Basic predicate for compare elements
    using PredComp = bool (*) (const void *, const void *);

    // Regular comparison function pointer
    using Compare = bool (*) ( const void *, const void * );

    // Regular equality function pointer 
    using Equal = bool (*) ( const void *, const void * );

    // Here are the prototypes.
    //const void * min( const void *, const void *, size_t, Compare );
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

    //void reverse( void * , void * , size_t );
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
        byte temporario[size];
        segundo-=size;
        while(primeiro<segundo){       
            std::memcpy(temporario,primeiro,size);
            std::memcpy(primeiro,segundo,size);
            std::memcpy(segundo,temporario,size);
            primeiro+=size;
            segundo-=size; 
        }
    }

    //void * copy( const void * , const void * , void * , size_t size_ );
    /**
     * @brief function called copy that receives a range [ first ; last ) defined over an array and copies the range values into a new range beginning at d first
     * 
     * @param first the range of elementos to examine
     * @param last the range of elementos to examine
     * @param d_first the range of elementos to examine to copy vector
     * @param size size of each element in the range in bytes
     * @return void* Pointer to the memory area that contains the copy of the original range
     */
    void * copy ( const void * first , const void * last , const void * d_first , size_t size ){
        byte *esquerda = static_cast<byte*>(const_cast<void*>(first));
        byte *direita = static_cast<byte*>(const_cast<void*>(last));
        byte *primeiro = static_cast<byte*>(const_cast<void*>(d_first));
        while(esquerda<direita){
            std::memcpy(primeiro,esquerda,size);
            primeiro+=size;
            esquerda+=size;
        }
        return const_cast<void*>(d_first);
    }

    //void * clone( const void * , const void * , size_t );
    /**
     * @brief function called clone that receives a range defined over an array and returns a pointer to a new array containing a copy of the original range
     * 
     * @param first the range of elementos to examine
     * @param last the range of elementos to examine
     * @param size size of each element in the range in bytes
     * @return void* Pointer to the memory area that contains the copy of the original range
     */
    void * clone( const void * first , const void * last , size_t size ){
        byte *esquerda = static_cast<byte*>(const_cast<void*>(first));
        byte *direita = static_cast<byte*>(const_cast<void*>(last));
        byte *clone_um = new(byte[std::distance(esquerda,direita)]);
        byte *clone_dois = new(byte[std::distance(esquerda,direita)]);
        for(byte i(0); i<(std::distance(esquerda,direita)); ++i){
            *(clone_um+i) = *(esquerda+i);
        }    
        std::memcpy(clone_dois, clone_um, std::distance(esquerda,direita));
        return clone_dois;
    }

    //const void * find_if( const void * , const void * , size_t , Predicate );
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

    //const void * find( const void * , const void * , size_t , const void * , Equal );
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

    //bool all_of( const void * , const void * , size_t , Predicate );
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

    //bool any_of( const void * , const void * , size_t , Predicate );
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
    byte *esquerda = static_cast<byte*>(const_cast<void*>(first));
    byte *direita = static_cast<byte*>(const_cast<void*>(last)); 
    if(std::distance(esquerda,direita) == 0){
        return true;
    }     
    while(esquerda<direita){
        if(p(esquerda)){
            return true;
        }
        esquerda += size;
    }
    return false;
}

    //bool none_of( const void * , const void * , size_t , Predicate );
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

    //bool equal( const void *, const void *, const void *, size_t , Equal );
    /**
     * @brief equal (1)
     * 
     * @param first 
     * @param last 
     * @param s_first 
     * @return true if the first range if equal to the range
     * @return false otherwise
     */
    bool equal(const void * first , const void * last , const void * s_first, size_t size, Equal eq){
        byte *esquerda = static_cast<byte*>(const_cast<void*>(first));
        byte *direita = static_cast<byte*>(const_cast<void*>(last));
        byte *esquerda_segundo = static_cast<byte*>(const_cast<void*>(s_first));
        while(esquerda<direita){
            if(eq(esquerda,esquerda_segundo)){
                esquerda+=size;
                esquerda_segundo+=size;
            } else {
                return false;
            }
        }
        return true;
    }

    //bool equal( const void *, const void *, const void *, const void *, size_t , Equal );
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
    bool equal(const void * first , const void * last , const void * s_first, const void * s_last, size_t size, Equal eq){
        byte *esquerda = static_cast<byte*>(const_cast<void*>(first));
        byte *direita = static_cast<byte*>(const_cast<void*>(last));
        byte *esquerda_segundo = static_cast<byte*>(const_cast<void*>(s_first));
        byte *direita_segundo = static_cast<byte*>(const_cast<void*>(s_last));
        if(std::distance(esquerda,direita) == std::distance(esquerda_segundo,direita_segundo)){   
            while(esquerda<direita){
                if(eq(esquerda,esquerda_segundo)){
                    esquerda+=size;
                    esquerda_segundo+=size;
                } else {
                    return false;
                }
            }
            return true;
        } else {
            return false;
        }
    }

	//void * unique( void *, void *, size_t, Equal );
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

    //void * partition( void *, void *, size_t, Predicate );
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


    //void qsort( void *, std::size_t, std::size_t, PredComp );
    /**
     * @brief Sort
     * 
     * @param ptr pointer to the array to sort 
     * @param count number of elements in the array 
     * @param size size of each element in the array in bytes
     * @param comp comparison function which returns ​a negative integer value if the first argument is less than the second, a positive integer value if the first argument is greater than the second and zero if the arguments are equal.
     */
    void qsort( void *ptr, std::size_t count, std::size_t size, PredComp comp ){
        byte * primeiro = static_cast<byte*>(ptr);
        byte swap[size];
        size_t min;
        for (size_t i = 0; i < (count); ++i){        
            min = i;
            for(size_t j = (i+1); j < count; ++j) {
                if(comp(primeiro+(j*size),primeiro+(min*size))){
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

}

#endif
