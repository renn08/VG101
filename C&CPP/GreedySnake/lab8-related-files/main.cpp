#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

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
	vector2D head=snakeSelf.back();
	if((food.x()-head.x)>0){
       return direction_t(2);
	}
	else if((food.x()-head.x)<0){
		return direction_t(0);
	}
	if((food.y()-head.y)>0){
		return direction_t(1);
	}
	else if((food.y()-head.y)<0){
		return direction_t(3);
	}
	//Here the snake move towards an arbitary direction
	//You need to modify this part to make your AI stronger
}

int main(int, char **) {
    int first, foodx, foody, selfx, selfy, oppx, oppy;
    cin >> first >> foodx >> foody >> selfx >> selfy >> oppx >> oppy;

    game_t game({selfx, selfy}, {oppx, oppy}, {foodx, foody}, first == 1);

    int status = 0;

    if (first) {
        direction_t move = game.judge();
        cout << int(move) << endl;
        game.selfMove(move);

        cin >> foodx >> foody;
        game.setFood({foodx, foody});
    }

    while (status == 0) {
        int oppMove;
        cin >> oppMove;
        status = game.oppMove(direction_t(oppMove));

        cin >> foodx >> foody;
        game.setFood({foodx, foody});

        if (status != 0) break;

        direction_t move = game.judge();
        cout << int(move) << endl;
        status = game.selfMove(move);

        cin >> foodx >> foody;
        game.setFood({foodx, foody});
    }
	return 0;
}
