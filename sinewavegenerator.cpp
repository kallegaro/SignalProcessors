#include "sinewavegenerator.h"

SineWaveGenerator::SineWaveGenerator(double frequency , double phase) :
    m_frequency( 2.0f*M_PI*frequency )
  , m_phase( phase )
{
}

double SineWaveGenerator::getValue( double t )
{
    return sin( m_frequency*t );
}
