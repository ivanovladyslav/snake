#pragma once
class Level
{
private:
	int** map_;
	int width_, height_;
public:
	Level(int, int);
	void drawLevel();
	void setMap(int, int, int value);
	int getMap(int, int);
	int getWidth();
	int getHeight();
};

