#pragma once
#include "singletonBase.h"
#include "image.h"
//=============================================================
//	## imageManager ##
//=============================================================

class imageManager : public singletonBase <imageManager>
{
private:
	typedef map<string, image*> mapImageList;			// Image list created from maps
	typedef map<string, image*>::iterator mapImageIter;	// Iterator of an imageslist created from a map

private:
	//map<string, image*> _mImageList;
	mapImageList _mImageList;	// STL map to hold the actual image class

public:
	// Initialize the image manager
	HRESULT init();
	// Turn off Image Manager
	void release();

	// Initialize an empty bitmap
	image* addImage(string strKey, int width, int height);
	// Initialize with an image file
	image* addImage(string strKey, const char* fileName, int width, int height, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
	image* addImage(string strKey, const char* fileName, float x, float y, int width, int height, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
	// Initialize with a frame image file
	image* addFrameImage(string strKey, const char* fileName, int width, int height, int frameX, int frameY, bool isTrans = true, COLORREF transColor = RGB(255, 0, 255));
	image* addFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, bool isTrans = true, COLORREF transColor = RGB(255, 0, 255));

	// Find by image key value
	image* findImage(string strKey);
	// Delete by image key
	BOOL deleteImage(string strKey);
	// Delete all images
	BOOL deleteAll();

//=============================================================
//	## General Render ##
//=============================================================
	void render(string strKey, HDC hdc, int destX = 0, int destY = 0);
	void render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

//=============================================================
//	## Alfa Render ##
//=============================================================
	void alphaRender(string strKey, HDC hdc, BYTE alpha);
	void alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);

//=============================================================
//	## Framerender ##
//=============================================================
	void frameRender(string strKey, HDC hdc, int destX, int destY);
	void frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

//=============================================================
//	## Looprender ##
//=============================================================
	void loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);
	void loopAlphaRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha);


	imageManager() {}
	~imageManager() {}
};