#pragma once
#include <CIMG/CImg.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


#include "Logger.h"

#include "Color.h"



class Texture
{
public:
	Texture(int Width, int Height)
		:
		Width(Width),
		Height(Height),
		pPixels(new Color[Width*Height]),
		AlphaColor(0,0,0),
		lgfile("Logs/TextureFileLogs.txt")
	{}

	Texture(int Width,int Height,Color AlphaColor)
		:
		Width(Width),
		Height(Height),
		pPixels(new Color[Width*Height]),
		AlphaColor(AlphaColor),
		lgfile("Logs/TextureFileLogs.txt")
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

	//Texture Move Constructor
	Texture(Texture&& rhs);

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

	//Log files
	Logger lgfile;
    
public:

	void PutPixel(int x, int y, Color Pixel);
	 Color GetPixel(int x, int y);

	 //helper Functions
	 int GetHeight();
	 int GetWidth();
	 Color GetAlphaChannel();

};