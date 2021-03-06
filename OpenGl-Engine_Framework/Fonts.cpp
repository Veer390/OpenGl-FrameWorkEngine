#include "Fonts.h"

Font::Font(std::string FontName, std::string TexPath, bool IsMonoSpace, vector MainDiamensions, int WidthPerCharacter, int HeightPerCharacter)
	:
	FontName(FontName),
	MainText(TexPath,Color(0,0,0)),
	IsMonoSpace(IsMonoSpace),
	MainDiamensions(MainDiamensions),
	DiamensionsPerCharacter({WidthPerCharacter,HeightPerCharacter}),
	AlphaColor(0,0,0)
{
	if (IsMonoSpace)
	{
		int TotalArea = MainDiamensions.x*MainDiamensions.y;
		int AreaPerCharacter = DiamensionsPerCharacter.x*DiamensionsPerCharacter.y;
		NumberOfCharacters = TotalArea / AreaPerCharacter;
	}
}

Font::Font(std::string FontName, Texture Tex, bool IsMonoSpace, vector MainDiamensions, int WidthPerCharacter, int HeightPerCharacter)
	:
	FontName(FontName),
	MainText(Tex),
	IsMonoSpace(IsMonoSpace),
	MainDiamensions(MainDiamensions),
	DiamensionsPerCharacter({ WidthPerCharacter,HeightPerCharacter }),
	AlphaColor(0,0,0)
{
	if (IsMonoSpace)
	{
		int TotalArea = MainDiamensions.x*MainDiamensions.y;
		int AreaPerCharacter = DiamensionsPerCharacter.x*DiamensionsPerCharacter.y;
		NumberOfCharacters = TotalArea / AreaPerCharacter;
	}
}

Font::Font(std::string FontName, std::string TexPath, bool IsMonoSpace, vector MainDiamensions, Color AlphaColor, int WidthPerCharacter, int HeightPerCharacter)
	:
	FontName(FontName),
	MainText(TexPath,AlphaColor),
	IsMonoSpace(IsMonoSpace),
	MainDiamensions(MainDiamensions),
	DiamensionsPerCharacter({ WidthPerCharacter,HeightPerCharacter }),
	AlphaColor(AlphaColor)
{
	if (IsMonoSpace)
	{
		int TotalArea = MainDiamensions.x*MainDiamensions.y;
		int AreaPerCharacter = DiamensionsPerCharacter.x*DiamensionsPerCharacter.y;
		NumberOfCharacters = TotalArea / AreaPerCharacter;
	}
}

Font::Font(const Font & rhs)
	:
	FontName(rhs.FontName),
	MainText(rhs.MainText),
	IsMonoSpace(rhs.IsMonoSpace),
	MainDiamensions(rhs.MainDiamensions),
	DiamensionsPerCharacter(rhs.DiamensionsPerCharacter),
	AlphaColor(rhs.AlphaColor)
{
}

Font::Font(Font && rhs)
	:
	FontName(rhs.FontName),
	MainText(std::move(rhs.MainText)),
	IsMonoSpace(rhs.IsMonoSpace),
	MainDiamensions(rhs.MainDiamensions),
	DiamensionsPerCharacter(rhs.DiamensionsPerCharacter),
	AlphaColor(rhs.AlphaColor)
{
}


Font Font::operator=(const Font & rhs)
{
	FontName = rhs.FontName;
	MainText = rhs.MainText;
	IsMonoSpace = rhs.IsMonoSpace;
	MainDiamensions = rhs.MainDiamensions;
	DiamensionsPerCharacter=rhs.DiamensionsPerCharacter;
	AlphaColor=rhs.AlphaColor;
	return *this;
}



DataStructure::Rectangle Font::GetCharacter(char character)
{
int yoffset = 0;
int offset = int(character) - 32;
if (offset >= 0 && offset <= 32)
{
	yoffset = 0;//DiamensionsPerCharacter.y;
}
else if (offset > 32 && offset <= 64)
{
	offset = offset - 32;
    yoffset = DiamensionsPerCharacter.y;
}
else if (offset > 64 && offset <= 96)
{
	offset = offset - 64;
	yoffset = DiamensionsPerCharacter.y * 2;
}
DataStructure::Rectangle CharacterImage({ offset*DiamensionsPerCharacter.x,yoffset },
	                                    { (offset*DiamensionsPerCharacter.x) + DiamensionsPerCharacter.x,yoffset },
                                        { offset*DiamensionsPerCharacter.x, yoffset+DiamensionsPerCharacter.y }, 
	                                    { (offset*DiamensionsPerCharacter.x) + DiamensionsPerCharacter.x,yoffset+DiamensionsPerCharacter.y });
return CharacterImage;
}
/*DataStructure::Rectangle Font::GetCharacter(char character)
{
	int yoffset = 0;
	int offset = int(character) - 32;
	if (offset > 32 && offset <= 64)
	{
		yoffset = DiamensionsPerCharacter.y;
	}
	else if (offset > 64 && offset <= 96)
	{
		yoffset = DiamensionsPerCharacter.y * 2;
	}
	DataStructure::Rectangle CharacterImage({ offset*DiamensionsPerCharacter.x,0+yoffset }, { (offset*DiamensionsPerCharacter.x) + DiamensionsPerCharacter.x,0+yoffset },
		{ offset*DiamensionsPerCharacter.x,DiamensionsPerCharacter.y+ yoffset }, { (offset*DiamensionsPerCharacter.x) + DiamensionsPerCharacter.x,DiamensionsPerCharacter.y+ yoffset });
	return CharacterImage;
}*/


