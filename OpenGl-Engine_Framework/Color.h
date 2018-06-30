#pragma once
#include<iostream>


class Color {

	friend class Graphics;

public:
	Color() = default;
	Color(int r, int g, int b)
		:
		r(r),
		g(g),
		b(b)
	{}

private:
	int r=0;
	int g=0;
	int b=0;

public:
	inline int GetR()
	{
		return r;
	}
	inline int GetG()
	{
		return g;
	}
	inline int GetB()
	{
		return b;
	}


	void SetRGB(int R, int G, int B)
	{
		r = R;
		g = G;
		b = B;
	}

private:
	inline float GetNormaliedR()
	{
		return r/255;
	}
	inline float GetNormaliedG()
	{
		return g/255;
	}
	inline float GetNormaliedB()
	{
		return b/255;
	}

	
};