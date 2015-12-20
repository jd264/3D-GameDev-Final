#include "vector.h"
#include <vector>
#include <iostream>
#include <SDL.h>
#include <GL\glew.h>
#include <string>
#include "collisionplane.h"

#ifndef __LEVEL_H__
#define __LEVEL_H__

class level
{
	unsigned int mesh;
	std::vector<collisionPlane> cp;
	std::vector<vec3D> spawnP;
	std::string name;

public:
	level(const char* c, unsigned int map, std::vector<collisionPlane>& cplane, std::vector<vec3D>& spawnPoints);
	~level();

	void updateL();
	void showL();

	std::vector<collisionPlane>& getCollisionPlane();
	std::string& getName();

	void Change(const char* c, unsigned int map, std::vector<collisionPlane>& cplane, std::vector<vec3D>& spawnPoints);

	std::vector<vec3D>& getSpawns();
};

#endif