#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H
#include "scene.h"
#include "src/particle.h"
#include <vector>

/**
 * @brief The ParticleSystem class
 * @author Richard Southern and Alice Baglietto
 * @date 01.05.16
 */
class ParticleSystem : public Scene
{
public:
    /// Constructor
    ParticleSystem();

    /// Destructor
    virtual ~ParticleSystem();

    /// Initialises the scene, called before render().
    virtual void init();

    /// Called frequently, used if you are using some form of animation
    void update();

    /// Called most frequently, redraws the scene.
    void draw();

    /// Called to draw the system based on mouse coordinates
    void mouseinput(int mousex, int mousey);

    /// Called to handle the keyboard keys and change the particles colours
    void handlekey_snow();
    void handlekey_fire();
    void handlekey_grass();
    void handlekey_3D();

private:
    /// Dynamic storage for our point data
    Vertex *m_verts;

    /// Dynamic storage for our triangle data
    Triangle *m_tris;

    /// Particles stored as a vector
    std::vector<Particle> particles;

    /// Positions variables declared to handle the mouse input
    Vec4 m_startingposition;
    Vec4 m_position;

    /// Colours of each particle stored as a vector
    std::vector<Vec4> m_currentcolour;
};

#endif // PARTICLESYSTEM_H
