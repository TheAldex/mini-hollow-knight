#pragma once
#include "gameNode.h"

#define CAMSIZEX 600
#define CAMSIZEY 400

class camera : public gameNode
{
private:
	image* _img;		// Background image
	RECT _rcCam;		// Camera Lect

public:
	HRESULT init();
	void release();
	void update();
	void render();

	camera() {}
	~camera() {}
};

