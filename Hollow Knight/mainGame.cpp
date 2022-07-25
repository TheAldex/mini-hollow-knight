#include "stdafx.h"
#include "mainGame.h"

//=============================================================
//	## Initialization ## init()
//=============================================================

HRESULT mainGame::init()
{
	gameNode::init();
	
	/*Going forward, the main game will only manage each scene*/
	/*Add each scene here and set the current scene*/
	_imageLoader = new imageLoader;
	_imageLoader->init();
	/*Add Scene*/
	SCENEMANAGER->addScene("start screen", new startScene);
	SCENEMANAGER->addScene("Game Screen", new gameScene);

	/*Current Scene*/
	SCENEMANAGER->loadScene("start screen");

	return S_OK;
}

//=============================================================
//	## Cancellation ## release()
//=============================================================
void mainGame::release()
{
	gameNode::release();
}

//=============================================================
//	## Update ## update()
//=============================================================
void mainGame::update()
{
	gameNode::update();
	
	//Scene Manager Updates
	SCENEMANAGER->update();
}

//=============================================================
//	## Render ## render()
//=============================================================
void mainGame::render()
{
	// White blank bitmap (this is just left in the render)
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	// Scene Manager Render
	SCENEMANAGER->render();
	
	// Draw the contents of the backbuffer to the screen DC 
	// (leave this in the render as well)
	this->getBackBuffer()->render(getHDC());
}
