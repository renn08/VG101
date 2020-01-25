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
	return false;  //You need to modify here to get a stronger AI
}

bool game_t::moveValid(direction_t dir) {
	int mySize = snakeSelf.size();
	//int opSize = snakeOpp.size();
	//version 1
	// if(mySize>1){
	// 	if(snakeSelf.at(mySize -2)!=snakeSelf.back()+directionVec[dir]) return true;
	// 	else {return false;}
	// }
	// return true;

	//version2
	if(mySize>1){
		for(int i=2;i<=mySize;i++){
            if(snakeSelf.at(mySize -i)==snakeSelf.back()+directionVec[dir]) return false;
		}
		//return true;
	}
	return true;

	//version3
	
		// for(int i=1;i<=mySize;i++){
        //     if(snakeSelf.at(mySize -i)==snakeSelf.back()+directionVec[dir]) return false;
		// }
		// for(int j=1;j<=opSize;j++){
		// 	if(snakeOpp.at(mySize -j)==snakeSelf.back()+directionVec[dir]) return false;
		// }//return true;
	
	// return true;
	//int i=2;
	// if(mySize>1){
	// 	int p=1;
	// 	for(int i=2;i<=mySize;i++){
    //         if(snakeSelf.at(mySize -i)!=snakeSelf.back()+directionVec[dir]) p++;
	// 	}
	// 	if(p==(mySize+1)) return true;
	// }
	// if(mySize==1) return true;
	// return false; 
	
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
	//return direction_t(rand() % 4);
	return direction_t(rand() % 4);
}