#pragma once
#include <iostream>
#include <string>
#include "Graphics.h"
#include "Keyboard.h"
#include "Texture.h"

/*Note - For checking if key is presses using the handle kbd please use use capital letters --donot use small letters the keycode is capital letters
  example- kbd->CheckKeyIsPressed('A'); not kbd->CheckKeyIsPressed('a');  SECOND ONE WONT WORK
  For Special keys like ARROWKEYS Please check keyboard.h for appropriate macros*/
class Game
{
public:
	Game(Graphics& gfx,Keyboard* kbd)
		:
		gfx(gfx),
		kbd(kbd),
		tex(Texture(30,30)),
		Dib("Textures/dib.bmp"),
		C(255,255,255)
	{}


private:

	Graphics gfx;
	Keyboard* kbd;
	//User Defined Variables
	bool Forward = true;


	//

private:
	void main();
	void ComposeFrame();
	void DrawFrame();

	//User Defined Functions
	Texture tex;
	Texture Dib;

	void incrementColor(Color& col);
	Color C;
	//

public:
	bool Playable = true;
	void Start(){main();}
};