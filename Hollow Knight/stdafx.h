// stdafx.h : Use often, but not often
// Standard system include files or project-specific include files
// The include file that contains it
#pragma once
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#include <SDKDDKVer.h>


#define WIN32_LEAN_AND_MEAN             // Exclude rarely used content from the Windows headers
// Windows header file:
#include <Windows.h>
// C runtime header file:
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
// A C++ runtime header file:
#include <iostream>
using namespace std;

// Frequently used STLs
#include <string>
#include <vector>
#include <map>

//=============================================================
//	## Adding the header file created here ##
//=============================================================
#include "commonMacroFunction.h"
#include "input.h"
#include "random.h"
#include "imageManager.h"
#include "util.h"
#include "playerData.h"
#include "sceneManager.h"
#include "cameraManager.h"
using namespace _UTIL;

//=============================================================
//	## Adding a Singleton ##
//=============================================================
#define INPUT input::getSingleton() //세미콜론 찍으면 작동안함
#define RANDOM random::getSingleton()
#define IMAGEMANAGER imageManager::getSingleton()
#define PLAYERDATA playerData::getSingleton()
#define SCENEMANAGER sceneManager::getSingleton()
#define CAMERAMANAGER cameraManager::getSingleton()
//=============================================================
//	## Deepasentence ## (Initialize the window)
//=============================================================
#define WINNAME (LPTSTR)(TEXT(" 프로그래밍 22기 "))
#define WINSTARTX	-10
#define WINSTARTY	0
#define WINSIZEX		1920
#define WINSIZEY		1060
#define WINSTYLE		WS_CAPTION | WS_SYSMENU

//=============================================================
//	## Macro Actions ## (Dynamic de-allocated portion of a class)
//=============================================================
#define SAFE_DELETE(p)		{if(p) {delete (p); (p) = NULL;}}
#define SAFE_DELETE_ARRAY(p)	{if(p) {delete[] (p); (p) = NULL;}}

//=============================================================
//	## Global variables ##
//=============================================================
extern HINSTANCE	_hInstance;
extern HWND			_hWnd;
extern POINT		_ptMouse;