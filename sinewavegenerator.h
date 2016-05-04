#ifndef SINEWAVEGENERATOR_H
#define SINEWAVEGENERATOR_H

#include <iostream>
#include <math.h>

class SineWaveGenerator
{
public:
    explicit SineWaveGenerator( double frequency, double phase = 0.0f );

    double getValue( double t );

private:
    double m_frequency;
    double m_phase;
};

#endif // SINEWAVEGENERATOR_H
