#ifndef FIRFILTER_TPP
#define FIRFILTER_TPP

#include "firfilter.h"

template < typename Targ >
FIRFilter< Targ >::FIRFilter( int filterSize ) :
    m_inputArray( new std::deque< Targ > () )
  , m_coefArray( new std::vector< Targ > () )
  , m_sum( Targ() )
  , m_coefArrayLoaded( false )
  , m_filterSize( filterSize )
{

}

template < typename Targ >
Targ FIRFilter<Targ>::addElementAndProcess(const Targ &a)
{
    Targ sum = 0.0f;

    if( m_coefArrayLoaded ) {
        if( m_inputArray->size() == m_filterSize ) {
            m_inputArray->pop_back();
        }

        m_inputArray->push_front( a );

        for ( int i = 0; i < m_inputArray->size(); ++i ) {
            const Targ &element = m_inputArray->at( i );
            const Targ &coefElement = m_coefArray->at( i );

            sum += element*coefElement;
        }
    }
    return sum;
}

#endif // FIRFILTER_TPP
