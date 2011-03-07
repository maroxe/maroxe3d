#ifndef DEF_STATES
#define DEF_STATES

#include <string>
#include "fsm_system.h"
#include "world.h"


class GameState : public State {
     
public:
     Object* make_spherical_object(std::string mesh, std::string texture, int mass, int radius);
     Object* make_cube_object(std::string mesh, std::string texture, int mass, int h);

     void make_floor();

     virtual void start();
     virtual bool update();
     virtual void pause();
     virtual void unpause();
     virtual void stop();
     
protected:
     World m_world;
};

#endif


