#include "circularparticle.h"
#include "GLFunctions.h"
#include <SDL.h>
#include <SDL_image.h>

CircularParticle::CircularParticle()
{
    /*glEnable(GL_TEXTURE_2D);
    GLuint CircularPID=0;
    SDL_Surface *Surf = IMG_Load("/Users/Alice/Desktop/P/PPP2Ass/CircularParticle.jpg");
    glGenTextures(1, &CircularPID);
    glBindTexture(GL_TEXTURE_2D, CircularPID);*/
}

void CircularParticle::getShape()
{
    GLFunctions::sphere(2.0f, 1);
}
