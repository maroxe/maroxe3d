#include <iostream>
#include <irrlicht/irrlicht.h> 
#include <btBulletDynamicsCommon.h>

#include "debug_draw.h"
#include "utils.h"

using namespace irr;

DebugDraw::DebugDraw(video::IVideoDriver* driver):
     m_driver(driver) {
}

void DebugDraw::drawLine (const btVector3 &from, const btVector3 &to, const btVector3 &color) {
     m_driver->setTransform(video::ETS_WORLD, core::IdentityMatrix);
     m_driver->draw3DLine(
	  btvect_to_irrvect(from),
	  btvect_to_irrvect(to),
	  btcolor_to_irrcolor(color)
	  );
     m_driver->draw3DLine(
	  core::vector3df(2, 1, 5),
	  core::vector3df(10, 10, 10)
	  );     
}

void DebugDraw::drawContactPoint (const btVector3 &PointOnB, const btVector3 &normalOnB, btScalar distance, int lifeTime, const btVector3 &color) {
}

void DebugDraw::reportErrorWarning (const char *warningString) {
     std::cout << warningString;
}

void DebugDraw::draw3dText (const btVector3 &location, const char *textString){
}

void DebugDraw::setDebugMode (int debugMode) {
     m_debug_mode = debugMode;
}

int DebugDraw::getDebugMode () const {
     return m_debug_mode;
}


     
