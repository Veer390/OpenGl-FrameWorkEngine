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
		Height(Height),
		pPixels(new Color[Width*Height]),
		AlphaColor(0,0,0)
	{}

	Texture(int Width,int Height,Color AlphaColor)
		:
		Width(Width),
		Height(Height),
		pPixels(new Color[Width*Height]),
		AlphaColor(AlphaColor)
	{}
	
	Texture(const Texture& rhs)
		:
		Texture(rhs.Width,rhs.Height)
	{
		const int nPixels = Width * Height;
		for (int i = 0; i < nPixels; i++)
		{
			pPixels[i] = rhs.pPixels[i];
		}
	}

	//Loading Texture from File...
	Texture(std::string FilePath);
	Texture(std::string FilePath,Color AlphaColor);

	~Texture()
	{
		delete[] pPixels;
		pPixels = nullptr;
	}

	Texture & operator=(const Texture & rhs)
	{
		Width = rhs.Width;
		Height = rhs.Height;

		delete[]pPixels;

		pPixels = new Color[Width*Height];
		const int nPixels = Width * Height;
		for (int i = 0; i < nPixels; i++)
		{
			pPixels[i] = rhs.pPixels[i];
		}

		return *this;
	}

private:
	int Width;
	int Height;

	//Alpha Channel value
	Color AlphaColor;
	Color* pPixels;
    
public:

	void PutPixel(int x, int y, Color Pixel);
	 Color GetPixel(int x, int y) const ;

	 //helper Functions
	 int GetHeight();
	 int GetWidth();
	 Color GetAlphaChannel();

};