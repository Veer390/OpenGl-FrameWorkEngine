#include "Game.h"
#include <Windows.h>

int c = 0;
void DrawFrameNumber()
{
	std::cout << c << std::endl;
	c++;
}

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
	//int n=MainRenderer.SetNewTexture(Dib);
	//int m = MainRenderer.SetNewTexture(Dib);
	//MainRenderer.DrawTexture(m, { 30,20 });
	//MainRenderer.DrawTexture(n, { 50,60 });

	//int o = MainRenderer.SetNewFont(fnt);
	gfx.print({ 20,30 }, "!", &fnt);

	//int a = MainRenderer.SetNewTexture(Dib);
	//MainRenderer.DrawTexture(a, { 20,30 });

	//MainRenderer.DrawFont(o, { 30,20 }, "Aba");
	//DataStructure::Rectangle rec({ 0,0 }, { 204,0 }, { 0,247 }, { 204,247 });
	//gfx.DrawTextureWithAlpha(30, 20, Dib);

	//gfx.print({ 20,30 }, "Empyrean Veer \nEmhyr", &fnt);

	//gfx.PutPixel(250, 250, Color(255, 255, 255));
}

void Game::DrawFrame()
{
	//DrawFrameNumber();

}



