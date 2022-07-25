#pragma once
#include "gameNode.h"

// Bullet structure
struct tagBullet
{
	image* bulletImage;
	RECT rc;
	float x, y;
	float fireX, fireY;
	float speed;
	float angle;
	float gravity;
	float radius;
	int count;
	bool fire;
};

//=============================================================
//	## bullet ## (Public Bullet)
//=============================================================
class bullet : public gameNode
{
private:
	// Vector declaration to hold bullet structs
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;
private:
	const char* _imageName;	// Bullet Image Name
	float _range;			// Bullet range
	int _bulletMax;			// Maximum number of bullets
	bool _isFrameImg;		// Is it a frame image?

public:
	HRESULT init(const char* imageName, int bulletMax, float range, bool isFrameImg = false);
	void release();
	void update();
	void render();
	
	// Bullet firing
	void fire(float x, float y, float angle, float speed);
	// Bullet Movement
	void move();

	// Bullet Removal
	void removeBullet(int index);

	// Get the Common Bullet Vector
	vector<tagBullet> getBullet() { return _vBullet; }
};

//=============================================================
//	## missile ## (missile[0] -> Pre-loaded like an array and fired a bullet)
//=============================================================
class missile : public gameNode
{
private:
	// Vector declaration to hold bullet structs
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

private:
	float _range;			// Bullet range
	int _bulletMax;			// Maximum number of bullets

public:
	HRESULT init(int bulletMax, float range);
	void release();
	void update();
	void render();

	// Bullet firing
	void fire(float x, float y);
	// Bullet Movement
	void move();

};

//=============================================================
//	## bomb ## (Shoot one shot like a bomb, create it, and automatically delete it)
//=============================================================
class bomb : public gameNode
{
private:
	// Vector declaration to hold bullet structs
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

private:
	float _range;			// Bullet Range
	int _bulletMax;			// Maximum number of bullets

public:
	HRESULT init(int bulletMax, float range);
	void release();
	void update();
	void render();

	// Bullet firing
	void fire(float x, float y);
	// Bullet Movement
	void move();

	// Bomb Removal
	void removeBomb(int index);

	// Get a bullet vector
	vector<tagBullet> getBullet() { return _vBullet; }


};