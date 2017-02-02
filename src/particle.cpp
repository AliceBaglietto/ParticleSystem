/** @file particle.cpp
 * @brief This is where the particle is defined.
 * @author Alice Baglietto
 * @version 1.0
 * @date 01.05.16
 */

#include "particle.h"
#include <iostream>
// Needed for memcpy
#include <string.h>

// Use this to keep track of the times
#include <sys/time.h>
#include <iostream>
#include <cmath>
#include <SDL_image.h>

/**
 * @brief Particle::Particle it is the class constructor and where the time is initialized
 * @author Alice Baglietto
 */
Particle::Particle()
{
    // Initialize time
    m_time=0;
}

/**
 * @brief Particle::drawP where a particle is created and its shape randomly chosen
 * @author Alice Baglietto
 */
void Particle::drawP()
{
    // Randomly change the point size
    float f=rand() %10;
    if (f<6)
    {
        glPointSize(5.0f);
    }
    else
    {
        glPointSize(7.0f);
    }

    // Randomly change the point type (squared or circular)
    int rdm = rand() %10;
    if (rdm<5)
    {
        // Squared points
        glEnable(GL_POINT_SPRITE);
        glEnable(GL_POINT_SMOOTH);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBegin(GL_POINTS);
        glColor3f(m_colour[0], m_colour[1], m_colour[2]);
        glVertex3f(m_position.m_x,m_position.m_y,-2.0f);
        glEnd();

    }
    else if(rdm>=5)
    {
        // Circular points
        glDisable(GL_POINT_SPRITE);
        glDisable(GL_POINT_SMOOTH);
        glBegin(GL_POINTS);
        glColor3f(m_colour[0], m_colour[1], m_colour[2]);
        glVertex3f(m_position.m_x,m_position.m_y,-2.0f);
        glEnd();
    }
}

/**
 * @brief Particle::updateP where the particles path is initialised with a parametric mathematical function expression
 *                          here the time is implemented too, and linked to the particles lifetime.
 * @author Alice Baglietto
 */
void Particle::updateP()
{
    /// Parametric expression for the function that draws the particles path (Logarithmic Spiral)
    float x = m_ax*exp(m_bx*m_time)*sin(m_time) + m_startingposition.m_x;
    float y = m_ay*exp(m_by*m_time)*cos(m_time) + m_startingposition.m_y;
    m_position.m_x=x;
    m_position.m_y=y;

    //life of the particle is growing
    m_time+=0.05;
    if(m_time>m_life)
    {
        alive==false;
    }
}

/**
 * @brief Particle::getTimeP
 * @author Alice Baglietto
 * @return m_time The current time frame
 */
int Particle::getTimeP()
{
    return m_time;
}
