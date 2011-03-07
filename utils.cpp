#include "utils.h"

using namespace irr;


irr::core::vector3df btvect_to_irrvect(const btVector3& vec) {
     return irr::core::vector3df(vec.x(), vec.y(), vec.z());
}


// Converts a quaternion to an euler angle
core::vector3df quat_to_euler(const btQuaternion &TQuat) {
	btScalar W = TQuat.getW();
	btScalar X = TQuat.getX();
	btScalar Y = TQuat.getY();
	btScalar Z = TQuat.getZ();
	float WSquared = W * W;
	float XSquared = X * X;
	float YSquared = Y * Y;
	float ZSquared = Z * Z;

	float x = (atan2f(2.0f * (Y * Z + X * W), -XSquared - YSquared + ZSquared + WSquared));
	float y = (asinf(-2.0f * (X * Z - Y * W)));
	float z = (atan2f(2.0f * (X * Y + Z * W), XSquared - YSquared - ZSquared + WSquared));

	core::vector3df euler = core::vector3df(x, y, z);
	euler *= core::RADTODEG;
	return euler;
}

video::SColor btcolor_to_irrcolor(const btVector3& color) {
     return video::SColor(
	  255,  
	  color.x() * 255,
	  color.y() * 255,
	  color.z() * 255
	  );
}


