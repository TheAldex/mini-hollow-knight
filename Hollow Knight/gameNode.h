#pragma once
#include "image.h"

// Put back buffer images in Image Manager
static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZEX, WINSIZEY); 

class gameNode
{
private:
	HDC _hdc;				//HDC

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	// Obtaining a back buffer image
	image* getBackBuffer() { return _backBuffer; }
	// Get HDC Screen
	HDC getHDC() { return _hdc; }
	// Obtaining DC Memory
	HDC getMemDC() { return _backBuffer->getMemDC(); }

	LRESULT CALLBACK MainProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	gameNode() {}
	virtual ~gameNode() {}
};