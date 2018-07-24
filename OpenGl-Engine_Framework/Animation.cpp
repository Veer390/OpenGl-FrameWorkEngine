#include "Animation.h"

Animation::Animation(std::string name, std::vector<DataStructure::RectangleAndIndex_Animation> FramesInTextureAlongWithTextureNumber,
	                 std::vector<Texture*> TextureArray)
	:
	name(name),
	FramesInTextureAlongWithTextureNumber(FramesInTextureAlongWithTextureNumber),
	TextureArray(TextureArray)
{

}

RectangleCoordinatesWithTexturePointer Animation::GetFrame()
{
	RectangleCoordinatesWithTexturePointer Temp;

	//Check These Two Lines For any Problems...
	Temp.PayloadRectangle = FramesInTextureAlongWithTextureNumber[FramePointer - 1].RectangleBoxPayload;
	Temp.tex = TextureArray[FramesInTextureAlongWithTextureNumber[FramePointer - 1].TextureNumber];

	IncrementFramePointer();
	return Temp;
}
