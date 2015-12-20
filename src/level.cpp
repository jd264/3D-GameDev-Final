#include "level.h"

level::level(const char* c, unsigned int map, std::vector<collisionPlane>& cplane, std::vector<vec3D>& spawnPoints)
{
	mesh = map;
	cp = cplane;
	spawnP = spawnPoints;
	name = c;
}

level::~level()
{

}

void level::updateL()
{

}
void level::showL()
{
	glCallList(mesh);
}

std::vector<collisionPlane>& level::getCollisionPlane()
{
	return cp;
}

std::string& level::getName()
{
	return name;
}

void level::Change(const char* c, unsigned int map, std::vector<collisionPlane>& cplane, std::vector<vec3D>& spawnPoints)
{
	mesh = map;
	cp = cplane;
	spawnP = spawnPoints;
	name = c;
}

std::vector<vec3D>& level::getSpawns()
{
	return spawnP;
}