#include "interface.h"
#include <cstdlib>
#include <ctime>

/*The following is a robot that moves randomly. 
You can use this piece of code if you completely
don't know how to write lab 8*/

game_t::game_t(vector2D birthSelf, vector2D birthOpp, vector2D food, bool first) {
	snakeSelf.push_back(birthSelf);
	snakeOpp.push_back(birthOpp);
	this->food = food;
	this->first = first;
	srand((int)time(0));
}

bool game_t::moveCross(direction_t dir) {
	return false;  //You need to modify here to get a stronger AI
}

bool game_t::moveValid(direction_t dir) {
	return false;  //You need to modify here to get a stronger AI
}

void game_t::setFood(vector2D _food) {
	food = _food;
}

vector2D game_t::getFood() const { return food; }

int game_t::selfMove(direction_t dir) {
	vector2D head = snakeSelf.back() + directionVec[dir];
	snakeSelf.push_back(head);
	if (head != food) {
		snakeSelf.erase(snakeSelf.begin());
	}
	return 0;
}

int game_t::oppMove(direction_t dir) {
	vector2D head = snakeOpp.back() + directionVec[dir];
	snakeOpp.push_back(head);
	if (head != food) {
		snakeOpp.erase(snakeOpp.begin());
	}
	return 0;
}

direction_t game_t::judge() {
	return direction_t(rand() % 4); 
	//Here the snake move towards an arbitary direction
	//You need to modify this part to make your AI stronger
}