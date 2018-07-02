#pragma once
#include <iostream>
#include <cmath>

template<typename T>
struct Vector
{
	T x;
	T y;

	Vector<T> operator+(Vector<T> rhs)
	{
		Vector<T> temp;
		temp.x = this->x + rhs.x;
		temp.y = this->y + rhs.y;
		return temp;
	}
	typedef Vector<int> vector;
};