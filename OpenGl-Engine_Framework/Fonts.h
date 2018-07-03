#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Vector.h"
#include "Color.h"
#include "rectangle.h"
#include "Texture.h"

class Font
{
	friend class Graphics;
public:
	//Default constructor is deleted
	Font() = delete;

	Font(std::string FontName,std::string TexPath, bool IsMonoSpace,
		vector MainDiamensions,
		int WidthPerCharacter, int HeightPerCharacter);
	Font(std::string FontName,Texture Tex, bool IsMonoSpace,
		vector MainDiamensions,
		int WidthPerCharacter, int HeightPerCharacter);

	//Same Constructors As Above only with An extra parameter to hold alpha channel

	Font(std::string FontName, std::string TexPath, bool IsMonoSpace,
		vector MainDiamensions,Color AlphaColor,
		int WidthPerCharacter, int HeightPerCharacter);
	//The Other Constructor comes loaded with a texture so need for an alpha color

private:
	Color AlphaColor;
	bool IsMonoSpace = true;
	std::string FontName;
	Texture MainText;
	vector MainDiamensions;
	vector DiamensionsPerCharacter;
	int NumberOfCharacters = 96;

private:
	
	DataStructure::Rectangle GetCharacter(char character);

};