#include "Player.h"
#include "AIE.h"



Player::Player()
{
}

void Player::SetSize(float a_width, float a_height)
		{
			width = a_width;
			height = a_height;
		}

void Player::SetPosition(float a_x, float a_y)
{
	x = a_x;
	y = a_y;

}

void Player::SetMovementKeys(unsigned int a_moveLeft, unsigned int a_moveRight)
{
	moveLeftKey = a_moveLeft;
	moveRightKey = a_moveRight;
}


void Player::SetMovementExtreme(unsigned int a_leftExtreme, unsigned int a_rightExtreme)
{
	leftMovementExtreme = a_leftExtreme;
	rightMovementExtreme = a_rightExtreme;
}

void Player::Move(float a_timeStep, float a_speed)
{
	if (IsKeyDown(moveLeftKey))
	{
		x -= a_timeStep * a_speed;
		if (x < (leftMovementExtreme + width*.5f))
		{
			x = (leftMovementExtreme + width*.5f);
		}
	}
	if (IsKeyDown(moveRightKey))
	{
		x += a_timeStep * a_speed;
		if (x >(rightMovementExtreme - width*.5f))
		{
			x = (rightMovementExtreme - width*.5f);
		}
	}
	MoveSprite(spriteID, x, y);
}


Player::~Player()
{
}
