#include "vector.h"
#include "objloader.h"

#ifndef __COLLISION_H__
#define __COLLISION_H__

class collision
{
public:
	static bool sphereplane(vec3D& sp,vec3D pn,vec3D p1,vec3D p2,vec3D p3,vec3D p4, float r);
	static bool raysphere(float xc,float yc,float zc,float xd,float yd,float zd,float xs,float ys,float zs,float r,float* dist=NULL,vec3D* collpoint=NULL);
	static bool rayplane(const float& nx,float ny,float nz,float x0,float y0,float z0,float xs,float ys,float zs,float xd,float yd,float zd,vec3D p1,vec3D p2,vec3D p3,vec3D p4,float* dis=NULL,vec3D* point=NULL);
	static float rayplanedist(float nx,float ny,float nz,float x0,float y0,float z0,float xs,float ys,float zs,float xd,float yd,float zd);
	static float trianglearea(vec3D p1,vec3D p2,vec3D p3);
	static bool spheresphere(vec3D& c1,float r1,vec3D& c2,float r2);
	static float pointdistacesquare(vec3D p1,vec3D p2);
	static float pointdistace(vec3D p1,vec3D p2);
};

#endif