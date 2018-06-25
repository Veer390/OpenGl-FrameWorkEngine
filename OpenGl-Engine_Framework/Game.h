#pragma once
#include <iostream>
#include "Window.h"
#include "Graphics.h"
#include "Keyboard.h"

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