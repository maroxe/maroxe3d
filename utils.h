#ifndef DEF_UTILS
#define DEF_UTILS

#include <irrlicht/irrlicht.h> 
#include <btBulletDynamicsCommon.h>

irr::core::vector3df btvect_to_irrvect(const btVector3& vect);
irr::core::vector3df quat_to_euler(const btQuaternion &TQuat);

irr::video::SColor btcolor_to_irrcolor(const btVector3& color);

#endif

