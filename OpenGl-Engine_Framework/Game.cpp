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
	Color c(0.0f, 0.5f, 0.7f);
	Color b(255, 255, 210);
	//gfx.PutPixel(100, 0, b);
	/*for (int i = 0; i < 1280; i++)
	{
		for (int j = 0; j < 720; j++)
		{
			gfx.PutPixel(i, j, b);
		}
	}*/
	for (int i = 0; i < 1280; i++)
	{
		gfx.PutPixel(i, 720, b);
	}
	/*for (int j = 0; j < 720; j++)
	{
		gfx.PutPixel(0, j, b);
	}*/
}
