#include <irrlicht/irrlicht.h> 
#include <btBulletDynamicsCommon.h>

#include "object.h"
#include "world.h"
#include "debug_draw.h"

using namespace irr;

World::World() {
     init_gfx();
     init_phyx();
     m_debug_draw = new DebugDraw(m_device->getVideoDriver());
     m_debug_draw->setDebugMode(btIDebugDraw::DBG_MAX_DEBUG_DRAW_MODE);
     m_world->setDebugDrawer(m_debug_draw);
}

bool World::init_gfx() {
     m_device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(640, 480), 32,
			     false, false, false, 0);
     m_scene = m_device->getSceneManager();
     m_driver = m_device->getVideoDriver();
     m_scene->addCameraSceneNodeFPS();
     return true;
}

bool World::init_phyx() {
     btBroadphaseInterface* broadphase = new btDbvtBroadphase();
     btDefaultCollisionConfiguration* conf = new btDefaultCollisionConfiguration();
     btCollisionDispatcher* dispatcher = new btCollisionDispatcher(conf);
     btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver;

     m_world = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, conf);
     m_world->setGravity(btVector3(0, -10, 0));
}

void World::add_object(Object* object) {
     m_objects.push_back(object);
}

bool World::step() {
     m_world->stepSimulation(1/60.f, 10);
     m_world->debugDrawWorld();
     
     for(ObjectIter o = m_objects.begin();
	 o != m_objects.end();
	 o ++) {
	  (*o)->update(1);
     }

     m_driver->beginScene(true, true, video::SColor(255,10,101,140));
     m_scene->drawAll();
     m_driver->endScene();

     return m_device->run();
}

