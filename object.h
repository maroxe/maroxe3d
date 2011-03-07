#ifndef DEF_OBJECT
#define DEF_OBJECT

#include <string>
#include <irrlicht/irrlicht.h> 
#include <btBulletDynamicsCommon.h>
#include "world.h"


struct GfxConf {
     enum NodeType { STATIC, ANIMATED, TERRAIN };
     NodeType type;
     std::string mesh;
     std::string texture;
     irr::IrrlichtDevice* device;
};

struct PhyxConf {
     int mass;
     btCollisionShape* shape;
     btDiscreteDynamicsWorld* world;
     //material propreties
};

class Object {
public:
     Object(const GfxConf& gfx, const PhyxConf& phyx);
     virtual void update(float dt);
     void apply_force(float x, float y, float z);

protected:
     irr::scene::ISceneNode* m_node;
     btRigidBody* m_body;

     friend void World::add_object(Object*);
};

#endif


