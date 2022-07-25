#pragma once
#include "gameNode.h"
// Going forward, the main game will only manage each scene
// Only the header file of the scenes is added here
#include "startScene.h"
#include "gameScene.h"
#include "imageLoader.h"
class mainGame : public gameNode
{
public:
	imageLoader* _imageLoader;

	HRESULT init();
	void release();
	void update();
	void render();
};