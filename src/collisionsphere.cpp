#include "collisionsphere.h"

collisionSphere::collisionSphere()
{
	r = 0;
}

collisionSphere::collisionSphere(const vec3D& vec, float rad)
{
	center.Change(vec);
	r = rad;
}