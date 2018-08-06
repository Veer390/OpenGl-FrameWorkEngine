#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "rectangle.h"
#include "Texture.h"

namespace DataStructure 
{
	struct RectangleCoordinatesWithTexturePointer
	{
		RectangleCoordinatesWithTexturePointer()
			:
			PayloadRectangle({ 0,0 }, { 0,0 }, { 0,0 }, { 0,0 })
		{

		}
		DataStructure::Rectangle PayloadRectangle;
		Texture* tex;
	};
}

namespace DataStructure
{
	struct RectangleAndTextureIndex_Animation
	{
		RectangleAndTextureIndex_Animation() = default;
		RectangleAndTextureIndex_Animation(DataStructure::Rectangle payload, int Index)
			:
			RectangleBoxPayload(payload),
			TextureNumber(Index)
		{}
		DataStructure::Rectangle RectangleBoxPayload;
		int TextureNumber;
	};
}

class Animation
{
public:
	/*Animation Constructor takes in a name and a special datastructure which holds the index and the rectangle coordinates of the 
	  frame to draw note- IF FRAME COORDINATES ARE RECT AND INDEX IS 2 WILL DRAW THE FRAME FROM COORDINATES OF THE SECOND TEXTURE
	                      IF FRAME COORDINATES ARE RECT AND INDEX IS 1 WILL DRAW THE FRAME FROM COORDINATES OF THE FIRST TEXTURE*/
	Animation(std::string name, std::vector<DataStructure::RectangleAndTextureIndex_Animation> FramesInTextureAlongWithTextureNumber,
		std::vector<Texture*> TextureArray);

private:
	std::string name;
	std::vector<DataStructure::RectangleAndTextureIndex_Animation> FramesInTextureAlongWithTextureNumber;
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

	DataStructure::RectangleCoordinatesWithTexturePointer GetFrame();

	//Not intended to be used
	void SetAnimation(std::vector<DataStructure::RectangleAndTextureIndex_Animation> AnimationRectanglesWithTextureIndex);
	void SetTextureArray(std::vector<Texture*> TexturePointerArray);

public:
	std::string GetName();
};