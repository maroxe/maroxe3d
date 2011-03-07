#ifndef DEF_WORLD
#define DEF_WORLD

#include <vector>
#include <irrlicht/irrlicht.h> 

class btDiscreteDynamicsWorld;
class Object;
class DebugDraw;

typedef std::vector<Object*> ObjectList;
typedef std::vector<Object*>::iterator ObjectIter;

class World {
public:
     World();
     bool init_gfx();
     bool init_phyx();
     void add_object(Object* object);
     //void remove_object();
     bool step();

     // getters
     irr::IrrlichtDevice* get_device() {
	  return m_device;
     }

     btDiscreteDynamicsWorld* getPhyxWorld() {
	  return m_world;
     }
     
protected:
     // graphics
     irr::IrrlichtDevice* m_device;
     irr::scene::ISceneManager* m_scene;
     irr::video::IVideoDriver* m_driver;

     // physics
     btDiscreteDynamicsWorld* m_world;

     DebugDraw* m_debug_draw;
     
     ObjectList m_objects;
};


#endif

