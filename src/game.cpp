#include "game.h"

static SDL_GLContext	graphicsGLContext;
static SDL_Window  *	graphicsWindow = NULL;
static GLuint			graphicsShaderProgram;
static Uint32			graphicsFrameDelay = 33;

game::game()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	const unsigned char *version;
	GLenum glewStatus;

	atexit(SDL_Quit);
	int graphicsFrameDelay = 33;

	SDL_Window *graphicsWindow = SDL_CreateWindow("3D Game",
										SDL_WINDOWPOS_UNDEFINED,
										SDL_WINDOWPOS_UNDEFINED,
										640, 480,
										SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	graphicsGLContext = SDL_GL_CreateContext(graphicsWindow);

	version = glGetString(GL_VERSION);

	SDL_GL_MakeCurrent(graphicsWindow, graphicsGLContext);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

	//MUST make a context AMD make it current BEFORE glewInit()!
	glewExperimental = GL_TRUE;
	glewStatus = glewInit();

	glClearColor(0.5, 0.5, 0.5, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 640.0/480.0, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	//initSkybox();

	std::vector<collisionPlane> mapcp;
	std::vector<vec3D> mapSP;
	mapSP.push_back(vec3D(3,4,5));

	unsigned int map = obj.load("test level.obj", &mapcp);

	levels.push_back(new level("name", map, mapcp, mapSP)); 

	player1 = new player("p1", collisionSphere(vec3D(0, 10, 0), 3.0), 0.2, 0.2);
}

game::~game()
{
	for(int i = 0; i < levels.size(); i++)
	{
		delete levels[i];
	}

	SDL_Quit();
	//killSkybox();
}

void game::initG()
{
	bool running = true;
	Uint32 start;
	SDL_Event event;

	while(running)
	{
		start = SDL_GetTicks();
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				player1->cam.mouseIn();
				SDL_ShowCursor(SDL_DISABLE);
			case SDL_KEYDOWN:
				if(event.key.keysym.sym == SDLK_p)
				{
					player1->cam.mouseOut();
					SDL_ShowCursor(SDL_ENABLE);
					break;
				}
				if(event.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
					break;
				}
			}
			}
			updateG();
			showG();
			SDL_GL_SwapWindow(graphicsWindow);
	}
}

void game::updateG()
{
	for(int i = 0; i<levels.size(); i++)
	{
		levels[i]->updateL();
	}

	player1->updateP(levels[0]->getCollisionPlane());
}

void game::showG()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//drawSkybox(50.0);
	for(int i = 0; i<levels.size(); i++)
	{
		levels[i]->showL();
	}

	player1->showP();
}