#ifndef PARTICLE_H
#define PARTICLE_H
#include <SDL.h>
#include "scene.h"
#include "GLFunctions.h"
#include <vector>

/**
 * @brief The Particle class
 * @author Alice Baglietto
 * @date 01.05.16
 *
 */
class Particle
{
public:
    Particle();
    Particle(Vec4 _position, float _ax, float _bx, float _ay, float _by, int _life, Vec4 _colour):
        m_startingposition(_position),
        m_ax(_ax),
        m_bx(_bx),
        m_ay(_ay),
        m_by(_by),
        m_life(_life),
        m_colour(_colour){alive=true;}

    void drawP();
    void updateP();
    int getTimeP();
    bool isAlive(){return alive;}

private:   
    Vec4 m_position;
    Vec4 m_startingposition;
    Vec4 m_colour;
    Vec4 m_velocity;
    // parameters for the eliptic function expression
    float m_ax, m_bx;
    float m_ay, m_by;
    // parameters for particle life and time
    float m_time;
    int m_life;
    bool alive;
};

#endif // PARTICLE_H
