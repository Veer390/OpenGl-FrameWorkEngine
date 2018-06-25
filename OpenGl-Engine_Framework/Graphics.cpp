#include "Graphics.h"

void Graphics::PutPixel(int x, int y, Color c)
{
	glColor3f(c.GetNormaliedR(), c.GetNormaliedG(), c.GetNormaliedB());
	glBegin(GL_POINTS);
	glVertex2f(x / Graphics::ScreenWidth, y / Graphics::ScreenHeight);
	glEnd();
}
