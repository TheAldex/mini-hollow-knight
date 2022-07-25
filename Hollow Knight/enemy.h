#pragma once

enum BossState
{
	B_IDLE,
	B_JUMP,
	B_MOVE,
	B_ATK,
	B_DAMAGE,
	B_DOWN,
	B_DOWN2
};

enum BossSkill
{
	B_Basic_Attack,
	B_Air_attack,
	B_Strong_attack
};


class enemy 
{
protected:

	float posX,posY;				// Enemy x, y value
	float speedX;					// Speed X
	float speedY;					// Speed Y
	float jump_power;				// Jump Power
	float angle;					// Jump Angle
	int _count;						// Image Count
	int _index;						// Image Index
	int atk_count[2];
	int atk_index[2];
	int hp;


	float gravity;					// Gravity
	float gravity_accumulate;		// Gravitational accumulation


	RECT _rc;						// Body RC


	bool _max_jump;					// Jump Peak
	bool Right_and_left;			// Left Movement 
	bool isJump;					// Check if you're jumping
};
