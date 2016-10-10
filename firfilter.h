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
    FIRFilter( ) = delete;

    /**
     * @brief FIRFilter
     * Construct an FIR filter with the number of "taps" defined by the filter size.
     * The coeficcients need to be configured with the method insertFilterCoef, otherwise,
     * the filter will not be valid and will always return zero.
     * @param filterSize
     */
    FIRFilter( int filterSize );

    /**
     * @brief addElementAndProcess
     * Inser an new element to the buffer array and then calculate the filter value. It will only
     * calculate an valid output if the filter coefficients were correctly loaded.
     * @param a
     * @return
     */
    Targ addElementAndProcess( const Targ & a );

    /**
     * @brief getVector
     * Just an "get" method for returning the deque containing the last filterSize values.
     * @return
     */
    const std::deque< Targ > & getVector() const {
        return m_inputArray;
    }

    /**
     * @brief insertFilterCoef
     * Insert an filter coefficients vector. The size will be checked and must be equal to filterSize,
     * otherwise, the filter will awawys return zero.
     * @param coef
     */
    void insertFilterCoef( const std::vector<float> & coef ) {
        *m_coefArray = coef;

        if( m_coefArray->size() == m_filterSize ) {
            m_coefArrayLoaded = true;
        }
    }

    void insertFilterCoef( float *coef ) {
        m_coefArray->assign( coef, coef+m_filterSize );
    }

private:
    std::unique_ptr < std::deque< Targ > > m_inputArray;        /** An "linked-list", given that elements will be put and removed constantly. The "front" element is the newest one. */
    std::unique_ptr < std::vector< float > > m_coefArray;        /** Given that the coef doesn't change once that they were loaded, this doesn't need to be an linked-list. The front element is the coefficient for the newest input value. */
    Targ m_sum;

    bool m_coefArrayLoaded;

    int m_filterSize;
};

#include "firfilter.tpp"

#endif // FIRFILTER_H
