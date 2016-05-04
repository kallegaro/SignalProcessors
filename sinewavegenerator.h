#ifndef SINEWAVEGENERATOR_H
#define SINEWAVEGENERATOR_H

#include <iostream>
#include <math.h>

class SineWaveGenerator
{
public:

    /**
     * @brief SineWaveGenerator
     * This will construct a class that will calculate the value of a sin wave for a determined time "t".
     * @param frequency sin wave frequency in Hertz ( cycles per second )
     * @param phase sin wave phase in Deegres
     */
    explicit SineWaveGenerator( double frequency, double phase = 0.0f );

    /**
     * @brief getValue
     * Calculate the sin wave value for a given time "t"
     * @param t
     * @return
     */
    double getValue( double t );

private:
    double m_frequency;
    double m_phase;
};

#endif // SINEWAVEGENERATOR_H
