#include <SDL.h>
#include <GL\glew.h>
#include <cmath>
#include <iostream>
#include "vector.h"

#ifndef __CAMERA_H__
#define __CAMERA_H__


class camera
{
	vec3D loc;
	float camYaw;
	float camPitch;
	float speed;
	float mousespeed;
	bool mi;

	void lockCamera();
	void moveCamera(const float& dir);
	void moveCameraUp(const float& dir);

	public:

	camera();
	camera(const vec3D& loc);
	camera(const vec3D& loc,const float& yaw,const float& pitch);
	camera(const vec3D& loc,const float& yaw,const float& pitch,const float& sp,const float& ms);

	void control();
	void update();

	vec3D getVector();
	vec3D getLocation();

	float getYaw();
	float getPitch();

	void setLocation(const vec3D& newcoord);
	void lookAt(const float& y, const float& p);
	void mouseIn();
	void mouseOut();

	bool IsMouseIn();

	void setSpeed(float sp,float ms);
};


#endif
