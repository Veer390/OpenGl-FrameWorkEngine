#include "Texture.h"
//Sets A Pixel To The image Surface
void Texture::PutPixel(int x, int y, Color Pixel)
{
	pPixels[(Width*x) + y] = Pixel;
}

//Gets A Pixel From The image Surface
Color Texture::GetPixel(int x, int y) const
{
	return pPixels[(Width*x) + y];
}

int Texture::GetHeight()
{
	return Height;
}

int Texture::GetWidth()
{
	return Width;
}



