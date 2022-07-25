#pragma once
#include "singletonBase.h"

class cameraManager : public singletonBase<cameraManager>
{
public:
	typedef struct tagCameraInfo
	{
		HDC		hMemDC;		// Memory DC
		HBITMAP hBit;		// Bitmap
		HBITMAP hOBit;		// Old bitmap
		float	x;			// Camera X-coordinate (left)
		float	y;			// Camera Y-coordinate (top)
		int		width;		// Landscape size (camera)
		int		height;		// Portrait size (camera)

		int		groundWidth;	// Background total horizontal size
		int		groundHeight;	// Background total vertical size

		float	magnification;

		tagCameraInfo()
		{
			hMemDC = NULL;
			hBit = NULL;
			hOBit = NULL;
			x = 0;
			y = 0;
			width = 0;
			height = 0;
			groundWidth = 0;
			groundHeight = 0;
			magnification = 1;
		}
	}CAMERA_INFO, *LPCAMERA_INFO;

private:
	LPCAMERA_INFO	_cameraInfo;		// Camera Information Structure
	LPCAMERA_INFO   _tempInfo;
	BLENDFUNCTION   _blendfuntion;
public:
	cameraManager();
	~cameraManager();

	HRESULT init(int groundTotalWidth, int groundTotalHeight, int cameraWidth, int cameraHeight, float x = 0, float y = 0, float magnification = 1);
	void release();
	void cameraMove(int focusX, int focusY);
	void render(HDC hdc);
	void camerashiver(int focusX, int focusY);

	inline HDC getMemDC() { return _cameraInfo->hMemDC; }
	inline float getX() { return _cameraInfo->x; }
	inline float getY() { return _cameraInfo->y; }
	inline void setMagnification(float mag) { _cameraInfo->magnification = mag; }
};