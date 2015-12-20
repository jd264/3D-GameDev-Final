#include <SDL.h>
#include <GL\glew.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "camera.h"
#include "vector.h"
#include "collisionsphere.h"
#include "collision.h"
#include "collisionplane.h"

#ifndef __PLAYER_H__
#define __PLAYER_H__

class player
{
	std::string name;
	collisionSphere cs;
	int health;
	vec3D grav;
	vec3D dir;
	bool isGround;
	bool isCollision;
	float playerSpeed;
	float mouseSpeed;
	int pointsSys;

public:
	camera cam;
	
	player(const char* n, collisionSphere cSP, float pSpeed, float lookS);
	~player();

	void updateP(std::vector<collisionPlane>& collPlane);
	void showP();
	void setPos(vec3D pos);

	//get
	std::string getName();
	int getHealth();
	collisionSphere getCollisionSphere();
	int getPoints();

	//set
	void setHealth(int h);
	void addPoints(int p);
};

#endif