#include "Game.h"

void Game::main()
{
	if(glfwWindowShouldClose(gfx.WindowReference))
	{Playable = false;}
	else
	{
		ComposeFrame();
		DrawFrame();
	}
}

void Game::ComposeFrame()
{
	char c = 'A';
	if(kbd->CheckKeyIsPressed(int(c)))
	{
		std::cout << c << std::endl;
	}
}

void Game::DrawFrame()
{

}
