#include "stdafx.h"
#include <Windows.h>
#include "Snake.h"

Snake::Snake(Level& lvl) {
	pos p;
	p.x = 10;
	p.y = 10;
	body_.push_back(p);
	direction_ = FORWARD;
}
void Snake::draw(Level& lvl) {
	unsigned int i = 0;
	lvl.setMap(xprev_, yprev_, 0);
	while (i < body_.size()) {
		xprev_ = body_[i].x;
		yprev_ = body_[i].y;
		lvl.setMap(body_[i].x,body_[i].y, 2);
		i++;
	}
	Sleep(150);
}
void Snake::move() {
	int i = body_.size(),
		j = 1;
	pos tmp, tmp2;
	switch (direction_) {
	case FORWARD: {
		tmp = body_[0];
		while (j < i) {
			if (j % 2 == 0) {
				tmp = body_[j];
				body_[j] = tmp2;
			} else {
				tmp2 = body_[j];
				body_[j] = tmp;
			}
			++j;
		}
		body_[0].x--;
		break;
	}
	case LEFT: {
		tmp = body_[0];
		while (j < i) {
			if (j % 2 == 0)	{
				tmp = body_[j];
				body_[j] = tmp2;
			} else {
				tmp2 = body_[j];
				body_[j] = tmp;
			}
			++j;
		}
		body_[0].y--;
		break;
	}
	case RIGHT: {
		tmp = body_[0];
		while (j < i) {
			if (j % 2 == 0) {
				tmp = body_[j];
				body_[j] = tmp2;
			} else {
				tmp2 = body_[j];
				body_[j] = tmp;
			}
			++j;
		}
		body_[0].y++;
		break;
	}
	case BACK: {
		tmp = body_[0];
		while (j < i) {
			if (j % 2 == 0) {
				tmp = body_[j];
				body_[j] = tmp2;
			} else {
				tmp2 = body_[j];
				body_[j] = tmp;
			}
			++j;
		}
		body_[0].x++;
		break;
	}
	default:
		break;
	}
	if (add_) {
		body_.push_back(tmp);
		add_ = false;
	}
}
void Snake::checkCollision(Food& fd, Level& lvl) {
	if (body_[0].x == fd.getX() && body_[0].y == fd.getY())	{
		add_ = true;
		fd.spawn(lvl);
	}
	if (lvl.getMap(body_[0].x,body_[0].y)==1) {
		alive_ = false;
	}
	for (int i = 1;i < body_.size(); i++) {
		if (body_[i].x == body_[0].x && body_[i].y == body_[0].y)
			alive_ = false;
	}
}
void Snake::setDirection(int dir) {	
	if ((direction_ == 0 && dir != 3) ||
		(direction_ == 3 && dir != 0) ||
		(direction_ == 2 && dir != 1) ||
		(direction_ == 1 && dir != 2))
	direction_ = dir;
}
bool Snake::isAlive() { return alive_; }
int Snake::getLength() { return body_.size(); }