#include "Level.h"

#pragma once
class Food
{
	int x_, y_;
public:
	Food(Level& lvl);
	void spawn(Level& lvl);
	void draw(Level& lvl);
	int getX();
	int getY();
};

