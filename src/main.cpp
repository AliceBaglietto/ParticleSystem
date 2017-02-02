/** @file main.cpp
 * @brief This is the main source for my simple Particle System.
 * @author Richard Southern and Alice Baglietto
 * @version 1.0
 * @date 01.05.16
 */

//to include opengl for mac
#ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
//or linux
#else
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <SDL2/SDL.h>
#include "particlesystem.h"
#include "particle.h"

// Change this if you want something different.
#define WINDOW_TITLE "A Particle System!"
// These defines are for the initial window size (it can be changed in the resize function)
#define WIDTH 760
#define HEIGHT 600

// Our scene, which will store all the GL stuff
Scene *scene = NULL;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//OpenGL context
SDL_GLContext gContext;

ParticleSystem particlesys;

/**
 * This function was originally written by Richard Southern and modified by Alice Baglietto
 * @brief initSDL fires up the SDL window and readies it for OpenGL
 * @author Richard Souther and Alice Baglietto
 * @return EXIT_SUCCESS or EXIT_FAILURE
 */
int initSDL()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        return EXIT_FAILURE;
    }
    else
    {
        //Use OpenGL 3.1 core
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

        //Create window
        gWindow = SDL_CreateWindow( "A Particle System!",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    WIDTH,
                                    HEIGHT,
                                    SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

/**
 * This function was originally written by Richard Southern
 * @brief timerCallback an SDL2 callback function which will trigger whenever the timer has hit the elapsed time.
 * @author Richard Southern
 * @param interval The elapsed time (not used - scene uses it's own internal clock)
 * @return the elapsed time.
 */
Uint32 timerCallback(Uint32 interval, void *)
{
    if (scene != NULL)
    {
        scene->update();
        //scene->draw();
    }
    return interval;
}

/** 
 * This function was originally written by Richard Southern and modified by Alice Baglietto
 * @brief main The main opengl loop is managed here
 * @author Richard Souther and Alice Baglietto
 * @param argc Not used
 * @param args Not used
 * @return EXIT_SUCCESS if it went well!
 */
int main() //int argc, char* args[] )
{
    //Start up SDL and create window
    if( initSDL() == EXIT_FAILURE ) return EXIT_FAILURE;

    //Create context
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
     SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,2);
     SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,1);

     SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,1);
     SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,4);

     SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,16);
     SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
    gContext = SDL_GL_CreateContext( gWindow );

    SDL_GL_MakeCurrent(gWindow,gContext);
    if( gContext == NULL ) return EXIT_FAILURE;

    //Use Vsync
    if( SDL_GL_SetSwapInterval( 1 ) < 0 ) {
        fprintf(stderr, "Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError() );
    }

    // We should now be ready to use OpenGL
    // This object holds our scene. It needs to be initialised before it can be drawn.
    scene = new ParticleSystem();
    //scene = new Particle();

    // Initialise the scene
    scene->init();
    // Need an initial resize to make sure the projection matrix is initialised
    scene->resize(WIDTH, HEIGHT);

    // Use a timer to update our scene. This is the best way to handle updates,
    // as the timer runs in a separate thread and is therefore not affected by the
    // rendering performance.
    SDL_TimerID timerID = SDL_AddTimer(10, /*elapsed time in milliseconds*/
                                     timerCallback, /*callback function*/
                                     (void*) NULL /*parameters (none)*/);
    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //Enable text input
    SDL_StartTextInput();

    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            // The window has been resized
            if ((e.type == SDL_WINDOWEVENT) &&
                    (e.window.event == SDL_WINDOWEVENT_RESIZED)) {
                SDL_SetWindowSize(gWindow, e.window.data1, e.window.data2);
                scene->resize(e.window.data1, e.window.data2);
            }
            // User requests quit
            else if( e.type == SDL_QUIT )
            {
                quit = true;
            }
            /// This part of the code was modified by Alice Baglietto
            // Keyboard input
            else if(e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                // If esc is pressed, quit and close the window
                case SDLK_ESCAPE: quit=true; break;
                // If S, F or G keys are pressed, make something happen (change particles colour)
                case SDLK_s: scene->handlekey_snow();break;
                case SDLK_f: scene->handlekey_fire();break;
                case SDLK_g: scene->handlekey_grass();break;
                default: scene->handlekey_snow(); break;
                }

            }
            // Mouse input
            // If mouse right button is pressed, make somethig happen (restart the system there)
            else if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                int mousex, mousey;
                SDL_GetMouseState(&mousex, &mousey);
                scene->mouseinput(mousex, mousey);
            }
            /// End of the part of code Alice Baglietto modified
        }

        scene->update();
        //Render the scene
        scene->draw();

        //Update screen
        SDL_GL_SwapWindow( gWindow );
    }

    //Disable text input
    SDL_StopTextInput();

    // Disable our timer
    SDL_RemoveTimer(timerID);

    // Delete our scene
    delete scene;

    //Destroy window
    SDL_DestroyWindow( gWindow );

    //Quit SDL subsystems
    SDL_Quit();

    return EXIT_SUCCESS;
}
