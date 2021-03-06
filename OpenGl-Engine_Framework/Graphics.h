#pragma once
#include <GLEW\glew.h>
#include <GLFW\glfw3.h>

#include <iostream>

#include "Vector.h"
#include "rectangle.h"
#include "Texture.h"
#include "Fonts.h"
#include "Color.h"


 class Graphics
{
public:
	Graphics(GLFWwindow* WindowPointer)
		:
		WindowReference(WindowPointer)
	{

	}

public:
	//Draw Pixel
	void PutPixel(int x, int y, Color c);
	
	//Draws A Texture Onto The Screen
	void DrawTexture(int x, int y,Texture tex);
	void DrawTexture(vector ScreenCoordinates, DataStructure::Rectangle TextureCoordinates, Texture tex);
	void DrawTextureWithAlpha(int x, int y, Texture tex);
	void DrawTextureWithAlpha(vector ScreenCoordinates, DataStructure::Rectangle TextureCoordinates, Texture tex);
	
	//Writes A String Onto the Screen
	void print(vector ScreenLocation,std::string Test,Font* font);

public:
	GLFWwindow * WindowReference;

public:
	static constexpr int ScreenWidth = 1280;
	static constexpr int ScreenHeight = 720;
};