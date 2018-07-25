#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Vector.h"
#include "rectangle.h"
#include "Texture.h"
#include "Fonts.h"
#include "Line.h"
#include "Graphics.h"

#include "Animation.h"

namespace RendererNS
{
	class Renderer
	{
	public:
		//Default Constructor
		Renderer(Graphics* gfx);

		//No Copy Constructor
		Renderer(const Renderer&) = delete;

		//Move Constructor possible
		Renderer(Renderer&& rhs);

		//Cannot be constructed without graphics
		Renderer() = delete;

		//Destructor
		~Renderer()
		{
			for (auto i : Textures)
			{
				i.~Texture();
			}
			for (auto i : Fonts)
			{
				i.~Font();
			}
		}

	private:
		Line lnobj;
		Graphics * gfx;
		std::vector<Texture> Textures;
		std::vector<Font> Fonts;

	public:
		//setter functions
		int SetNewTexture(Texture NewTexture);
		int SetNewFont(Font NewFont);

		//Main Draw Functions
		void DrawTexture(int RendererValue,vector ScreenCoordinates);
		void DrawFont(int RenderValue, vector ScreenCoordinates,std::string Message);
		void DrawFontAutoLine(int RenderValue, vector ScreenCoordinates, std::string Message);
		

	public:
		void DrawANimation(Animation& Anim,vector ScreenCoordinates);
	private:
		void print(vector ScreenLocation, std::string Test, Font * font);
		void printAutoLine(vector ScreenLocation, std::string Test, Font * font);
	};
}

