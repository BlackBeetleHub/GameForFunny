#include "Game.h"

void sdldie(const char *msg)
{
	printf("%s: %s\n", msg, SDL_GetError());
	SDL_Quit();
	exit(1);
}

Game::Game()
{
}


Game::~Game()
{
	SDL_GL_DeleteContext(maincontext);
	SDL_DestroyWindow(mainwindow);
	SDL_Quit();
}

void Game::Run()
{
	_sprite.init(-1.0f, -1.0f, 1.0f, 1.0f);
	GameLoop();
	//_sprite.init(100, 100, 100, 100);
}

void Game::initSystem(std::string nameWindow, int hight, int wigth)
{
	_hight = hight;
	_wigth = wigth;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) 
		sdldie("Unable to initialize SDL"); 								
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	
	//SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	mainwindow = SDL_CreateWindow(nameWindow.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		_hight, _wigth, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	if (!mainwindow) /* Die if creation failed */
		sdldie("Unable to create window");
	maincontext = SDL_GL_CreateContext(mainwindow);
	glewInit();
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	//SDL_GL_SetSwapInterval(1);
	glClearColor(0.0f, 0.0f, 1.0f,1.0f);
	/*SDL_GL_SwapWindow(mainwindow);*/
	initShaders();
	//DrawGame();
}

void Game::GameLoop()
{
	SDL_Event e;
	bool quit = false;
	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}
		DrawGame();
		//_sprite.draw();
	}
}

void Game::initShaders()
{
	colorProgram.CompileShaders("shaders/colorShading.vert", "shaders/colorShading.frag");
	colorProgram.AddAttribute("vertexPosition");
	colorProgram.LinkShaders();
}

void Game::DrawGame()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	colorProgram.use();
	_sprite.draw();
	colorProgram.unuse();
	SDL_GL_SwapWindow(mainwindow);
}
