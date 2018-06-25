#pragma once
#include <iostream>
#include <vector>

class Keyboard
{

public:
	static bool keys[1024];
public:
	Keyboard()
	{
		for (auto& i : keys)
		{
			i = false;
		}
	}
	
};