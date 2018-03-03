#include "stdafx.h"
#include "Level.h"
#include <windows.h> 
#include <iostream>
using namespace std;

Level::Level(int sizeX, int sizeY) {
	width_ = sizeX;
	height_ = sizeY;
	map_ = new int* [height_];
	for (int i = 0; i < height_; i++) map_[i] = new int[width_];
	for (int i = 0; i < height_; i++) {
		for (int j = 0; j < width_; j++) {
			if (j == 0 || j == width_ - 1 || i == 0 || i == height_ - 1) 
				map_[i][j] = 1;
			else
				map_[i][j] = 0;
		}
	}
}

void Level::drawLevel() {
	system("cls");
	for (int i = 0; i < height_; i++) {
		for (int j = 0; j < width_; j++) {
			if (map_[i][j] == 1) {
				cout << "#";
			}
			else if (map_[i][j] == 2) {
				cout << "X";
			}
			else if (map_[i][j] == 3) {
				cout << "o"; 
			} else {
				cout << " ";
			}
		}
		cout << endl;
	}	
}

void Level::setMap(int xx, int yy, int value) { map_[xx][yy] = value; }
int Level::getMap(int xx, int yy) { return map_[xx][yy]; }
int Level::getWidth() { return width_; }
int Level::getHeight() { return height_; }