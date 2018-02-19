#pragma once
#include <d2d1.h>

class Graphics 
{
	ID2D1Factory* factory;
	ID2D1HwndRenderTarget* renderTarget; //the window sreen where graphics are being drawn.
	ID2D1SolidColorBrush* brush;
public:
	Graphics();
	~Graphics();

	bool initialize(HWND hwnd);
	bool shutdown();

	ID2D1RenderTarget* getRenderTarget() { return renderTarget; }
	void beginDraw() { renderTarget->BeginDraw(); }
	void endDraw() { renderTarget->EndDraw(); }

	void clearScreen(float r, float g, float b);
	void drawCircle(float x, float y, float radius, float r, float g, float b);
};