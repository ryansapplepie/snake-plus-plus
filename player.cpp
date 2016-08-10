#include "player.h"

void Player::move(){

	RectangleShape tail = squaresDeque.at(squaresDeque.size()-1);
	Vector2f headPosition = squaresDeque.at(0).getPosition();
	squaresDeque.pop_back();

	if (xDirection == 500)
		tail.setPosition(headPosition.x + 45, headPosition.y);
	else if (xDirection == -500)
		tail.setPosition(headPosition.x - 45, headPosition.y);
	else if (yDirection == 500)
		tail.setPosition(headPosition.x, headPosition.y + 45);
	else if (yDirection == -500)
		tail.setPosition(headPosition.x, headPosition.y - 45);

	squaresDeque.push_front(tail);
	
}


RectangleShape Player::initSquare(bool initialSquare){
	RectangleShape shape;
	shape.setSize(Vector2f(30,30));
	shape.setFillColor(Color::White);
	shape.setOutlineThickness(5);
	shape.setOutlineColor(Color(250, 150, 100));
	if (!initialSquare)
	{
		Vector2f previousSquarePosition = squaresDeque.at(squaresDeque.size() - 1).getPosition();
		if (xDirection == 500) //right direction
			shape.setPosition(previousSquarePosition.x - 45, previousSquarePosition.y);
		else if (xDirection == -500) //left direction
			shape.setPosition(previousSquarePosition.x + 45, previousSquarePosition.y);
		else if (yDirection == 500) //down direction
			shape.setPosition(previousSquarePosition.x, previousSquarePosition.y + 45);
		else if (yDirection == -500) //up direction
			shape.setPosition(previousSquarePosition.x, previousSquarePosition.y - 45);
		
	}else
		shape.setPosition(100, 100);

	return shape;
}

Player::Player(){ squaresDeque.push_back(initSquare(true));	}

void Player::addLength(){ squaresDeque.push_back(initSquare(false)); }
