#include <GLEW\glew.h>
#include <GLFW\glfw3.h>

#include <iostream>

#include "Renderer.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "Game.h"

//GUI Stuff
#include "IMGUI/imgui.h"
#include "IMGUI/imgui_impl_glfw.h"
#include "IMGUI/imgui_impl_opengl3.h"

//Gloabal Keyboard Object
Keyboard keyboard;

void ExampleGui()
{
	static float f = 0.0f;
	static int counter = 0;
	ImGui::Text("Hello, world!");                           // Display some text (you can use a format string too)
	ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f    
	//ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

	//ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our windows open/close state
	//ImGui::Checkbox("Another Window", &show_another_window);

	if (ImGui::Button("Button"))                            // Buttons return true when clicked (NB: most widgets return true when edited/activated)
		counter++;
	ImGui::SameLine();
	ImGui::Text("counter = %d", counter);

	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	keyboard.keys[key] = true;
	std::cout << key << ",";
	if (key == GLFW_KEY_E && action == GLFW_PRESS)
	std::cout << "TEst Condition Met E Key Pressed"<<std::endl;
}
int main(int argc, char **argv)
{
	if (!glfwInit())
	{
		std::cout << "Glfw Did not initialize Successfully  " << std::endl;
	}

	GLFWwindow* Window = glfwCreateWindow(Graphics::ScreenWidth, Graphics::ScreenHeight, "Test", 0, NULL);
	Graphics gfx(Window);
	RendererNS::Renderer MainRenderer(&gfx);
	Game game(gfx, &keyboard,MainRenderer);
	
	glfwMakeContextCurrent(Window);

	if(glewInit())
	{
		std::cout << "Glew Did not initialize correctly " << std::endl;
	}
	else
		std::cout << " Glfw Version = " << glGetString(GL_VERSION)<<std::endl;

	
	glfwSwapInterval(1);
	
	//Initializing IMGUI
	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(Window, true);
	ImGui_ImplOpenGL3_Init();

	ImGui::StyleColorsDark();

	while (!glfwWindowShouldClose(Window))
	{
		//GameLoop
		while (game.Playable)
		{
			//New Imgui Frame Start
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			glClear(GL_COLOR_BUFFER_BIT);
			game.Start();

			ExampleGui();

			//Draw Gui
			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
			glfwSwapBuffers(Window);
			glfwPollEvents();
			glfwSetKeyCallback(Window, key_callback);
		}
		//End
		glfwTerminate();

		
		
	}
	

	
}