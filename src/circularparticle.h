#ifndef CIRCULARPARTICLE_H
#define CIRCULARPARTICLE_H

#include "particle.h"


class CircularParticle : public Particle
{
public:
    CircularParticle();
    void getShape();

   /* glEnable(GL_TEXTURE_2D);
      // You should probably use CSurface::OnLoad ... ;)
      //-- and make sure the Surface pointer is good!
      GLuint titleTextureID = 0;
      SDL_Surface* Surface = IMG_Load("textures/title.png");
      if(!Surface)
        {
          printf("IMG_Load: %s\n", IMG_GetError());
          std::cout<<"error"<<std::endl;
        }

      glGenTextures(1, &titleTextureID);
      glBindTexture(GL_TEXTURE_2D, titleTextureID);

      int Mode = GL_RGB;

      if(Surface->format->BytesPerPixel == 4) {
          Mode = GL_RGBA;
      }

      glTexImage2D(GL_TEXTURE_2D, 0, Mode, Surface->w, Surface->h, 0, Mode, GL_UNSIGNED_BYTE, Surface->pixels);

      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

      float X = -halfwidth;
      float Y = halfheight-1.5;
      float Width = 5;
      float Height = 1.5;
      glBegin(GL_QUADS);
          glColor3f(1.0f,1.0f,1.0f);
          glTexCoord2f(0, 1); glVertex3f(X, Y, -2);
          glTexCoord2f(1, 1); glVertex3f(X + Width, Y, -2);
          glTexCoord2f(1, 0); glVertex3f(X + Width, Y + Height, -2);
          glTexCoord2f(0, 0); glVertex3f(X, Y + Height, -2);
      glEnd();

      glDisable(GL_TEXTURE_2D);*/

};

#endif // CIRCULARPARTICLE_H
