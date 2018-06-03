#include <GLEW\glew.h>
#include <GLFW\glfw3.h>

#include <iostream>

#include "Window.h"
void InitializeGLFW()
{
	if (!glfwInit())
	{
		std::cout << "Glfw Initialization failed" << std::endl;
	}
}
int main()
{
	InitializeGLFW();
	
	

	std::cin.get();
	
}