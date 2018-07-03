#include "Fonts.h"

Font::Font(std::string FontName, std::string TexPath, bool IsMonoSpace, vector MainDiamensions, int WidthPerCharacter, int HeightPerCharacter)
	:
	FontName(FontName),
	MainText(TexPath),
	IsMonoSpace(IsMonoSpace),
	MainDiamensions(MainDiamensions),
	DiamensionsPerCharacter({WidthPerCharacter,HeightPerCharacter})
{
	if (IsMonoSpace)
	{
		int TotalArea = MainDiamensions.x*MainDiamensions.y;
		int AreaPerCharacter = DiamensionsPerCharacter.x*DiamensionsPerCharacter.y;
		NumberOfCharacters = TotalArea / AreaPerCharacter;
	}
}

DataStructure::Rectangle Font::GetCharacter(char character)
{
	int offset = int(character) - 32;
	DataStructure::Rectangle CharacterImage({ offset*DiamensionsPerCharacter.x,0 }, { (offset*DiamensionsPerCharacter.x) + DiamensionsPerCharacter.x,0 },
		{ offset*DiamensionsPerCharacter.x,DiamensionsPerCharacter.y }, { (offset*DiamensionsPerCharacter.x) + DiamensionsPerCharacter.x,DiamensionsPerCharacter.y});
	return CharacterImage;
}


