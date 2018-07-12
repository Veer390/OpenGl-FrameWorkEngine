#pragma once
#include <iostream>
#include <string>
#include "Renderer.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "Texture.h"
#include "Fonts.h"

/*Note - For checking if key is presses using the handle kbd please use use capital letters --donot use small letters the keycode is capital letters
  example- kbd->CheckKeyIsPressed('A'); not kbd->CheckKeyIsPressed('a');  SECOND ONE WONT WORK
  For Special keys like ARROWKEYS Please check keyboard.h for appropriate macros*/
class Game
{
public:
	Game(Graphics& gfx,Keyboard* kbd,RendererNS::Renderer& MainRenderer)
		:
		gfx(gfx),
		MainRenderer(std::move(MainRenderer)),
		kbd(kbd),
		tex(Texture(30,30)),
		Dib("Textures/dib.bmp",Color(255,255,255)),
		fnt("StandradFont", "Fonts/Standrad.bmp", true, {416,72},Color(255,255,255),13,24),
		C(255,255,255)
	{}


private:

	Graphics gfx;
	Keyboard* kbd;
	//User Defined Variables
	bool Forward = true;
	RendererNS::Renderer MainRenderer;

	//

private:
	void main();
	void ComposeFrame();
	void DrawFrame();

	//User Defined Functions
	Texture tex;
	Texture Dib;
	Font fnt;
	void incrementColor(Color& col);
	Color C;
	int c = 1;
	//

public:
	bool Playable = true;
	void Start(){main();}
};