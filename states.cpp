#include <iostream>
#include <boost/bind.hpp>
#include <irrlicht/irrlicht.h>
#include <btBulletDynamicsCommon.h>

#include "events.h"
#include "states.h"
#include "object.h"

Object* GameState::make_spherical_object(std::string mesh, std::string texture, int mass, int radius){ 
     GfxConf gfx;
     gfx.type = GfxConf::ANIMATED;
     gfx.mesh = mesh;
     gfx.texture = texture;
     gfx.device = m_world.get_device();

     PhyxConf phyx;
     phyx.mass = mass;
     phyx.shape = new btSphereShape(radius);
     phyx.world = m_world.getPhyxWorld();

     Object* o = new Object(gfx, phyx);
     m_world.add_object(o);

     return o;
}

Object* GameState::make_cube_object(std::string mesh, std::string texture, int mass, int h){ 
     GfxConf gfx;
     gfx.type = GfxConf::ANIMATED;
     gfx.mesh = mesh;
     gfx.texture = texture;
     gfx.device = m_world.get_device();

     PhyxConf phyx;
     phyx.mass = mass;
     phyx.shape = new btBoxShape(btVector3(h, h, h));
     phyx.world = m_world.getPhyxWorld();

     Object* o = new Object(gfx, phyx);
     m_world.add_object(o);

     return o;
}

void GameState::make_floor() {
     GfxConf gfx;
     gfx.type = GfxConf::TERRAIN;
     gfx.device = m_world.get_device();

     PhyxConf phyx;
     phyx.mass = 0;
     phyx.shape = new btStaticPlaneShape(btVector3(0, 1, 0), 1);
     phyx.world = m_world.getPhyxWorld();

     Object* o = new Object(gfx, phyx);
     m_world.add_object(o);
}

void GameState::start() {
     EventManager *emgr = new EventManager;
     m_world.get_device()->setEventReceiver((irr::IEventReceiver*) emgr);
     
     
     Object* o = make_cube_object(
	  "/usr/share/irrlicht/media/sydney.md2",
	  "/usr/share/irrlicht/media/sydney.bmp",
	  10,
	  1
	  );

     this->make_floor();
     
     Action a;
     a.key = irr::KEY_KEY_T;
     a.callback = boost::bind(&Object::apply_force, o, 0, 0, 1000);
     emgr->bind_action_to_key(a);
}


bool GameState::update() {
     return m_world.step();
}

void GameState::pause() {
}

void GameState::unpause() {
}

void GameState::stop() {
     std::cout << "bye bye gamestate" << std::endl;
}

