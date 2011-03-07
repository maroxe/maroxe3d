#include <irrlicht/irrlicht.h> 
#include <btBulletDynamicsCommon.h>

#include "object.h"
#include "utils.h"

using namespace irr;

Object::Object(const GfxConf& gfx, const PhyxConf& phyx) {

     // graphics
     scene::ISceneManager* smgr = gfx.device->getSceneManager();
     video::IVideoDriver* driver = gfx.device->getVideoDriver();

     switch(gfx.type) {
     case GfxConf::ANIMATED:
	  m_node = smgr->addAnimatedMeshSceneNode(gfx.device->getSceneManager()->getMesh(gfx.mesh.c_str()));
	  if(!gfx.texture.empty()) {
	       m_node->setMaterialTexture(0, driver->getTexture(gfx.texture.c_str()));
	  }
	  break;
     case GfxConf::TERRAIN:
	  m_node = smgr->addMeshSceneNode(
	       smgr->addHillPlaneMesh(
		    "terrain",
		    irr::core::dimension2d< irr::f32 >(10, 10),
		    irr::core::dimension2d< irr::u32 >(10, 10)
		    )
	       );
	  break;	       
     default:
	  m_node = smgr->addAnimatedMeshSceneNode(smgr->getMesh(gfx.mesh.c_str()));
	  break;
     };
     m_node->setMaterialFlag(video::EMF_LIGHTING, false);

     // physics
     btDefaultMotionState* motion_state = new btDefaultMotionState(
	  btTransform( btQuaternion(0, 0, 0, 1), btVector3( 0, 50, 0) )
	  );
     btVector3 inertia(0, 0, 0);
     phyx.shape->calculateLocalInertia(phyx.mass, inertia);

     btRigidBody::btRigidBodyConstructionInfo conf(phyx.mass, motion_state, phyx.shape, inertia);
     m_body = new btRigidBody(conf);

     phyx.world->addRigidBody(m_body);
}

void Object::update(float dt) {
     btTransform trans;
     m_body->getMotionState()->getWorldTransform(trans);
     m_node->setPosition(btvect_to_irrvect(trans.getOrigin()));
     m_node->setRotation(quat_to_euler(m_body->getOrientation()));
}

void Object::apply_force(float x, float y, float z) {
     m_body->applyCentralForce(btVector3(x, y, z));
}

