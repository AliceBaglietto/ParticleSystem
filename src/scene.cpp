/** @file scene.cpp
 * @brief This is the main source for my simple Particle System.
 * @author Richard Southern and Alice Baglietto
 * @version 1.0
 * @date 01.05.16
 */

#include "scene.h"
#include "particle.h"

// Use this to keep track of the times
#include <sys/time.h>
#include <iostream>

/**
 * This function was originally written by Richard Southern
 * @brief Scene::Scene
 * @author Richard Souther
 */
Scene::Scene() : m_isInit(false),m_startTime(0.0),m_elapsedTime(0.0)
{
}

/**
 * This function was originally written by Richard Southern
 * @brief Scene::~Scene destructorize this thing. Make sure to eliminate dynamically allocated memory.
 * @author Richard Souther
 */
Scene::~Scene() {
}

/**
 * This function was originally written by Richard Southern
 * @brief Scene::init initialises the GL scene, enabling features that are needed
 * @author Richard Souther
 */
void Scene::init() {
    // Sanity check - if we've already initialised this class we shouldn't be here
    if (m_isInit) return;

    // Enable texturing
    glDisable(GL_TEXTURE_2D);

    // Enable counter clockwise face ordering
    glFrontFace(GL_CCW);
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHT0);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    GLfloat lightpos[] = {0.0f, 1.0f, 1.0f, 1.0f};
    GLfloat lightdiff[] = {0.5f, 0.5f, 0.5f, 1.0f};
    GLfloat lightamb[] = {0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat lightspec[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightdiff);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightamb);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightspec);

    // Make our points lovely and smooth
    glEnable( GL_POINT_SMOOTH );
    glEnable( GL_MULTISAMPLE_ARB);
    glEnable(GL_DEPTH_TEST);

    // Set the background colour
    glClearColor(0.05f, 0.1f, 0.27f, 1.0f);

    // Set our start time by using the gettimeofday function (accurate to 10 nanosecs)
    struct timeval tim;
    gettimeofday(&tim, NULL);
    m_startTime = tim.tv_sec+(tim.tv_usec * 1e-6);

    m_isInit = true;
}

/**
 * This function was originally written by Richard Southern
 * @brief Scene::resize needs to set up the camera paramaters (i.e. projection matrix) and the viewport
 * @author Richard Souther
 * @param w Width of window
 * @param h Height of window
 */
void Scene::resize(int w, int h) {
    if (!m_isInit) return;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, 0.1, 10); //ortho view instead of perspective
    glViewport(0,0,w,h);
    glMatrixMode(GL_MODELVIEW);
}

/**
 * This function was originally written by Richard Southern
 * @brief Scene::draw draws the scene to the current GL context. Called a lot - make this fast!
 */
void Scene::draw()
{
    if (!m_isInit) return;

    // Clear the display buffer
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

/**
 * This function was originally written by Richard Southern
 * @brief Scene::update updates the scene based on a timer. Used for animation.
 * @author Richard Souther
 */
void Scene::update()
{
    if (!m_isInit) return;

    // Some stuff we need to perform timings
    struct timeval tim;

    // Retrieve the current time in nanoseconds (accurate to 10ns)
    gettimeofday(&tim, NULL);
    double now =tim.tv_sec+(tim.tv_usec * 1e-6);

    // Increment the rotation based on the time elapsed since we started running
    m_elapsedTime = m_startTime - now;
}

/**
 * @brief Scene::mouseinput
 * @author Alice Baglietto
 * @param mousex
 * @param mousey
 */
void Scene::mouseinput(int mousex, int mousey)
{

}

/**
 * @brief Scene::handlekey_snow
 * @author Alice Baglietto
 */
void Scene::handlekey_snow()
{

}

/**
 * @brief Scene::handlekey_fire
 * @author Alice Baglietto
 */
void Scene::handlekey_fire()
{

}

/**
 * @brief Scene::handlekey_grass
 * @author Alice Baglietto
 */
void Scene::handlekey_grass()
{

}
