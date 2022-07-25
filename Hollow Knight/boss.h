#pragma once
#include "enemy.h"

class player;
class boss : public enemy
{
public:

	RECT collisionRc;
	vector<RECT> _b_head;
	vector<RECT> collisionRc_2;

	player* _p;

	BossState _state;

	BossSkill _skill;

	HRESULT init();
	void release();
	void update();
	void render();
	RECT LeftRc;
	RECT RightRc;

	void animation();			// Animation	
	void boss_state();			// Boss Status
	void boss_state_move();		// Boss state-specific behavior
	void boss_jump();			// Boss Jump
	void boss_gravity();		// Boss gravity calculation
	void right_left();			// Boss direction
	void count_set(int count,int index);
	int getHp() { return bossHp; }
	void setHp(int num) {
		bossHp -= num;
	}

	void BossIsDown();			// Boss Down
	void BossDown();
	void setPlayer(player* p){
		_p = p;
	}
	// Get player values
	float player_getAngle();		// Jump near the Flyer

	void boss_atk_collision();
	BossState get_state() { return _state; }
	void set_state(BossState _bs) {
		_state = _bs;
	};
private:
	int pattern_count;			// Pattern Count
	int rendom_atk;				// Attack by taking random values
	int jump_atk_count;			// Pause after attacking
	int bossHp;
	int finerHp;
	bool isbossHp;				// Physical Strength
	int gravity1;
	bool isbossHpCount;			// Is boss
	float angle1;
	bool isHp;
	bool jumping;				// Jump
	bool jump_start;			// Preparing to jump
	bool isBasic_atk;			// During the basic attack
	bool atk_two;				// Basic Attack Second Motion
	bool isDown2;
	bool isDown3;
	bool isDown4;
	bool isDown5;

};

