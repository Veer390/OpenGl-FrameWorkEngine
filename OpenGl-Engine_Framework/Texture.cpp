#include "Texture.h"

#include <cassert>
#include <Windows.h>
#include <fstream>
#include <iostream>


Texture::Texture(std::string FilePath)
{
	std::ifstream file(FilePath,std::ios::binary);

	BITMAPFILEHEADER BmFileHeader;
	file.read(reinterpret_cast<char*>(&BmFileHeader), sizeof(BmFileHeader));

	BITMAPINFOHEADER BmInfoHeader;
	file.read(reinterpret_cast<char*>(&BmInfoHeader), sizeof(BmInfoHeader));

	assert(BmInfoHeader.biBitCount == 24);
	assert(BmInfoHeader.biCompression == BI_RGB);

	//move the cursor to the beginning of the file...
	file.seekg(BmFileHeader.bfOffBits);

	Width = BmInfoHeader.biWidth;
	Height = BmInfoHeader.biHeight;

	pPixels = new Color[Width*Height];

	const int padding = (4 - (Width * 3) % 4) % 4;
	for (int j = Height-1; j >=0; j--)
	{
		for (int i = 0; i <Width; i++)
		{
			PutPixel(i, j, Color(file.get(), file.get(), file.get()));
		}
		file.seekg(padding, std::ios::cur);
	}


}

//Sets A Pixel To The image Surface
void Texture::PutPixel(int x, int y, Color Pixel)
{
	pPixels[y*Width + x] = Pixel;
}

//Gets A Pixel From The image Surface
Color Texture::GetPixel(int x, int y) const
{
	return pPixels[y*Width+x];
}

int Texture::GetHeight()
{
	return Height;
}

int Texture::GetWidth()
{
	return Width;
}



