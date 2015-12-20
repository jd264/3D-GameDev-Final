#include "vector.h"

#ifndef __COLLISIONSPHERE_H__
#define __COLLISIONSPHERE_H__

class collisionSphere
{
public:
	float r;
	vec3D center;
	
	collisionSphere();
	collisionSphere(const vec3D& vec, float rad);
};

#endif