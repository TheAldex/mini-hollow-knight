//=============================================================
//	## Write a header file ##
//=============================================================
#include "stdafx.h"
#include "mainGame.h"

//=============================================================
//	## Write global variables ##
//=============================================================
HWND		_hWnd;
HINSTANCE	_hInstance;
POINT		_ptMouse = { 0, 0 };
// Main Game Class Declaration
mainGame* _mg;


//=============================================================
//	## Function forward declaration ##
//=============================================================
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowSize(int x, int y, int width, int height);

//=============================================================
//	## Windows Main Functions ##
//=============================================================
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// Main Game Class Dynamic Assignment
	_mg = new mainGame;

	// Put the instance in a global variable
	_hInstance = hInstance;

	//WNDCLASS : A structure for storing information in a window

	// Declare and initialize window structs
	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;										// Class Extra Memory
	wndClass.cbWndExtra = 0;										// Windows Extra Memory
	wndClass.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);	// Background
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					// Mouse cursor
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// Icon
	wndClass.hInstance = hInstance;									// Instance
	wndClass.lpfnWndProc = (WNDPROC)WndProc;						// Windows Procedure
	wndClass.lpszClassName = WINNAME;								// Class Name
	wndClass.lpszMenuName = NULL;									// Menu Name
	wndClass.style = CS_HREDRAW | CS_VREDRAW;						// Window style

	// Register a Windows Class
	RegisterClass(&wndClass);

	// Creating a window
	_hWnd = CreateWindow(
		WINNAME,				// Name of the window class
		WINNAME,				// Windows Titlebar Name
		WINSTYLE,				// Window style
		WINSTARTX,				// Window screen coordinates X
		WINSTARTY,				// Window screen coordinates Y
		WINSIZEX,				// Windows screen landscape size
		WINSIZEY,				// Windows screen landscape size
		NULL,					// Parent Window
		(HMENU)NULL,			// Menu handle
		hInstance,				// Specifying Instances
		NULL					// When you create a window and a child window, you specify it, otherwise it is NULL
	);

	// Accurately size the Liant area
	setWindowSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);

	// Windows shows on screen
	ShowWindow(_hWnd, nCmdShow);

	// Exit the main game class as soon as initialization fails
	if (FAILED(_mg->init()))
	{
		return 0;
	}

	//MSG : A structure for storing message information issued by the operating system
	MSG message;
	// Message loops
	//GetMessage : A function that pauses until a message can be pulled out
	//PeekMessage : A function that is returned even if there is no message

	/*
	// Use it later for gaming
	while (true)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT) break;
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
	}
	*/

	// For general programming use
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	// Disable the main game class
	_mg->release();

	return message.wParam;
}



// Windows Procedure: The section where the message is communicated to the operating system and coded
//hWnd : Identify which window is the message
//message : Message identification number
//wParam : unsigned int: Convey the state of the mouse button, keyboard modifier keys
//lParam : unsigned long: Pass mouse click coordinates (x,y)
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// The main game class is run by you as a main procedure
	return _mg->MainProc(hWnd, message, wParam, lParam);
}

//=============================================================
//	## Resize the window ## (it will size the client area correctly)
//=============================================================
void setWindowSize(int x, int y, int width, int height)
{
	RECT rc = { 0, 0, width, height };

	// Actual window resizing
	AdjustWindowRect(&rc, WINSTYLE, false);

	// Setting the Windows Client Size with the above Rect Information
	SetWindowPos(_hWnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top),
		SWP_NOZORDER | SWP_NOMOVE);
}