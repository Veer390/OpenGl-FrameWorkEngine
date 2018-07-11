#include "Renderer.h"

RendererNS::Renderer::Renderer(Graphics* gfx)
	:
	gfx(gfx)
{}

//Moving The Renderer
RendererNS::Renderer::Renderer(Renderer && rhs)
	:
	gfx(rhs.gfx)
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
	Fonts.emplace_back(NewFont);
	auto end = Textures.end();
	end--;
	for (auto i = Textures.begin();; i++)
	{
		if (i == Textures.end())
			return c;
		c++;
	}
}

void RendererNS::Renderer::DrawTexture(int RendererValue,vector ScreenCoordinates)
{
	gfx->DrawTexture(ScreenCoordinates.x, ScreenCoordinates.y, Textures[RendererValue-1]);
}
