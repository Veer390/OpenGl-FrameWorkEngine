#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Vector.h"
#include "Graphics.h"
#include "rectangle.h"

class Line
{
public:
	Line(Graphics& gfx)
		:
		gfx(gfx)
	{}
private:
	Graphics gfx;

public:
	bool ShouldGotoNextLine(vector CurrentPosition)
	{
		if (CurrentPosition.x >= Graphics::ScreenWidth)
		{
			return true;
		}
		else return false;
	}
};