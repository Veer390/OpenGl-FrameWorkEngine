#include "Game.h"
#include <Windows.h>


int counter = 1;
void Game::incrementColor(Color & col)
{
	if (col.GetR() >= 255)
	{
		Forward = false;
	}
	if (col.GetR() <= 0)
	{
		Forward = true;
	}
	if(Forward==true)
	{
		col.SetRGB(col.GetR() + 1, col.GetG() + 1, col.GetB() + 1);
	}
	if(Forward==false)
	{
		col.SetRGB(col.GetR() -1 , col.GetG() - 1, col.GetB() - 1);
	}
}
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
	//DataStructure::Rectangle rec({ 0,0 }, { 204,0 }, { 0,247 }, { 204,247 });
	//gfx.DrawTexture({ 30,30 }, rec, Dib);

	gfx.print({ 20,30 }, "Empyrean", &fnt);
}

void Game::DrawFrame()
{
	

}



