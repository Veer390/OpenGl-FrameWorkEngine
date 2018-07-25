#include "Renderer.h"
#include <iostream>

RendererNS::Renderer::Renderer(Graphics* gfx)
	:
	gfx(gfx),
	lnobj(*gfx)
{}

//Moving The Renderer
RendererNS::Renderer::Renderer(Renderer && rhs)
	:
	gfx(rhs.gfx),
	lnobj(*rhs.gfx)
{
	rhs.gfx = nullptr;
}

int RendererNS::Renderer::SetNewTexture(Texture NewTexture)
{
	int c = 0;
	Textures.emplace_back(NewTexture);
	auto end = Textures.end();
	end--;
	for(auto i =Textures.begin();;i++)
	{
		if (i == Textures.end())
			return c;
		c++;
	}
}

int RendererNS::Renderer::SetNewFont(Font NewFont)
{
	int c = 0;
	//Fonts.insert(NewFont);
	Fonts.push_back(std::move(NewFont));
	return Fonts.size();

	/*auto end = Fonts.end();
	end--;
	for (auto i = Fonts.begin();; i++)
	{
		if (i == Fonts.end())
		{
			std::cout << "C value : " << c << std::endl;
			return c;
		}
		c++;
	}*/
	
}

void RendererNS::Renderer::DrawTexture(int RendererValue,vector ScreenCoordinates)
{
	gfx->DrawTexture(ScreenCoordinates.x, ScreenCoordinates.y, Textures[RendererValue-1]);
}

void RendererNS::Renderer::DrawFont(int RenderValue, vector ScreenCoordinates, std::string Message)
{
	gfx->print(ScreenCoordinates, Message, &(Fonts[RenderValue-1]));
}

void RendererNS::Renderer::DrawFontAutoLine(int RenderValue, vector ScreenCoordinates, std::string Message)
{
	printAutoLine(ScreenCoordinates, Message, &(Fonts[RenderValue - 1]));
}



void RendererNS::Renderer::DrawANimation(Animation& Anim,vector ScreenCoordinates)
{
	auto x = Anim.GetFrame();
	//gfx->DrawTexture(ScreenCoordinates, x.PayloadRectangle,*(x.tex));
	gfx->DrawTexture(ScreenCoordinates,x.PayloadRectangle,*x.tex);
}

void RendererNS::Renderer::print(vector ScreenLocation, std::string Test, Font * font)
{
	vector TempScreenLocation = ScreenLocation;
	for (char ch : Test)
	{
		if (ch == '\n')
		{
			TempScreenLocation.x = ScreenLocation.x;
			TempScreenLocation.y = TempScreenLocation.y + font->DiamensionsPerCharacter.y;
		}
		else
		{
			DataStructure::Rectangle rect = font->GetCharacter(ch);
			gfx->DrawTexture(TempScreenLocation, rect, font->MainText);
			TempScreenLocation.x = TempScreenLocation.x + font->DiamensionsPerCharacter.x;
		}
	}
}

void RendererNS::Renderer::printAutoLine(vector ScreenLocation, std::string Test, Font * font)
{
	vector TempScreenLocation = ScreenLocation;
	for (char ch : Test)
	{
		if (ch == '\n')
		{
			TempScreenLocation.x = ScreenLocation.x;
			TempScreenLocation.y = TempScreenLocation.y + font->DiamensionsPerCharacter.y;
		}
		else
		{
			DataStructure::Rectangle rect = font->GetCharacter(ch);
			if (!lnobj.ShouldGotoNextLine(TempScreenLocation))
			{
				gfx->DrawTexture(TempScreenLocation, rect, font->MainText);
				TempScreenLocation.x = TempScreenLocation.x + font->DiamensionsPerCharacter.x;
			}
			else
			{
				TempScreenLocation.x = ScreenLocation.x;
				TempScreenLocation.y = TempScreenLocation.y + font->DiamensionsPerCharacter.y;
				gfx->DrawTexture(TempScreenLocation, rect, font->MainText);
				TempScreenLocation.x = TempScreenLocation.x + font->DiamensionsPerCharacter.x;
			}
		}
	}
}
