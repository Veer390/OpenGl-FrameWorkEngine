#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Color.h"


class Texture
{
public:
	Texture(int Width, int Height)
		:
		Width(Width),
		Height(Height)
	{
		pPixels = new Color[Width*Height];
	}

	Texture(const Texture& rhs)
		:
		Width(rhs.Width),
		Height(rhs.Height)
	{
		pPixels = new Color[Width*Height];
		for (int i = 0; i < Width; i++)
		{
			for (int j = 0; j < Height; j++)
			{
				PutPixel(i, j, rhs.GetPixel(i, j));
			}
		}
	}

private:
	int Width;
	int Height;

	Color* pPixels;
    
public:

	void PutPixel(int x, int y, Color Pixel);
	 Color GetPixel(int x, int y) const ;

	 //helper Functions
	 int GetHeight();
	 int GetWidth();

};