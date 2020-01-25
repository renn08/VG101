/*
 * The interface of VG101 LAB8 Greedy Snake
 */

#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <cmath>
#include <queue>
#include <vector>

#define BOARD_X 50
#define BOARD_Y 50

typedef enum {LEFT, UP, RIGHT, DOWN} direction_t;//枚举型，LEFT=0, UP=1, RIGHT=2, DOWN=3

class vector2D {
private:
	int _x, _y;
public:
	vector2D(int x=0, int y=0) : _x(x), _y(y) {}; // List constructor
	vector2D(vector2D const &cpy) : _x(cpy.x()), _y(cpy.y()) {}; // Copy constructor//把cpy的_x,_y抄过来到自己的private里
	// Getter & Setter
	int x() const { return _x; }//获取位置
	void x(int x) { _x = x; }//设置private里的坐标
	int y() const { return _y; }
	void y(int y) { _y = y; }
	// Operator overload
	vector2D operator +(const vector2D& another) const { return {_x+another.x(), _y+another.y()}; }
	vector2D operator -() const { return {-_x, -_y}; }
	vector2D operator -(const vector2D& another) const { return {_x-another.x(), _y-another.y()}; }
	vector2D operator *(int num) const { return {_x*num, _y*num}; }
	vector2D operator /(int num) const { return {_x/num, _y/num}; }
	vector2D &operator =(vector2D const&another) { _x=another.x(); _y=another.y(); return *this;} // Deep copy//直接复制？
	bool operator ==(const vector2D& another) const { return ((_x == another.x()) && (_y == another.y())); }
	bool operator !=(const vector2D& another) const { return ((_x != another.x()) || (_y != another.y())); }
	// Other functions
	int length() const { return int(sqrt(_x*_x + _y*_y)); }//到左上角的距离
	vector2D normalize() const { return *this/length(); }//不知道干啥的
};

const vector2D directionVec[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

/* The class that you need to implement for the game, the functions may be useful to you
 */
class game_t {
private:
	std::vector<vector2D> snakeSelf, snakeOpp;
	vector2D food;
	int round{};
	bool first;
public:
	/* EFFECTS: Initialize the game board
	 * MODIFIES: this
	 */
	game_t(vector2D birthSelf, vector2D birthOpp, vector2D food, bool first);

	/* EFFECTS: Set the position of food
	 * MODIFIES: this->food
	 */
	void setFood(vector2D food);

	/* EFFECTS: Get the position of food
	 */
	vector2D getFood() const;

	/* EFFECTS: Make a move with corresponding direction
	 * MODIFIES: this->snakeSelf, this->food, this->round
	 * RETURNS: 0 - Game continues
	 			1 - You win
				2 - Opponent win
	 */
	int selfMove(direction_t dir);

	/* EFFECTS: Update the opponent's position
	 * MODIFIES: this->snakeOpp, this->food, this->round
	 * RETURNS: 0 - Game continues
	 			1 - You win
				2 - Opponent win
	 */
	int oppMove(direction_t dir);

	/* EFFECTS: Tell if the move is invalid *Only to snakeSelf
	 */
	bool moveValid(direction_t dir);

	/* EFFECTS: Tell if the move will cause boundary cross
	 */
	bool moveCross(direction_t dir);

	/* EFFECTS: Determine the best direction to go at the current situation
	 */
	direction_t judge();
};

#endif
