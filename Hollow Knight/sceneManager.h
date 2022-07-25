#pragma once
#include "singletonBase.h"

//=============================================================
//	## sceneManager ##
//=============================================================

// Because children who inherit singletons are made static
// If you try to use a regular class game node, it will explode

// Gamenode Class Forward Declaration
class gameNode;

class sceneManager : public singletonBase <sceneManager>
{
private:
	typedef map<string, gameNode*> mSceneList;
	typedef map<string, gameNode*>::iterator miSceneList;

private:	
	//map<string, gameNode*> _mSceneList;			// A map to hold each scene (screen)
	mSceneList _mSceneList;			// A map to hold each scene (screen)
	gameNode* _currentScene;		// Current Scene

public:
	HRESULT init();
	void release();
	void update();
	void render();

	// Add a scene
	gameNode* addScene(string sceneName, gameNode* scene);
	// Change the scene
	HRESULT loadScene(string sceneName);

	sceneManager() : _currentScene(NULL) {}
	~sceneManager() {}
};

