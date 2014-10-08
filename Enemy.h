#pragma once
class Enemy
{
public:
	unsigned int spriteID;

	float x;
	float y;
	float speed;
	float width;
	float height;
	void SetSize(float a_width, float a_height);
	void SetPosition(float a_x, float a_y);
	void Move(float );

	Enemy();
	~Enemy();
};

