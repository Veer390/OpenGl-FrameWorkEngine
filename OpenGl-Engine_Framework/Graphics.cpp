#include "Graphics.h"

/*const float min = -2;
const float max = 4;
float normalize(float input)
{
	float average = (min + max) / 2;
	float range = (max - min) / 2;
	float normalized_x = (input - average) / range;
	return normalized_x;
}*/
int width = Graphics::ScreenWidth / 2;
int height = Graphics::ScreenHeight / 2;

struct Coordinates
{
	float x;
	float y;
};
inline Coordinates TransformToNewCoordinates(Coordinates point)
{
	return { point.x - width,point.y + height };
}
Coordinates TransformToAndNormalizeCoordinates(Coordinates point)
{	
	point = TransformToNewCoordinates(point);
	return{ point.x / width, point.y / height };
}
/*//Component can be 'x' or 'y'
float normalize(int input,char Component)
{
	if (Component == 'x')
	{
		if (input == Graphics::ScreenWidth / 2)
			return 0.0f;
		if (input < Graphics::ScreenWidth / 2)
			return -1.0f*input / Graphics::ScreenWidth;
		if (input > Graphics::ScreenWidth/2)
			return 1.0f*input / Graphics::ScreenWidth;
	}

	if (Component == 'y')
	{
		if (input == Graphics::ScreenHeight / 2)
			return 1.0f;
		if (input < Graphics::ScreenHeight / 2)
			return -1.0f*input / Graphics::ScreenHeight;
		if (input > Graphics::ScreenHeight / 2)
			return 1.0f*input / Graphics::ScreenHeight;
	}
}*/

void Graphics::PutPixel(int x, int y, Color c)
{
	y = -1 * y;
	Coordinates point =TransformToAndNormalizeCoordinates({ float(x),float(y) });
	glColor3f(c.GetNormaliedR(), c.GetNormaliedG(), c.GetNormaliedB());
	glBegin(GL_POINTS);
	glVertex2f(point.x,point.y);
	//glVertex2f(x / Graphics::ScreenWidth, y / Graphics::ScreenHeight);
	glEnd();
	
}

//Draws A Texture onto The Screen At A Given location
void Graphics::DrawTexture(int x, int y,Texture tex)
{
	const int width = tex.GetWidth();
	const int height = tex.GetHeight();

	for (int sy = 0; sy < height; sy++)
	{
		for (int sx = 0; sx < width; sx++)
		{
			PutPixel(x + sx, y + sy, tex.GetPixel(sx, sy));
		}
	}
}

void Graphics::DrawTexture(vector ScreenCoordinates, DataStructure::Rectangle TextureCoordinates, Texture tex)
{
	int Startx = TextureCoordinates.TL.x;
	int Stopx = TextureCoordinates.TR.x;
	int Starty = TextureCoordinates.TL.y;
	int Stopy = TextureCoordinates.BL.y;

	for (int i = Startx,sx = 0; i < Stopx; i++,sx++)
	{
		for (int j = Starty,sy=0; j < Stopy; j++,sy++)
		{
			PutPixel(ScreenCoordinates.x + sx, ScreenCoordinates.y + sy, tex.GetPixel(i, j));
		}
	}
}

void Graphics::DrawTextureWithAlpha(int x, int y, Texture tex)
{
	const int width = tex.GetWidth();
	const int height = tex.GetHeight();

	for (int sy = 0; sy < height; sy++)
	{
		for (int sx = 0; sx < width; sx++)
		{
			if (tex.GetPixel(sx, sy) != tex.GetAlphaChannel())
			{
				PutPixel(x + sx, y + sy, tex.GetPixel(sx, sy));
			}
		}
	}
}

void Graphics::DrawTextureWithAlpha(vector ScreenCoordinates, DataStructure::Rectangle TextureCoordinates, Texture tex)
{
	int Startx = TextureCoordinates.TL.x;
	int Stopx = TextureCoordinates.TR.x;
	int Starty = TextureCoordinates.TL.y;
	int Stopy = TextureCoordinates.BL.y;

	for (int i = Startx, sx = 0; i < Stopx; i++, sx++)
	{
		for (int j = Starty, sy = 0; j < Stopy; j++, sy++)
		{
			if (tex.GetPixel(sx, sy) != tex.GetAlphaChannel())
			{
				PutPixel(ScreenCoordinates.x + sx, ScreenCoordinates.y + sy, tex.GetPixel(i, j));
			}
		}
	}
}

void Graphics::print(vector ScreenLocation,std::string Test, Font * font)
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
			DrawTexture(TempScreenLocation, rect, font->MainText);
			TempScreenLocation.x = TempScreenLocation.x + font->DiamensionsPerCharacter.x;
		}
	}
}



