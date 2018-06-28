#pragma once
#include <iostream>
#include "Window.h"
#include "Graphics.h"
#include "Keyboard.h"

/*Note - For checking if key is presses using the handle kbd please use use capital letters --donot use small letters the keycode is capital letters
  example- kbd->CheckKeyIsPressed('A'); not kbd->CheckKeyIsPressed('a');  SECOND ONE WONT WORK
  For Special keys like ARROWKEYS Please check keyboard.h for appropriate macros*/
class Game
{
public:
	Game(Graphics& gfx,Keyboard* kbd)
		:
		gfx(gfx),
		kbd(kbd)
	{}


private:

	Graphics gfx;
	Keyboard* kbd;
	//User Defined Variables


	//

private:
	void main();
	void ComposeFrame();
	void DrawFrame();

	//User Defined Functions


	//

public:
	bool Playable = true;
	void Start(){main();}
};