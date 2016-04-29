#ifndef FIRFILTER_H
#define FIRFILTER_H

/*--- STL Includes. ---*/
#include <deque>
#include <iostream>

template < typename Targ >
class FIRFilter
{
public:
    FIRFilter( );
    FIRFilter( int filterSize );

    void addElementAndProcess( const Targ & a );

private:
    std::deque< Targ > m_inputArray;
    Targ m_sum;

    int m_filterSize;
};

#include "firfilter.tpp"

#endif // FIRFILTER_H
