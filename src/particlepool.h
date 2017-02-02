#ifndef PARTICLEPOOL_H
#define PARTICLEPOOL_H
#include "particle.h"

class ParticlePool : public Particle
{
public:
    ParticlePool();
    void animate();
private:
    static const int POOL_SIZE=100;


};
#endif // PARTICLEPOOL_H
