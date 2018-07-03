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
	bool operator!=(Color rhs)
	{
		if (this->r == rhs.r
			&& this->g == rhs.g
			&& this->b == rhs.b)
		{
			return false;
		}
		else
			return true;
	}
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
		float R = r;
		return R/255;
	}
	inline float GetNormaliedG()
	{
		float G = g;
		return G/255;
	}
	inline float GetNormaliedB()
	{
		float B = b;
		return B/255;
	}

	
};