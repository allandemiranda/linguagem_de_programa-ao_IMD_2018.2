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
    const void * min( const void *, const void *, size_t, Compare );
    void reverse( void * , void * , size_t );
    void * copy( const void * , const void * , void * , size_t size_ );
    void * clone( const void * , const void * , size_t );
    const void * find_if( const void * , const void * , size_t , Predicate );
    const void * find( const void * , const void * , size_t , const void * , Equal );
    bool all_of( const void * , const void * , size_t , Predicate );
    bool any_of( const void * , const void * , size_t , Predicate );
    bool none_of( const void * , const void * , size_t , Predicate );
    bool equal( const void *, const void *, const void *, size_t , Equal );
    bool equal( const void *, const void *, const void *, const void *, size_t , Equal );
	void * unique( void *, void *, size_t, Equal );
    void * partition( void *, void *, size_t, Predicate );
    void qsort( void *, std::size_t, std::size_t, PredComp );

}

#endif
