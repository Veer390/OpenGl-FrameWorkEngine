#pragma once
#include <GLEW\glew.h>
#include <GLFW\glfw3.h>

#include<iostream>
#include<string>

class Window		
{
public:
	Window(int EngineId,bool MakeWindowContextCurrent,bool InitializeGlew,
		   std::string Title,int width,int height);
	~Window();

private:
	GLFWwindow * WindowHandle;
	int WindowId;

	int width;
	int height;
};