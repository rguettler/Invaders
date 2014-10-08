#include "Enemy.h"
#include "AIE.h"

Enemy::Enemy()
{
}
void Enemy::SetSize(float a_width, float a_height)
{
	width = a_width;
	height = a_height;
}
void Enemy::SetPosition(float a_x, float a_y)
{
	x = a_x;
	y = a_y;

}

Enemy::~Enemy()
{
}
