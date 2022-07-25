#pragma once
#include "singletonBase.h"
//=============================================================
//	## input ## Input Manager (keyboard, mouse buttons)
//=============================================================

#define KEYMAX 256

class input : public singletonBase <input>
{
private:
	bool _keyUp[KEYMAX];
	bool _keyDown[KEYMAX];

public:
	// Input Manager Initialization
	HRESULT init();
	// Turn off Input Manager
	void release();

	// Is the key still pressed?
	bool GetKey(int key);
	// Has the key been pressed only once?
	bool GetKeyDown(int key);
	// Has the key been pressed once?
	bool GetKeyUp(int key);
	// Toggle key? (Note that Unity does not have this feature)
	bool GetToggleKey(int key);

	input() {}
	~input() {}
};