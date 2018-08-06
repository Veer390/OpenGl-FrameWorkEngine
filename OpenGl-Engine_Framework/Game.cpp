#include "Game.h"
#include <Windows.h>

int c = 0;
void DrawFrameNumber()
{
	std::cout << c << std::endl;
	c++;
}

int counter = 1;
void Game::incrementColor(Color & col)
{
	if (col.GetR() >= 255)
	{
		Forward = false;
	}
	if (col.GetR() <= 0)
	{
		Forward = true;
	}
	if(Forward==true)
	{
		col.SetRGB(col.GetR() + 1, col.GetG() + 1, col.GetB() + 1);
	}
	if(Forward==false)
	{
		col.SetRGB(col.GetR() -1 , col.GetG() - 1, col.GetB() - 1);
	}
}

void Game::main()
{
	if(glfwWindowShouldClose(gfx.WindowReference))
	{Playable = false;}
	else
	{
		ComposeFrame();
		DrawFrame();
	}
}

void Game::ComposeFrame()
{
	//gfx.PutPixel(20, 20, { 255,255,255 });
	//gfx.DrawTexture(20, 30, AnimTest);
	int o = MainRenderer.SetNewFont(fnt);
	MainRenderer.DrawFontAutoLine(o, { 135,135 }, "Asish ");
	texVec.push_back(&AnimTest);
	Anim.SetTextureArray(texVec);
	SetRectangleAndFrameNumber();
	//texVec[0] = &AnimTest;
	//SetRectangleAndFrameNumber();

	//gfx.DrawTexture({20,30},)
	//int n=MainRenderer.SetNewTexture(Dib);
	//int m = MainRenderer.SetNewTexture(Dib);
	//MainRenderer.DrawTexture(m, { 30,20 });
	//MainRenderer.DrawTexture(n, { 50,60 });

	//int p = MainRenderer.SetNewTexture(Dib);
	//MainRenderer.DrawTexture(p, { 20,30 });
	//gfx.print({ 20,30 }, " 8Ph!9Qi\n:Rj#; Sk$<Tl %= Um\n & >Vn'?Wo(@Xp)AYq*BZr+C[s,\nD\t-E]u.F^v/G_w0H`x1\nIay2Jbz3Kc{4Ld|5\nMe}6Nf~7Og", &fnt);
	//gfx.print({ 20,30 }, "k",&fnt);
	//int a = MainRenderer.SetNewTexture(Dib);
	//MainRenderer.DrawTexture(a, { 20,30 });


	//MainRenderer.DrawFont(o, { 30,20 }, "Aba");
	//MainRenderer.DrawFontAutoLine(o, { 30,20 }, "Emperor \n   Emhyr");
	//DataStructure::Rectangle rec({ 0,0 }, { 204,0 }, { 0,247 }, { 204,247 });
	//gfx.DrawTextureWithAlpha(30, 20, Dib);

	//gfx.print({ 20,30 }, "Empyrean Veer \nEmhyr", &fnt);
	MainRenderer.DrawANimation(Anim, { 20,30 });
	//gfx.PutPixel(250, 250, Color(255, 255, 255));
	texVec.clear();
}

void Game::DrawFrame()
{
	
	//DrawFrameNumber();

}

void Game::SetRectangleAndFrameNumber()
{
	
	int c = 0;
	static vector TR_S = { 0,0 };
	static vector TL_S = { 64,0 };
	static vector BL_S = { 0,64 };
	static vector BR_S = { 64,64 };
	vector TR = { 0,0 };
	vector TL = { 64,0 };
	vector BL = { 0,64 };
	vector BR = { 64,64 };

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//REal
			//DataStructure::Rectangle re(TL, TR, BL, BR);

			//Alternative
			DataStructure::Rectangle re(TR, TL, BL, BR);
			//TestAnimationBoxAndTextureNumber[i*j].RectangleBoxPayload = re;
			//TestAnimationBoxAndTextureNumber[i*j].TextureNumber = 0;

			//Alternative
			TestAnimationBoxAndTextureNumber.push_back(DataStructure::RectangleAndTextureIndex_Animation(re, 0));
			
			//Standrad
			TR.y = TR.y + 64;
			TL.y = TL.y + 64;
			BR.y = BR.y + 64;
			BL.y = BL.y + 64;
		}
		TR.y = TR_S.y;
		TL.y = TL_S.y;
		BR.y = BR_S.y;
		BL.y = BL_S.y;
        
		TR.x = TR.x + 64;
		TL.x = TL.x + 64;
		BL.x = BL.x + 64;
		BR.x = BR.x + 64;
		
	}
	
	Anim.SetAnimation(TestAnimationBoxAndTextureNumber);
	TestAnimationBoxAndTextureNumber.clear();
}


