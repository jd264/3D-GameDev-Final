#include "vector.h"

#ifndef __COLLISIONPLANE_H__
#define __COLLISIONPLANE_H__

class collisionPlane
{
public:
	vec3D p[4];
	vec3D normal;

	collisionPlane(float n1, float n2, float n3, float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l);
};

#endif