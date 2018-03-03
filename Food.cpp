#include "stdafx.h"
#include "Food.h"
#include "Level.h"

Food::Food(Level& lvl) {
	x_ = 1 + rand() % (lvl.getWidth() - 2);
	y_ = 1 + rand() % (lvl.getHeight() - 2);
	lvl.setMap(x_, y_, 3);
}

void Food::spawn(Level& lvl) {
	//srand(time(NULL));
	x_ = 1 + rand() % (lvl.getWidth() - 2);
	y_ = 1 + rand() % (lvl.getHeight() - 2);
	if (lvl.getMap(x_, y_) != 2) 
		lvl.setMap(x_, y_, 3);
    else 
		spawn(lvl);
	
}
void Food::draw(Level& lvl) { lvl.setMap(x_, y_, 3); }
int Food::getX() { return x_; }
int Food::getY() { return y_; }