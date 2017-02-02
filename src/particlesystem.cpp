/** @file particlesystem.cpp
 * @brief This is where the particles are implemented in a system. It is the so called the emitter of the system.
 * @author Richard Southern and Alice Baglietto
 * @version 1.0
 * @date 01.05.16
 */

#include "particlesystem.h"
// Needed for memcpy
#include <string.h>
// Use this to keep track of the times
#include <sys/time.h>
#include <iostream>
#include "particle.h"
#include <vector>
//window size infos
#define WIDTH 760
#define HEIGHT 600

/**
 * This function was originally written by Richard Southern and modified by Alice Baglietto
 * @brief ParticleSystem::ParticleSystem constructor
 * @author Richard Souther and Alice Baglietto
 */
ParticleSystem::ParticleSystem() : Scene()
{

}

/**
 * This function was originally written by Richard Southern and modified by Alice Baglietto
 * @brief ParticleSystem::~ParticleSystem destructor
 * @author Richard Souther and Alice Baglietto
 */
ParticleSystem::~ParticleSystem()
{
    // Only delete allocated memory if we've initialised the class
    if (m_isInit)
    {
        delete [] m_verts;
        delete [] m_tris;
    }
}

/**
 * This function was originally written by Richard Southern and modified by Alice Baglietto
 * @brief ParticleSystem::init where everything is initialised
 * @author Richard Souther and Alice Baglietto
 */
void ParticleSystem::init()
{
    // Sanity check - if we've already initialised this class we shouldn't be here
    if (m_isInit) return;

    // Call the parent class initialisation!
    Scene::init();

    /// This part of the code was modified by Alice Baglietto
    // Initialize stating position and current colour of the particles
    m_startingposition.m_x=0.0f;
    m_startingposition.m_y=0.0f;
    m_currentcolour.push_back(Vec4(1.0f,1.0f,0.98f));
    m_currentcolour.push_back(Vec4(0.6f,0.7f,1.0f));
    m_currentcolour.push_back(Vec4(0.8f,0.86f,1.0f));
    /// End of the part of code Alice Baglietto modified

    // Disable lighting for this example
    glDisable(GL_LIGHTING);
    glDisable(GL_BLEND);
}

/**
 * This function was originally written by Richard Southern and modified by Alice Baglietto
 * @brief ParticleSystem::draw where the particles are drawn if they are alive
 * @author Richard Souther and Alice Baglietto
 */
void ParticleSystem::draw()
{
    if (!m_isInit) return;
    // Clear the display buffer (colour set by glClearColor)
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    /// This part of the code was modified by Alice Baglietto
    //delete all particles when out of life
    for(auto& i : particles)
    {

        if(i.isAlive())
        {
            i.drawP();

        }
        else
        {
            particles.erase(particles.begin());
        }
    }
    /// End of the part of code Alice Baglietto modified
}

/**
 * This function was originally written by Alice Baglietto
 * @brief ParticleSystem::update where particles are updated
 * @author Alice Baglietto
 */
void ParticleSystem::update()
{
    // Call the parent class update function to make sure m_elapsedTime has been updated
    Scene::update();

    int c = rand() %3;

    particles.push_back(Particle(m_startingposition, 0.01f,0.15f,0.01f,0.15f,40,m_currentcolour[c]));
    particles.push_back(Particle(m_startingposition,-0.01f,0.15f,-0.01f,0.15f,40,m_currentcolour[c]));
    particles.push_back(Particle(m_startingposition + Vec4(0.010f,0.010f),0.01f,0.15f,0.01f,0.15f,40,m_currentcolour[c]));
    particles.push_back(Particle(m_startingposition + Vec4(0.010f,0.010f),-0.01f,0.15f,-0.01f,0.15f,40,m_currentcolour[c]));

    for(auto& i : particles)
    {
        i.updateP();
    }
}

/**
 * @brief ParticleSystem::mouseinput
 * @author Alice Baglietto
 * @param mousex the x position of the mouse
 * @param mousey the y position of the mouse
 */
void ParticleSystem::mouseinput(int mousex, int mousey)
{
    //move opengl center and mouse input center together in the screen and set starting position in mouse coordinates
    m_startingposition.m_x = ((float)mousex/WIDTH)*2 - 1;
    m_startingposition.m_y = (((float)mousey/HEIGHT)*2 - 1)*-1;
}

/**
 * @brief ParticleSystem::handlekey_snow handles the S key to change the colour of the particles and the screen
 * @author Alice Baglietto
 */
void ParticleSystem::handlekey_snow()
{
    // Set the background colour
    glClearColor(0.05f, 0.1f, 0.27f, 1.0f);
    // Set the current colour of the new particles
    m_currentcolour[0].set(1.00f,1.00f,0.98f);
    m_currentcolour[1].set(0.60f,0.70f,1.00f);
    m_currentcolour[2].set(0.80f,0.86f,1.00f);
}

/**
 * @brief ParticleSystem::handlekey_fire handles the F key to change the colour of the particles and the screen
 * @author Alice Baglietto
 */
void ParticleSystem::handlekey_fire()
{
    // Set the background colour
    glClearColor(0.22f, 0.01f, 0.27f, 1.0f);
    // Set the current colour of the new particles
    m_currentcolour[0].set(1.00f,0.93f,0.05f);
    m_currentcolour[1].set(1.00f,0.41f,0.19f);
    m_currentcolour[2].set(0.85f,0.16f,0.00f);
}

/**
 * @brief ParticleSystem::handlekey_grass handles the G key to change the colour of the particles and the screen
 * @author Alice Baglietto
 */
void ParticleSystem::handlekey_grass()
{
    // Set the background colour
    glClearColor(0.24f, 0.02f, 0.01f, 1.0f);
    // Set the current colour of the new particles
    m_currentcolour[0].set(0.05f,0.28f,0.07f);
    m_currentcolour[1].set(0.64f,0.59f,0.20f);
    m_currentcolour[2].set(0.38f,0.60f,0.12f);
}
