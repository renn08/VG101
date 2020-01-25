#include "interface.h"
#include <cstdlib>
#include <ctime>

game_t::game_t(vector2D birthSelf, vector2D birthOpp, vector2D food, bool first) {
	snakeSelf.push_back(birthSelf);
	snakeOpp.push_back(birthOpp);
	this->food = food;
	this->first = first;
	srand((int)time(0));
}

bool game_t::moveCross(direction_t dir) {
    return false;  
}

bool game_t::moveValid(direction_t dir) {
	int mySize = snakeSelf.size();
	int opSize = snakeOpp.size();
	vector2D current=snakeSelf.back()+directionVec[dir];
	if(current.x()<0||current.x()>49||current.y()<0||current.y()>49) return false;
	if(mySize>1){
		for(int i=2;i<=mySize;i++){
            if(snakeSelf.at(mySize -i)==snakeSelf.back()+directionVec[dir]) return false;
		}
        if(opSize>1){
		for(int j=2;j<=opSize;j++){
		    if(snakeOpp.at(opSize -j)==snakeSelf.back()+directionVec[dir]) return false;
		 }
      }
	  }
     return true;
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
	vector2D head2=snakeSelf.back();
	if((food.x()-head2.x())>0){
	   if(moveValid(direction_t(2))) return direction_t(2);
	}
	if(((food.x()-head2.x())<0)){
		if(moveValid(direction_t(0))) return direction_t(0);
	}
	if((food.y()-head2.y())>0){
		if(moveValid(direction_t(3))) return direction_t(3);
	}
    if(((food.y()-head2.y())<0)){
		if(moveValid(direction_t(1))) return direction_t(1);
	}
	if(moveValid(direction_t(1))) return direction_t(1);
	if(moveValid(direction_t(0))) return direction_t(0);
	if(moveValid(direction_t(2))) return direction_t(2);
	if(moveValid(direction_t(3))) return direction_t(3);
	return direction_t(rand() % 4);
}