#ifndef DEBUG_DRAW
#define DEBUG_DRAW

#include <irrlicht/irrlicht.h> 
#include <btBulletDynamicsCommon.h>

class DebugDraw: public btIDebugDraw {
     
public:
     DebugDraw(irr::video::IVideoDriver* driver);
     
     virtual void drawLine (const btVector3 &from, const btVector3 &to, const btVector3 &color);
     virtual void drawContactPoint (const btVector3 &PointOnB, const btVector3 &normalOnB, btScalar distance, int lifeTime, const btVector3 &color);
     virtual void reportErrorWarning (const char *warningString);
     virtual void draw3dText (const btVector3 &location, const char *textString);
     virtual void setDebugMode (int debugMode);
     virtual int getDebugMode () const;

protected:
     irr::video::IVideoDriver* m_driver;
     int m_debug_mode;
};

#endif
     
