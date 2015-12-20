#include "player.h"

player::player(const char* n, collisionSphere cSP, float pSpeed, float lookS)
{
	name = n;
	cs = cSP;
	pointsSys = 0;
	isGround = false;
	isCollision = false;
	health = 100;
	playerSpeed = pSpeed;
	mouseSpeed = lookS;

	grav.Change(0.0, -0.3, 0.0);

	setPos(vec3D(0.0, 10, 0.0));

	cam.setSpeed(playerSpeed, lookS);
}

player::~player()
{

}

void player::updateP(std::vector<collisionPlane>& collPlane)
{
	if(dir.y >= grav.y);
	{
		dir += grav;
	}

	vec3D newPos(cam.getLocation());

	for(int i=0; i<collPlane.size(); i++)
	{
		collision::sphereplane(newPos, collPlane[i].normal, collPlane[i].p[0], collPlane[i].p[1], collPlane[i].p[2], collPlane[i].p[3], cs.r);

		if(cam.getLocation().y != newPos.y)
		{
			isGround = true;
		}
		else
		{
			isGround = false;
		}

		setPos(newPos);
	}
}

void player::showP()
{

}

void player::setPos(vec3D pos)
{
	cs.center = pos;
	cam.setLocation(pos);
}

	//get
std::string player::getName()
{
	return name;
}

int player::getHealth()
{
	return health;
}

collisionSphere player::getCollisionSphere()
{
	return cs;
}

int player::getPoints()
{
	return pointsSys;
}

	//set
void player::setHealth(int h)
{
	health = h;
}

void player::addPoints(int p)
{
	pointsSys += p;
}