#include "squaredparticle.h"
#include "GLFunctions.h"
#include <SDL.h>
#include <SDL_image.h>

SquaredParticle::SquaredParticle()
{
    /*glEnable(GL_TEXTURE_2D);
    GLuint CircularPID=0;
    SDL_Surface *Surf = IMG_Load("/Users/Alice/Desktop/P/PPP2Ass/CircularParticle.jpg");
    glGenTextures(1, &CircularPID);
    glBindTexture(GL_TEXTURE_2D, CircularPID);*/
}

void SquaredParticle::getShape()
{
    GLFunctions::cube(2.0f, 2.0f, 2.0f);
}
