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




//PUTPIXEL ENTIRELY WRONG FIX THE NORMALIZATION PART