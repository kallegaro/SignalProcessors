#ifndef FIRFILTER_H
#define FIRFILTER_H

/*--- STL Includes. ---*/
#include <deque>
#include <vector>
#include <iostream>
#include <memory>

template < typename Targ >
class FIRFilter
{
public:
    FIRFilter( );
    FIRFilter( int filterSize );

    Targ addElementAndProcess( const Targ & a );

    const std::deque< Targ > & getVector() const {
        return m_inputArray;
    }

    void insertFilterCoef( const std::vector<float> & coef ) {
        *m_coefArray = coef;

        if( m_coefArray->size() == m_filterSize ) {
            m_coefArrayLoaded = true;
        }
    }

private:
    std::unique_ptr < std::deque< Targ > > m_inputArray;
    std::unique_ptr < std::vector< Targ > > m_coefArray;
    Targ m_sum;

    bool m_coefArrayLoaded;

    int m_filterSize;
};

#include "firfilter.tpp"

#endif // FIRFILTER_H
