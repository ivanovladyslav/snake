#include "stdafx.h"
#include <conio.h>
#include "Level.h"
#include "Snake.h"

Level level(20, 20);
Snake snake(level);

void Input();

int main() {
	Food food(level);	
	while (snake.isAlive()) {
		level.drawLevel();
		Input();
		snake.move();
		snake.checkCollision(food, level);
		snake.draw(level);
		food.draw(level);
		std::cout << "SCORE: " << snake.getLength();
	}
	system("pause");
}
	
void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			snake.setDirection(LEFT);
			break;
		case 'd':
			snake.setDirection(RIGHT);
			break;
		case 'w':
			snake.setDirection(FORWARD);
			break;
		case 's':
			snake.setDirection(BACK);
			break;
		}
	}
}
