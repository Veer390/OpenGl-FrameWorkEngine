#include <GLEW\glew.h>
#include <GLFW\glfw3.h>

#include <iostream>

#include "Graphics.h"
#include "Keyboard.h"
#include "Game.h"

Keyboard *kbd;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//kbd->keys[key] = true;
	if (key == GLFW_KEY_E && action == GLFW_PRESS)
		std::cout << "Veer";
}
int main()
{
	if (!glfwInit())
	{
		std::cout << "Glfw Did not initialize Successfully  " << std::endl;
	}

	GLFWwindow* Window = glfwCreateWindow(Graphics::ScreenWidth, Graphics::ScreenHeight, "Test", 0, NULL);
	Graphics gfx(Window);
	Game game(gfx, kbd);
	
	glfwMakeContextCurrent(Window);

	if(glewInit())
	{
		std::cout << "Glew Did not initialize correctly " << std::endl;
	}
	else
		std::cout << " Glfw Version = " << glGetString(GL_VERSION);

	
	glfwSwapInterval(1);
	
	while (!glfwWindowShouldClose(Window))
	{
		//GameLoop
		while (game.Playable)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			game.Start();
			glfwSwapBuffers(Window);
			glfwPollEvents();
			glfwSetKeyCallback(Window, key_callback);
		}
		//End
		glfwTerminate();

		
		
	}
	

	
}