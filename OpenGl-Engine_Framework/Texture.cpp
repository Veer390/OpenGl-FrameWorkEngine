#include "Texture.h"

#include <cassert>
#include <Windows.h>
#include <fstream>
#include <iostream>


/*Texture::Texture(std::string FilePath)
	:
	lgfile("Logs/TextureFileLogs.txt")
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


}*/

Texture::Texture(std::string FilePath)
	:
	lgfile("Logs\TExtureFileLogs.txt")
{
	//Creating The Image
	//cimg_library::CImg<unsigned char> Temp;
	cimg_library::CImg<unsigned char> TempImage(FilePath.c_str());

	//Image Initialization
	Width = TempImage.width();
	Height = TempImage.height();

	pPixels = new Color[Width*Height];

	for (int i = 0; i < Width; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			//Get Pixel Data
			unsigned char *r = TempImage.data(i, j, 0, 0);
			unsigned char *g = TempImage.data(i, j, 0, 1);
			unsigned char *b = TempImage.data(i, j, 0, 2);

			//Creating Color Varaiable
			Color color;
			color.SetColorFromCharData(*r, *g, *b);
			//Putting Pixel Into The Texture
			PutPixel(i, j, color);
		}
	}
}

Texture::Texture(std::string FilePath, Color AlphaColor)
	:
	AlphaColor(AlphaColor),
	lgfile("Logs/TextureFileLogs.txt")
{
	std::ifstream file(FilePath, std::ios::binary);

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
	for (int j = Height - 1; j >= 0; j--)
	{
		for (int i = 0; i <Width; i++)
		{
			PutPixel(i, j, Color(file.get(), file.get(), file.get()));
		}
		file.seekg(padding, std::ios::cur);
	}
}

Texture::Texture(Texture && rhs)
	:
	Width(rhs.Width),
	Height(rhs.Height),
	AlphaColor(rhs.AlphaColor),
	lgfile("Logs\TextureFileLogs.txt")
{
	pPixels = rhs.pPixels;
	rhs.pPixels = nullptr;
}

//Sets A Pixel To The image Surface
void Texture::PutPixel(int x, int y, Color Pixel)
{
	pPixels[y*Width + x] = Pixel;
}

//Gets A Pixel From The image Surface
Color Texture::GetPixel(int x, int y) 
{
	//std::string ToWrite = "x : " + std::to_string(x) + " y : " + std::to_string(y) + " y*Width+x : " + std::to_string(y * Width + x) + "\n";
	//lgfile.WriteToFile(ToWrite);
	//std::cout << "x :" << x << " y:" << y << " y*Width+x : " << y * Width + x << std::endl;
	return pPixels[y*Width + x];
}



int Texture::GetHeight()
{
	return Height;
}

int Texture::GetWidth()
{
	return Width;
}

Color Texture::GetAlphaChannel()
{
	return AlphaColor;
}



