#pragma once
//=============================================================
//	## image ## (Will continue to be updated in the future)
//=============================================================

class image
{
public:
	enum IMAGE_LOAD_KIND
	{
		LOAD_EMPTY,		// Loading Empty Bitmaps
		LOAD_FILE		// Loading as a file
	};

	typedef struct tagImage
	{
		HDC hMemDC;			// Memory DC
		HBITMAP hBit;		// Bitmap
		HBITMAP hOBit;		// Old bitmap
		float x;			// Image x coordinates
		float y;			// Image y coordinate
		int width;			// Image Width
		int height;			// Image Vertical Length
		int currentFrameX;	// Current Frame X
		int currentFrameY;	// Current Frame Y
		int maxFrameX;		// Maximum number of frames X
		int maxFrameY;		// Maximum number of frames Y
		int frameWidth;		// Horizontal Frame length
		int frameHeight;	// Vertical Frame length
		BYTE loadType;		// Image Load Type
		tagImage()
		{
			hMemDC = NULL;
			hBit = NULL;
			hOBit = NULL;
			x = 0;
			y = 0;
			width = 0;
			height = 0;
			currentFrameX = 0;
			currentFrameY = 0;
			maxFrameX = 0;
			maxFrameY = 0;
			frameWidth = 0;
			frameHeight = 0;
			loadType = LOAD_EMPTY;
		}
	}IMAGE_INFO, *LPIMAGE_INFO;

private:
	LPIMAGE_INFO	_imageInfo;		// About images
	char*			_fileName;		// Image filename
	bool			_isTrans;		// Are you going to get rid of the background color?
	COLORREF		_transColor;	// RGB to get rid of background color (magenta = RGB(255, 0, 255))

	LPIMAGE_INFO	_blendImage;	// Alpha Blend image
	BLENDFUNCTION	_blendFunc;		// Alpha Blend function

public:
	image();
	~image();

	// Initialize an empty bitmap
	HRESULT init(int width, int height);
	// Initialize with an image file
	HRESULT init(const char* fileName, int width, int height, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
	HRESULT init(const char* fileName, float x, float y, int width, int height, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
	// Initialize with a frame image file
	HRESULT init(const char* fileName, int width, int height, int frameX, int frameY, bool isTrans = true, COLORREF transColor = RGB(255, 0, 255));
	HRESULT init(const char* fileName, float x, float y, int width, int height, int frameX, int frameY, bool isTrans = true, COLORREF transColor = RGB(255, 0, 255));
	
	// Initialize an alpha blend
	HRESULT initForAlphaBlend();


	// Cancellation
	void release();

	// Render (output to the coordinates I want, normally we attach the image to the LT coordinate of the RECT)
	void render(HDC hdc, int destX = 0, int destY = 0);
	// Render (cut and paste the image to the coordinates you want)
	void render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);
	// Alpha Render (makes the image as transparent as the alpha value)
	void alphaRender(HDC hdc, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);
	// Framerender
	void frameRender(HDC hdc, int destX, int destY);
	void frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	// Looprender
	void loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);
	void loopAlphaRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha);

	// Get DC
	inline HDC getMemDC() { return _imageInfo->hMemDC; }

	// Image x, y coordinates
	inline float getX() { return _imageInfo->x; }
	inline float getY() { return _imageInfo->y; }
	inline void setX(float x) { _imageInfo->x = x; }
	inline void setY(float y) { _imageInfo->y = y; }
	// Image Center Coordinates
	inline void setCenter(float x, float y)
	{
		_imageInfo->x = x + (_imageInfo->width / 2);
		_imageInfo->y = y + (_imageInfo->height / 2);
	}
	// Get images horizontally and vertically
	inline int getWidth() { return _imageInfo->width; }
	inline int getHeight() { return _imageInfo->height; }
	// Bounding box (collision recte)
	inline RECT boundingBox()
	{
		RECT rc = { (int)_imageInfo->x, (int)_imageInfo->y,
		(int)_imageInfo->x + _imageInfo->width,
		(int)_imageInfo->y + _imageInfo->height };
		return rc;
	}
	inline RECT boudingBoxWithFrame()
	{
		RECT rc = { (int)_imageInfo->x, (int)_imageInfo->y,
		(int)_imageInfo->x + _imageInfo->frameWidth,
		(int)_imageInfo->y + _imageInfo->frameHeight };
		return rc;
	}
	// Frame X, Y
	inline int getFrameX() { return _imageInfo->currentFrameX; }
	inline int getFrameY() { return _imageInfo->currentFrameY; }
	inline void setFrameX(int frameX)
	{
		_imageInfo->currentFrameX = frameX;
		if (frameX > _imageInfo->maxFrameX)
		{
			_imageInfo->currentFrameX = _imageInfo->maxFrameX;
		}
	}
	inline void setFrameY(int frameY)
	{
		_imageInfo->currentFrameY = frameY;
		if (frameY > _imageInfo->maxFrameY)
		{
			_imageInfo->currentFrameY = _imageInfo->maxFrameY;
		}
	}
	// Get horizontal frame, vertical length
	inline int getFrameWidth() { return _imageInfo->frameWidth; }
	inline int getFrameHeight() { return _imageInfo->frameHeight; }
	// Get Max Frames
	inline int getMaxFrameX() { return _imageInfo->maxFrameX; }
	inline int getMaxFrameY() { return _imageInfo->maxFrameY; }

};

