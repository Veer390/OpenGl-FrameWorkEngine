#pragma once
#include <GLEW\glew.h>
#include <GLFW\glfw3.h>

#include <iostream>

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
	void PutPixel(int x, int y, Color c);

public:
	GLFWwindow * WindowReference;

public:
	static constexpr int ScreenWidth = 1280;
	static constexpr int ScreenHeight = 720;
};