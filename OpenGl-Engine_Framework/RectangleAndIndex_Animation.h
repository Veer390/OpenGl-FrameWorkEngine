#pragma once
#include "rectangle.h"
#include <iostream>

namespace DataStructure
{
	struct RectangleAndIndex_Animation
	{
		RectangleAndIndex_Animation() = default;
		RectangleAndIndex_Animation(DataStructure::Rectangle payload, int Index)
			:
			RectangleBoxPayload(payload),
			TextureNumber(Index)
		{}
		DataStructure::Rectangle RectangleBoxPayload;
		int TextureNumber;
	};
}