#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "rectangle.h"
#include "Texture.h"
#include "RectangleAndIndex_Animation.h"

struct RectangleCoordinatesWithTexturePointer
{
	RectangleCoordinatesWithTexturePointer()
		:
		PayloadRectangle({0,0}, { 0,0 }, { 0,0 }, { 0,0 })
	{

	}
	DataStructure::Rectangle PayloadRectangle;
	Texture* tex;
};
class Animation
{
public:
	/*Animation Constructor takes in a name and a special datastructure which holds the index and the rectangle coordinates of the 
	  frame to draw note- IF FRAME COORDINATES ARE RECT AND INDEX IS 2 WILL DRAW THE FRAME FROM COORDINATES OF THE SECOND TEXTURE
	                      IF FRAME COORDINATES ARE RECT AND INDEX IS 1 WILL DRAW THE FRAME FROM COORDINATES OF THE FIRST TEXTURE*/
	Animation(std::string name, std::vector<DataStructure::RectangleAndIndex_Animation> FramesInTextureAlongWithTextureNumber,
		std::vector<Texture*> TextureArray);

private:
	std::string name;
	std::vector<DataStructure::RectangleAndIndex_Animation> FramesInTextureAlongWithTextureNumber;
	std::vector<Texture*> TextureArray;
	int FramePointer = 1;

	inline void IncrementFramePointer()
	{
		if (FramePointer == FramesInTextureAlongWithTextureNumber.size() - 1)
		{
			FramePointer = 1;
		}
		else
		{
			FramePointer++;
		}
	}

public:
	inline int GetFrameNumberToDraw()
	{
		return FramePointer;
	}

	RectangleCoordinatesWithTexturePointer GetFrame();
};