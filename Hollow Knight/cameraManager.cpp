#include "stdafx.h"
#include "cameraManager.h"



cameraManager::cameraManager()
	: _cameraInfo(NULL)
{
}


cameraManager::~cameraManager()
{
}

HRESULT cameraManager::init(int groundTotalWidth, int groundTotalHeight, int cameraWidth, int cameraHeight, float x, float y, float magnification)
{
	if (_cameraInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	_cameraInfo = new CAMERA_INFO;
	_cameraInfo->hMemDC = CreateCompatibleDC(hdc);
	_cameraInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, groundTotalWidth, groundTotalHeight);
	_cameraInfo->hOBit = (HBITMAP)SelectObject(_cameraInfo->hMemDC, _cameraInfo->hBit);
	_cameraInfo->width = cameraWidth / magnification;
	_cameraInfo->height = cameraHeight / magnification;
	_cameraInfo->groundWidth = groundTotalWidth;
	_cameraInfo->groundHeight = groundTotalHeight;
	_cameraInfo->magnification = magnification;

	if (_cameraInfo->hBit == NULL)
	{
		release();
		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

void cameraManager::release()
{
	// If you have image information
	if (_cameraInfo)
	{
		SelectObject(_cameraInfo->hMemDC, _cameraInfo->hOBit);
		DeleteObject(_cameraInfo->hBit);
		DeleteDC(_cameraInfo->hMemDC);

		SAFE_DELETE(_cameraInfo);
	}

}

void cameraManager::cameraMove(int focusX, int focusY)
{
	_cameraInfo->x = focusX - _cameraInfo->width / 2;
	_cameraInfo->y = focusY - _cameraInfo->height / 2;

	if (_cameraInfo->x < 0)
		_cameraInfo->x = 0;
	if (_cameraInfo->x + _cameraInfo->width > _cameraInfo->groundWidth)
		_cameraInfo->x = _cameraInfo->groundWidth - _cameraInfo->width;

	if (_cameraInfo->y < 0)
		_cameraInfo->y = 0;
	if (_cameraInfo->y + _cameraInfo->height > _cameraInfo->groundHeight)
		_cameraInfo->y = _cameraInfo->groundHeight - _cameraInfo->height;
}

void cameraManager::render(HDC hdc)
{
	GdiTransparentBlt(
		hdc,               // DC of the area to be copied
		0,                  // Coordinates X to be copied
		0,                  // Coordinates Y to be copied
		WINSIZEX,            // Size to be copied (horizontally)
		WINSIZEY,            // Size to be copied (vertical)
		_cameraInfo->hMemDC,            // DC to Copy
		_cameraInfo->x, _cameraInfo->y,      // Coordinates X, Y to be copied
		_cameraInfo->width,               // Size to copy
		_cameraInfo->height,            // Size to copy
		RGB(255, 0, 255));      // What colors will you subtract and import when you copy it?
}

void cameraManager::camerashiver(int focusX, int focusY)
{
	for (int i = 0; i < 1000; i++) {
		_cameraInfo->x = RANDOM->range(focusX - _cameraInfo->width / 2 -50, focusX - _cameraInfo->width / 2+50);
		_cameraInfo->y = RANDOM->range(focusY - _cameraInfo->height / 2-50, focusY - _cameraInfo->height / 2+50);
	}
	if (_cameraInfo->x < 0)
		for (int i = 0; i < 1000; i++) {
			_cameraInfo->x = RANDOM->range(0, 50);
		}
		
	if (_cameraInfo->x + _cameraInfo->width > _cameraInfo->groundWidth) {
		for (int i = 0; i < 1000; i++) {
			_cameraInfo->x = RANDOM->range(_cameraInfo->groundWidth - _cameraInfo->width - 50, _cameraInfo->groundWidth - _cameraInfo->width);
		}
	}
		

	if (_cameraInfo->y < 0)
		for (int i = 0; i < 1000; i++) {
			_cameraInfo->y = RANDOM->range(0, 50);
		}
	if (_cameraInfo->y + _cameraInfo->height > _cameraInfo->groundHeight) {
		_cameraInfo->y = _cameraInfo->groundHeight - _cameraInfo->height;
	}
		
}

