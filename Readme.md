----------------------------------------------------------------------------------------------------------------------
Extend the ParticleSystem Application

----------------------------------------------------------------
THESE ARE SOME GENERAL THOUGHTS AND REFERENCES ABOUT THE PROGRAM
This is a simple Particle System code in C++11, implemented using OpenGL and SDL functions as requested.

The GL Functions Library was originally written with Jon Macey during one of our workshops this last term.
It was really usueful, especially to set colours and positions, done with Vec4.

The Particle System code was written starting from Richard Southern demo code "cube.pro", sotto suo consiglio,
and implemented mostly following the general rules outlined in the recommended paper for the research: “Particle
Systems : A technique for modeling a class of Fuzzy objects” (http://tinyurl.com/mfr3x9w).

The ultimate code and the structure of the program is quite different from the initial design and research because I
found out better and preferable ways to do it. For example I did not create two different classes to define the
particle shapes but I took advange of the features of GL_POINTS instead. The two shapes are now defined when drawn.
Plus, I kept the "scene" class of Richard Southern that wasn't there in my first design but that turned out to be
really useful especially to handle the timer and the inputs.

Moreover I didn't specified any velocity for my particles because of the parametric expression that handles the path
they follow when mooving. I've chosen the algorithm between the expressions of different spirals, ending to pick the
Logarithmic one for aesthetic reasons only. My initial design was infact inspired by Queen Elsa's powers GIF from the
Disney movie Frozen (http://24.media.tumblr.com/fcc98dfcad6067713c1e632a109bd2d4/tumblr_mxw2nyxDxq1qhkjhro1_500.gif),
but that shape was way to complex to be mathematically expressed.

----------------------------------
THIS IS HOW TO OPERATE THE PROGRAM
The program deals with some simple inputs:

1- Mouse Input:
        Click with the right button of the mouse wherever on the screen and the Particle System will start growing
        again from that point.

2- Keyboard Input:
        A) "S" KEY: "S" stands for "SNOW". Press this key to set the screen colour BLUE and the particles colours
                     as different shades of WHITE and LIGHT BLUE. This is also the default option.

        B) "F" KEY: "F" stands for "FIRE". Press this key to set the screen colour PURPLE and the particles colours
                     as different shades of ORANGE, RED and YELLOW.

        C) "G" KEY: "G" stands for "GRASS". Press this key to set the screen colour BROWN and the particles colours
                     as different shades of GREEN.

        D) "ESC" KEY: "ESC" is the "ESCAPE" command that quits the program and closes the window.


---------------
ALICE BAGLIETTO
01.05.16

------------------------------------------------------------------------------------------------------------------------

