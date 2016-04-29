#ifndef FIRFILTER_TPP
#define FIRFILTER_TPP

#include "firfilter.h"

template < typename Targ >
FIRFilter< Targ >::FIRFilter()
{

}

template < typename Targ >
FIRFilter< Targ >::FIRFilter( int filterSize ) :
    m_filterSize( filterSize )
  , m_sum( Targ() )
{

}

template < typename Targ >
void FIRFilter< Targ >::addElementAndProcess(const Targ &a)
{
    m_inputArray.push_front( a );

    m_sum += a;

    if( m_inputArray.size() > m_filterSize ) {
        Targ &last = m_inputArray.back();
        m_sum -= last;
        m_inputArray.pop_back();

        std::cout << "Ultimo: " << last << std::endl;
    }

    std::cout << "Soma: " << m_sum << std::endl;
}

#endif // FIRFILTER_TPP
