#include "camera.h"

camera::camera()
{
	loc.x=0.0;
	loc.y=0.0;
	loc.z=0.0;
	camYaw=0.0;
	camPitch=0.0;
	speed=0.2;
	mousespeed=0.2;
	mi=false;
}

camera::camera(const vec3D& l)
{
	loc=l;
	camYaw=0.0;
	camPitch=0.0;
	speed=0.3;
	mousespeed=0.3;
	mi=false;
}

camera::camera(const vec3D& l,const float& yaw,const float& pitch)
{
	loc=l;
	 camYaw=yaw;
	 camPitch=pitch;
	 speed=0.3;
	 mousespeed=0.3;
	 mi=false;
}

camera::camera(const vec3D& l,const float& yaw,const float& pitch,const float& sp,const float& ms)
{
	loc=l;
	 camYaw=yaw;
	 camPitch=pitch;
	 speed=sp;
	 mousespeed=ms;
	 mi=false;
}


void camera::lockCamera()
{
	if(camPitch>90)
		camPitch=90;
	if(camPitch<-90)
		camPitch=-90;
	if(camYaw<0.0)
		camYaw+=360.0;
	if(camYaw>360.0)
		camYaw-=360;
}

void camera::moveCamera(const float &dir)
{
	float rad=(camYaw+dir)*M_PI/180.0;
	loc.x-=sin(rad)*speed;
	loc.z-=cos(rad)*speed;
}

void camera::moveCameraUp(const float& dir)
{
	float rad=(camPitch+dir)*M_PI/180.0;
	loc.y+=sin(rad)*speed;	
}

void camera::control()
{
	if(mi)
	{

		int MidX=320;
		int MidY=240;
		SDL_ShowCursor(SDL_DISABLE);
		int tmpx,tmpy;
		SDL_GetMouseState(&tmpx,&tmpy);
		camYaw+=mousespeed*(MidX-tmpx);
		camPitch+=mousespeed*(MidY-tmpy);
		lockCamera();
		SDL_SetRelativeMouseMode(SDL_TRUE);
		const Uint8* state=SDL_GetKeyboardState(NULL);
		if(state[SDLK_w])
		{
				moveCamera(0.0);
		}else if(state[SDLK_s])
		{
				moveCamera(180.0);
		}		
		if(state[SDLK_a])
			moveCamera(90.0);
		else if(state[SDLK_d])
			moveCamera(270);	
	}

	glRotatef(-camPitch,1.0,0.0,0.0);
	glRotatef(-camYaw,0.0,1.0,0.0);
}

void camera::update()
{
	glTranslatef(-loc.x,-loc.y,-loc.z);
}

vec3D camera::getLocation()
{
	return loc;
}

float camera::getYaw()
{
	return camYaw;
}
float camera::getPitch()
{
	return camPitch;
}

void camera::setLocation(const vec3D& newcoord)
{
	loc=newcoord;
}

void camera::lookAt(const float& y, const float& p)
{
	camYaw=y;
	camPitch=p;
}

void camera::mouseIn()
{
	mi=true;
}

void camera::mouseOut()
{
	mi=false;
}

vec3D camera::getVector()
{
	return (vec3D(-cos(camPitch*M_PI/180.0)*sin(camYaw*M_PI/180.0),sin(camPitch*M_PI/180.0),-cos(camPitch*M_PI/180.0)*cos(camYaw*M_PI/180.0)));
}

bool camera::IsMouseIn()
{
	return mi;
}


void camera::setSpeed(float sp,float ms)
{
	speed=sp;
	mousespeed=ms;
}
