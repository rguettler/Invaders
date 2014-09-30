#pragma once
class Player
{
public:
		unsigned int spriteID;
		
		float speed;
		float width;
		float height;
		float x ;
		float y ;
		unsigned int moveLeftKey;
		unsigned int moveRightKey;
		unsigned int leftMovementExtreme;
		unsigned int rightMovementExtreme;
		void SetMovementExtreme(unsigned int a_leftExtreme, unsigned int a_rightExtreme);
		void SetMovementKeys(unsigned int a_moveLeft, unsigned int a_moveRight);
		void Move(float a_timeStep, float a_speed);
		void SetPosition(float a_x, float a_y);
		void SetSize(float a_width, float a_height);

	Player();
	~Player();
};

