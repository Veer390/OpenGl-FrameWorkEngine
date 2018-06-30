#pragma once
#include <GLEW\glew.h>
#include <GLFW\glfw3.h>

#include <iostream>

#include "Texture.h"
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

public:
	GLFWwindow * WindowReference;

public:
	static constexpr int ScreenWidth = 1280;
	static constexpr int ScreenHeight = 720;
};