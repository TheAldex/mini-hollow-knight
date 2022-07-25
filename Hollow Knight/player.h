#pragma once
#include "gameNode.h"
#define MAXSPEEDX 5
#define MAXSPEEDY 5
#define JUMPMAX 25
// Player Status


enum Player_state
{
	IDLE,
	DOWN,
	JUMP,
	MOVE,
	ATK,
	SKILL,
	DAMAGE
	
};
// Skills-related
enum Skill
{
	Basic_Attack,
	Air_attack,
	Javelin_throw
};

// HP image
struct HpImage
{
	image* hp;
	int frameX;
	int frameY;

};
// Player Gauge Bar
struct SkillGauge
{
	image* Gauge;
	int posX;
	int posY;

};
// Javelin
struct tagSphear
{
	float x, y;
	float speed;
	float angle;
};

class boss;
class player : public gameNode
{

private:	
	float speedX;					// X Speed
	float speedY;					// Y Speed
	float posX;						// Player Cordinates
	float posY;						// Player Cordinates
	float jump_power;				// Jump Power

	int _count;						// Image Count
	int _index;						// Image Index

	int _atk_count;					// Attack Image Count
	int _atk_index;					// Attack Image Index
	int _skill_count;				// Adjust skill time
	int angle;						// Flying after a collision
	int sphear_speed;				// Javelin Speed

	RECT _rc_sphear;				// Player skill javelin
	RECT _rc_collision;				// Crash Rack
	vector<RECT> atkMotion;
	vector<RECT> _atkRc;			// Attack Raid
	vector<RECT> sh_Rc;				// Javelin conflicts

	float gravity1;
	int count_gravity;				// Conflict Handling
	int timeHp;

	float gravity;					// Gravity
	float gravity_accumulate;		// Gravitational accumulation

	vector<tagSphear*> _vsphear;		// Spear
	vector<HpImage*> my_hp;				// Player Stamina
	vector<SkillGauge*> skill_gauge;	// Skill Gauge

	Player_state _state;			// Player Status

	RECT _rc;						// Player Rack
	Skill _p_skill;					// Player skill types

	boss* _b;

	int inuincibility_count;		// Invincible time
	bool inuincibility;				// Invincibility

	int imageaipcount;
	bool imageaip;

	int m_count;
	int m_index;


	bool motion;
	bool iscoillision;				// Boss Bob Clash
	bool isSphear_stert;			// Javelin
	bool _max_jump;					// Jump Peak
	bool Right_and_left;			// Left Movement 
	bool isJump;					// Check if you're jumping
	bool isJavelin;					// Inspect if you are throwing and receiving spears
	bool isHp;
	bool isGauge;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	float getX() { return _rc.left /*(_rc.left + _rc.right) / 2; */; }
	float getY() { return _rc.top /* (_rc.top + _rc.bottom) / 2*/; }
	RECT playerRc() { return _rc; }

	void setCollsion(bool t) { iscoillision = t; }
	void player_Move_left();	// Player Left
	void player_Move_up();		// Player Jump
	void player_Move_right();	// Player Right
	void player_Move_down();	// Player Down
	void player_atk();			// Player Attack
	void player_skill();		// Player Skill
	void player_sphear_move(float angle);	// Move the javalin
	void player_state();		// Player Status 
	void player_gravity();		// Player Gravity
	vector<RECT>  player_atk_Rc() { return _atkRc; }
	void setBossInfo(boss* b) { _b = b; }

	bool getinuincibility() {
		return inuincibility;
	}
	void setinuincibility(bool r) {
		inuincibility = r;
	}

	void morion_animation();
	Skill getSkill() {return _p_skill;}
	Player_state getState() { return _state; };
	void Player_Get_Hp();
	void collision();			// Boss and Collision Inspection
	void boss_collision();
	void boss_body_collision();
	void hp_management();		// Player Fitness Management and Lander
	void animation();			// Animation	
	void sphear_move();			// Flying the spear
	int My_Hp_Get();
	player() {}
	~player() {}
};

