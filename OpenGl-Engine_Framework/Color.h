#pragma once
#include<iostream>


class Color {

	friend class Graphics;

public:
	Color() = delete;
	Color(int r, int g, int b)
		:
		r(r),
		g(g),
		b(b)
	{}

private:
	int r;
	int g;
	int b;

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