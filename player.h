#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <deque>

using namespace sf;

class Player{
public:
	void move();
	void addLength();
	Player();

	std::deque<RectangleShape> squaresDeque;
	float xDirection;
	float yDirection;

private:
	RectangleShape initSquare(bool initialSquare);

};