#include "stdafx.h"
#include "image.h"
image::image() : _imageInfo(NULL), _fileName(NULL), _blendImage(NULL)
{
}
image::~image()
{
}

// Initialize an empty bitmap
HRESULT image::init(int width, int height)
{
	// To prevent reinitialization, 
	// if the value of the image information is included,
	// release it and initialize it cleanly.
	if (_imageInfo != NULL) this->release();

	// Import DC
	HDC hdc = GetDC(_hWnd);

	// Creating and initializing a new image information structure
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	// Filename
	_fileName = NULL;
	// Transparent key color setting
	_isTrans = false;
	_transColor = RGB(0, 0, 0);

	// If you fail to obtain image information
	if (_imageInfo->hBit == NULL)
	{
		this->release();
		return E_FAIL;
	}

	// Turning off DC
	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

// Initialize with an image file
HRESULT image::init(const char * fileName, int width, int height, bool isTrans, COLORREF transColor)
{
	// To prevent reinitialization, 
	// if the value of the image information is included, 
	// release it and initialize it cleanly.
	if (_imageInfo != NULL) this->release();

	// Import DC
	HDC hdc = GetDC(_hWnd);

	// Creating and initializing a new image information structure
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	// Filename
	int len = strlen(fileName);
	_fileName = new char[len + 1];
	strcpy(_fileName, fileName);

	// Transparent key color setting
	_isTrans = isTrans;
	_transColor = transColor;

	// If you fail to obtain image information
	if (_imageInfo->hBit == NULL)
	{
		this->release();
		return E_FAIL;
	}

	// Turn off DC
	ReleaseDC(_hWnd, hdc);

	return S_OK;
}
HRESULT image::init(const char * fileName, float x, float y, int width, int height, bool isTrans, COLORREF transColor)
{
	// To prevent reinitialization, 
	// if the value of the image information is included, 
	// release it and initialize it cleanly.
	if (_imageInfo != NULL) this->release();

	// Import DC
	HDC hdc = GetDC(_hWnd);

	// Creating and initializing a new image information structure
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = x;
	_imageInfo->y = y;
	_imageInfo->width = width;
	_imageInfo->height = height;

	// Filename
	int len = strlen(fileName);
	_fileName = new char[len + 1];
	strcpy(_fileName, fileName);

	// Transparent key color setting
	_isTrans = isTrans;
	_transColor = transColor;

	// If you fail to obtain image information
	if (_imageInfo->hBit == NULL)
	{
		this->release();
		return E_FAIL;
	}

	// Turning off DC
	ReleaseDC(_hWnd, hdc);

	return S_OK;
}
HRESULT image::init(const char * fileName, int width, int height, int frameX, int frameY, bool isTrans, COLORREF transColor)
{
	// To prevent reinitialization, 
	// if the value of the image information is included, 
	// release it and initialize it cleanly.
	if (_imageInfo != NULL) this->release();

	// Import DC
	HDC hdc = GetDC(_hWnd);

	// Creating and initializing a new image information structure
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;
	_imageInfo->frameWidth = width / frameX;
	_imageInfo->frameHeight = height / frameY;

	// Filename
	int len = strlen(fileName);
	_fileName = new char[len + 1];
	strcpy(_fileName, fileName);

	// Transparent key color setting
	_isTrans = isTrans;
	_transColor = transColor;

	// If you fail to obtain image information
	if (_imageInfo->hBit == NULL)
	{
		this->release();
		return E_FAIL;
	}

	// Turn off DC
	ReleaseDC(_hWnd, hdc);

	return S_OK;
}
HRESULT image::init(const char * fileName, float x, float y, int width, int height, int frameX, int frameY, bool isTrans, COLORREF transColor)
{
	// To prevent reinitialization, 
	// if the value of the image information is included, 
	// release it and initialize it cleanly.
	if (_imageInfo != NULL) this->release();

	// Import DC
	HDC hdc = GetDC(_hWnd);

	// Creating and initializing a new image information structure
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = x;
	_imageInfo->y = y;
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;
	_imageInfo->frameWidth = width / frameX;
	_imageInfo->frameHeight = height / frameY;

	// Filename
	int len = strlen(fileName);
	_fileName = new char[len + 1];
	strcpy(_fileName, fileName);

	// Transparent key color setting
	_isTrans = isTrans;
	_transColor = transColor;

	// If you fail to obtain image information
	if (_imageInfo->hBit == NULL)
	{
		this->release();
		return E_FAIL;
	}

	// Turning off DC
	ReleaseDC(_hWnd, hdc);

	return S_OK;
}
// Initialize an alpha blend
HRESULT image::initForAlphaBlend()
{
	// Import DC
	HDC hdc = GetDC(_hWnd);

	// Initialize alpha blend options
	//BlendOp => Currently only available AC_SRC_OVER
	//BlendFlags => Just 0 stands, I don't know, I used it on the old OS
	//AlphaFormat => 0 when using 24bit, AC_SRC_ALPHA when using 32bit, but it doesn't make much difference, so we just have 0
	_blendFunc.BlendOp = AC_SRC_OVER;
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	//0 ~ 255 => Original color at 255
	//_blendFunc.SourceConstantAlpha = 255;

	// To Create and Initialize a New Alpha Blend Image Information Structure
	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_FILE;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, _imageInfo->width, _imageInfo->height);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;

	// Turning off DC
	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

// Cancellation
void image::release()
{
	// If image information remains, turn it off
	if (_imageInfo)
	{
		// Delete an image
		SelectObject(_imageInfo->hMemDC, _imageInfo->hOBit);
		DeleteObject(_imageInfo->hBit);
		DeleteDC(_imageInfo->hMemDC);

		// Delete a pointer
		SAFE_DELETE(_imageInfo);
		SAFE_DELETE_ARRAY(_fileName);

		// Transparent colorkey initialization
		_isTrans = false;
		_transColor = RGB(0, 0, 0);
	}

	// If alpha blend image information remains, turn it off
	if (_blendImage)
	{
		// Delete an image
		SelectObject(_blendImage->hMemDC, _blendImage->hOBit);
		DeleteObject(_blendImage->hBit);
		DeleteDC(_blendImage->hMemDC);
		
		// Delete a pointer
		SAFE_DELETE(_blendImage);
	}
}

// render (output to the coordinates I want, normally we attach the image to the LT coordinate of the RECT)
void image::render(HDC hdc, int destX, int destY)
{
	if (_isTrans) // Get rid of background color and output
	{
		//GdiTransparentBlt : A function that copies a bitmap image except for certain colors
		GdiTransparentBlt(
			hdc,				// DC in the place to copy
			destX,				// Start coordinates to copy X
			destY,				// Start coordinates to copy Y
			_imageInfo->width,	// Image landscape size to copy
			_imageInfo->height,	// Image portrait size to copy
			_imageInfo->hMemDC,	// DC to be copied
			0, 0,				// The starting point of the destination to be copied
			_imageInfo->width,	// Copy area horizontal size
			_imageInfo->height,	// Copy area height
			_transColor);		// Colors to exclude when copying (usually using magenta colors)
	}
	else // Output as it is from the original image
	{
		//BitBlt : A function that allows high-speed copying between regions between DCs
		// Memory DC => Copy DC to Screen
		BitBlt(hdc, destX, destY, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

// Render (cut and paste the image to the coordinates you want)
void image::render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight)
{
	if (_isTrans) // Get rid of background color and exit
	{
		//GdiTransparentBlt : A function that copies a bitmap image except for certain colors
		GdiTransparentBlt(
			hdc,				// DC in the place to copy
			destX,				// Start coordinates to copy X
			destY,				// Start coordinates to copy Y
			sourWidth,			// Image landscape size to copy
			sourHeight,			// Image portrait size to copy
			_imageInfo->hMemDC,	// To be copied DC
			sourX, sourY,		// The starting point of the destination to be copied
			sourWidth,			// Copy area horizontal size
			sourHeight,			// Copy area height
			_transColor);		// Colors to exclude when copying (usually using magenta colors)
	}
	else // Output as it is from the original image
	{
		//BitBlt : A function that allows high-speed copying between regions between DCs
		//Memory DC => Copy DC to Screen
		BitBlt(hdc, destX, destY, sourWidth, sourHeight,
			_imageInfo->hMemDC, sourX, sourY, SRCCOPY);
	}
}

void image::alphaRender(HDC hdc, BYTE alpha)
{
	// Initialize the alpha blend so that it can be used
	if (!_blendImage) this->initForAlphaBlend();
	// Initialize alpha values
	_blendFunc.SourceConstantAlpha = alpha;

	if (_isTrans) // Get rid of background color and output
	{
		//1. Copy the contents of the current screenDC to the => blend image
		//2. ImageMemory Remove the background color of DC and copy it to the => blended image
		//3. Copy the blend image to the DC screen

		//1
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, 0, 0, SRCCOPY);

		//2
		//GdiTransparentBlt : A function that copies a bitmap image except for certain colors
		GdiTransparentBlt(
			_blendImage->hMemDC,	// DC in the place to copy
			0,						// Start coordinates to copy X
			0,						// Start coordinates to copy Y
			_imageInfo->width,		// Image landscape size to copy
			_imageInfo->height,		// Image portrait size to copy
			_imageInfo->hMemDC,		// DC to be copied 
			0, 0,					// The starting point of the destination to be copied
			_imageInfo->width,		// Copy area horizontal size
			_imageInfo->height,		// Copy area height
			_transColor);			// Colors to exclude when copying (usually using magenta colors)
	
		//3
		GdiAlphaBlend(hdc, 0, 0, _imageInfo->width, _imageInfo->height,
			_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
	else // Output as it is from the original image
	{
		GdiAlphaBlend(hdc, 0, 0, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
}

void image::alphaRender(HDC hdc, int destX, int destY, BYTE alpha)
{

	if (!_blendImage) this->initForAlphaBlend();
	_blendFunc.SourceConstantAlpha = alpha;

	if (_isTrans)
	{
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, destX, destY, SRCCOPY);

		GdiTransparentBlt(
			_blendImage->hMemDC,	
			0,						
			0,						
			_imageInfo->width,		
			_imageInfo->height,		
			_imageInfo->hMemDC,		
			0, 0,					
			_imageInfo->width,		
			_imageInfo->height,		
			_transColor);

		GdiAlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height,
			_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
	else
	{
		GdiAlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
}

void image::alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha)
{
	if (!_blendImage) this->initForAlphaBlend();
	_blendFunc.SourceConstantAlpha = alpha;

	if (_isTrans)
	{
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, destX, destY, SRCCOPY);

		GdiTransparentBlt(
			_blendImage->hMemDC,	
			0,						
			0,						
			sourWidth,				
			sourHeight,				
			_imageInfo->hMemDC,		
			sourX, sourY,			
			sourWidth,				
			sourHeight,				
			_transColor);	

		GdiAlphaBlend(hdc, destX, destY, sourWidth, sourHeight,
			_blendImage->hMemDC, 0, 0, sourWidth, sourHeight, _blendFunc);
	}
	else
	{
		GdiAlphaBlend(hdc, destX, destY, sourWidth, sourHeight,
			_imageInfo->hMemDC, sourX, sourY, sourWidth, sourHeight, _blendFunc);
	}
}

void image::frameRender(HDC hdc, int destX, int destY)
{
	if (_isTrans)
	{
		GdiTransparentBlt(
			hdc,						
			destX,						
			destY,						
			_imageInfo->frameWidth,		
			_imageInfo->frameHeight,	
			_imageInfo->hMemDC,			
			_imageInfo->currentFrameX * _imageInfo->frameWidth,		// The starting point of the destination to be copied
			_imageInfo->currentFrameY * _imageInfo->frameHeight,	// The starting point of the destination to be copied			
			_imageInfo->frameWidth,	
			_imageInfo->frameHeight,	
			_transColor);	
	}
	else
	{
		BitBlt(hdc, destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC, 
			_imageInfo->currentFrameX * _imageInfo->frameWidth, 
			_imageInfo->currentFrameY * _imageInfo->frameHeight, SRCCOPY);
	}
}

void image::frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY)
{
	// Image exception handling
	_imageInfo->currentFrameX = currentFrameX;
	_imageInfo->currentFrameY = currentFrameY;
	if (currentFrameX > _imageInfo->maxFrameX)
	{
		_imageInfo->currentFrameX = _imageInfo->maxFrameX;
	}
	if (currentFrameY > _imageInfo->maxFrameY)
	{
		_imageInfo->currentFrameY = _imageInfo->maxFrameX;
	}

	if (_isTrans)
	{
		GdiTransparentBlt(
			hdc,						
			destX,						
			destY,						
			_imageInfo->frameWidth,		
			_imageInfo->frameHeight,	
			_imageInfo->hMemDC,			
			_imageInfo->currentFrameX * _imageInfo->frameWidth,		
			_imageInfo->currentFrameY * _imageInfo->frameHeight,				
			_imageInfo->frameWidth,		
			_imageInfo->frameHeight,	
			_transColor);			
	}
	else
	{
		BitBlt(hdc, destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight, SRCCOPY);
	}
}

// Looprender
void image::loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY)
{
	//An offset is typically the displacement of an object from the beginning of an object to a given element or a certain point within the same object
		// offset means a value that differs slightly from a particular value, or the difference itself (a correction value based on the difference)
		// Calibrating if the offset value is negative
	if (offsetX < 0) offsetX = _imageInfo->width + (offsetX % _imageInfo->width);
	if (offsetY < 0) offsetY = _imageInfo->height + (offsetY % _imageInfo->height);

	// Drawing Area Settings
	RECT rcSour;
	int sourWidth;
	int sourHeight;

	// DC area to be drawn (screen size)
	RECT rcDest;

	// The entire area to be drawn
	int drawAreaX = drawArea->left;
	int drawAreaY = drawArea->top;
	int drawAreaW = drawArea->right - drawArea->left;
	int drawAreaH = drawArea->bottom - drawArea->top;

	// Vertical loop area
	for (int y = 0; y < drawAreaH; y += sourHeight)
	{
		// Calculate the height of the source area
		rcSour.top = (y + offsetY) % _imageInfo->height;
		rcSour.bottom = _imageInfo->height;
		sourHeight = rcSour.bottom - rcSour.top;

		// If the source area has crossed the drawing screen (when it is out of the screen)
		if (y + sourHeight > drawAreaH)
		{
			// Raise the bottom value by the value of the picture that has been crossed
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}

		// Area to be drawn
		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;

		// Horizontal loop area
		for (int x = 0; x < drawAreaW; x += sourWidth)
		{
			// Calculate the height of the source area
			rcSour.left = (x + offsetX) % _imageInfo->width;
			rcSour.right = _imageInfo->width;
			sourWidth = rcSour.right - rcSour.left;

			// If the source area has crossed the drawing screen (when it is out of the screen)
			if (x + sourWidth > drawAreaW)
			{
				// Raise the bottom value by the value of the picture that has been crossed
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}

			// Area to be drawn
			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;

			// Draw (Normal Render - Cut and paste the image)
			render(hdc, rcDest.left, rcDest.top, rcSour.left, rcSour.top, sourWidth, sourHeight);
		}
	}
}

void image::loopAlphaRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha)
{
	// Calibrate if the offset value is negative
	if (offsetX < 0) offsetX = _imageInfo->width + (offsetX % _imageInfo->width);
	if (offsetY < 0) offsetY = _imageInfo->height + (offsetY % _imageInfo->height);

	// Drawing Area Settings
	RECT rcSour;
	int sourWidth;
	int sourHeight;

	// DC area to be drawn (screen size)
	RECT rcDest;

	// The entire area to be drawn
	int drawAreaX = drawArea->left;
	int drawAreaY = drawArea->top;
	int drawAreaW = drawArea->right - drawArea->left;
	int drawAreaH = drawArea->bottom - drawArea->top;

	// Vertical loop area
	for (int y = 0; y < drawAreaH; y += sourHeight)
	{
		rcSour.top = (y + offsetY) % _imageInfo->height;
		rcSour.bottom = _imageInfo->height;
		sourHeight = rcSour.bottom - rcSour.top;

		if (y + sourHeight > drawAreaH)
		{
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}

		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;

		// Horizontal loop area
		for (int x = 0; x < drawAreaW; x += sourWidth)
		{
			rcSour.left = (x + offsetX) % _imageInfo->width;
			rcSour.right = _imageInfo->width;
			sourWidth = rcSour.right - rcSour.left;

			if (x + sourWidth > drawAreaW)
			{
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}

			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;

			// Draw (Alpharender - Cut and paste image)
			alphaRender(hdc, rcDest.left, rcDest.top, rcSour.left, rcSour.top, sourWidth, sourHeight, alpha);
		}
	}
}
