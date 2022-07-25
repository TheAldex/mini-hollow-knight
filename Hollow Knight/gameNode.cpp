#include "stdafx.h"
#include "gameNode.h"

//=============================================================
//	## Initialize ## init()
//=============================================================
HRESULT gameNode::init()
{
	_hdc = GetDC(_hWnd);				// HDC Get
	SetTimer(_hWnd, 1, 10, NULL);		// Timer initialization
	INPUT->init();						// Input Manager Initialization
	RANDOM->init();						// Random Manager Initialization
	IMAGEMANAGER->init();				// Initialize the Image Manager
	PLAYERDATA->init();					// Initialize player data
	SCENEMANAGER->init();				// Initialize the Scene Manager

	return S_OK;
}

//=============================================================
//	## Cancellation ## release()
//=============================================================
void gameNode::release()
{
	// Turn off the timer
	KillTimer(_hWnd, 1);
	// Turn off Input Manager
	INPUT->release();
	INPUT->releaseSingleton();
	// Turn off Random Manager
	RANDOM->release();
	RANDOM->releaseSingleton();
	// Turn off Image Manager
	IMAGEMANAGER->release();
	IMAGEMANAGER->releaseSingleton();
	// Turn off player data
	PLAYERDATA->release();
	PLAYERDATA->releaseSingleton();
	// Turn off Scene Manager
	SCENEMANAGER->release();
	SCENEMANAGER->releaseSingleton();

	//HDC cancellation
	ReleaseDC(_hWnd, _hdc);
}

//=============================================================
//	## Update ## update()
//=============================================================
void gameNode::update()
{
	// Refresh (don't use it later after you create a high-performance timer)
	// Do not use after double buffering (true => false)
	InvalidateRect(_hWnd, NULL, FALSE);
}

//=============================================================
//	## Render ## render()
//=============================================================
void gameNode::render()
{
}

//=============================================================
//	## Main Procedure ## MainProc()
//=============================================================
LRESULT gameNode::MainProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_TIMER:
		this->update();
		break;
	case WM_PAINT:
		this->render();
		break;
	case WM_MOUSEMOVE:
		_ptMouse.x = LOWORD(lParam);
		_ptMouse.y = HIWORD(lParam);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, message, wParam, lParam));
}