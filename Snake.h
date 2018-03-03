#include "Food.h"
#include "Level.h"
#include <vector>

#pragma once
#define FORWARD 0
#define LEFT 1
#define RIGHT 2
#define BACK 3
class Snake
{
private:
	typedef struct s_pos {
		int x;
		int y;
	} pos;
	std::vector <pos> body_;
	int x_, y_,
		xprev_, yprev_,
		direction_;
	bool add_ = false, 
		 alive_ = true;
public:
	Snake(Level&);
	void move();
	void draw(Level&);
	void setDirection(int);
	void checkCollision(Food&, Level&);
	bool isAlive();
	int getLength();
};

