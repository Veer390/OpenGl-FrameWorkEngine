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
	gfx.DrawTexture(30, 40, Dib);
	/*//gfx.PutPixel(30, 20, Color(254, 252, 251));
	for (int i = 0; i < 1280; i++)
	{
		for (int j = 0; j < 720; j++)
		{
			gfx.PutPixel(i, j, C);
			//std::cout << i << "," << j << "," << "Color: " << C.GetR() << "," << C.GetG() << "," << C.GetB() << "," << std::endl;
			incrementColor(C);
			//Sleep(10);

		}
	}
	C.SetRGB(255, 255, 255);
	std::cout << "Frame Number : " << counter << std::endl;
	counter++;
	/*int X = 0;
	int Line = 40;
	for (int i = 0; i < 100; i++)
	{
	
		gfx.PutPixel(i, Line, C);
		int r = C.GetR()-1;
		int g = C.GetG()-1;
		int b = C.GetB()-1;
		std::cout << C.GetR() << "," << C.GetG() << "," << C.GetB() << "," << std::endl;
		std::cout<<i<<","<<"40"<<","<<"Color "<< C.GetR() << "," << C.GetG() << "," << C.GetB() << "," << std::endl;
		Sleep(100);
	}
	if(Line<720)
	Line++;
	incrementColor(C);*/
		
}

void Game::DrawFrame()
{
	

}



