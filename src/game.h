#include <SDL.h>
#include <GL\glew.h>

#include "objloader.h"
#include "vector.h"
#include "collisionplane.h"
#include "collisionsphere.h"
#include "collision.h"
#include "level.h"
#include "player.h"

#ifndef __GAME_H__
#define __GAME_H__

class game
{
	objloader obj;
	std::vector<level*> levels;
	player* player1;

	void updateG();
	void showG();
	unsigned int loadTexture(const char* filename);

public:
	game();
	~game();

	void initG();
};

#endif