#include "Window.h"

Window::Window(int EngineId,bool MakeWindowContextCurrent, bool InitializeGlew,
	           std::string Title, int width, int height)
	:
	width(width),
	height(height),
	WindowId(EngineId)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	WindowHandle = glfwCreateWindow(width, height, Title.c_str(), NULL, NULL);

	if (!WindowHandle)
	{
		std::cout << "Window Generation Falied   Id of the failed window is :" << WindowId<<std::endl;
	}

	if (MakeWindowContextCurrent)
	{
		glfwMakeContextCurrent(WindowHandle);
	}

	if (InitializeGlew)
	{
		GLenum err = glewInit();
		if (GLEW_OK != err)
		{
			/* Problem: glewInit failed, something is seriously wrong. */
		std::cout<<"Error: "<< glewGetErrorString(err)<<std::endl;
			
		}
		std::cout<<"Status: Using GLEW Versio : "<< glewGetString(GLEW_VERSION)<<std::endl;
	}
}

Window::~Window()
{
	glfwDestroyWindow(WindowHandle);
}
