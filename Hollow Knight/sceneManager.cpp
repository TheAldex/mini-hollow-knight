#include "stdafx.h"
#include "sceneManager.h"
#include "gameNode.h"

HRESULT sceneManager::init()
{
	return S_OK;
}

void sceneManager::release()
{
	/*
	// The Seminal Way
	miSceneList iter = _mSceneList.begin();
	for (; iter != _mSceneList.end();)
	{
		if (iter->second != NULL)
		{
			// Delete it here
			if (iter->second == _currentScene) iter->second->release();
			SAFE_DELETE(iter->second);
			iter = _mSceneList.erase(iter);
		}
		else
		{
			++iter;
		}
	}
	// Clearing the entire map
	_mSceneList.clear();
	*/

	//C++ Classical grammar
	//for(auto scene in _mSceneList) => Not available now
	for (auto scene : _mSceneList)
	{
		scene.second->release();
		SAFE_DELETE(scene.second);
	}

	//int a = 10;
	//auto b = 100.5f;
	//var c = 10; // From Unity
}

void sceneManager::update()
{
	// If the current scene exists, update the scene
	if (_currentScene) _currentScene->update();
}

void sceneManager::render()
{
	// If the current scene exists, print it out
	if (_currentScene) _currentScene->render();
}

gameNode * sceneManager::addScene(string sceneName, gameNode * scene)
{
	// If there is no scene, just return null
	if (!scene) return NULL;

	// If you have a scene, return it and put it on the map
	_mSceneList.insert(make_pair(sceneName, scene));
	//_mSceneList.insert(pair<string, gameNode*>(sceneName, scene));

	return scene;
}

HRESULT sceneManager::loadScene(string sceneName)
{
	miSceneList find = _mSceneList.find(sceneName);

	// If you can't find it, E_FAIL
	if (find == _mSceneList.end()) return E_FAIL;

	// If the scene you want to change is the same as the current scene, E_FAIL
	if (find->second == _currentScene) return E_FAIL;

	// Once you've gotten here, it's not a big deal, so let's change the scene
	if (SUCCEEDED(find->second->init()))
	{
		_currentScene = find->second;
		return S_OK;
	}

	return E_NOTIMPL;
}
