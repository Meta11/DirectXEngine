#pragma once
#include <d2d1.h>

class GameLevel;

class Renderer 
{
	ID2D1Factory* factory;
	ID2D1HwndRenderTarget* renderTarget; //the window sreen where graphics are being drawn.
	ID2D1SolidColorBrush* brush;
public:
	Renderer();
	~Renderer();

	bool initialize(HWND hwnd);
	bool shutdown();

	ID2D1RenderTarget* getRenderTarget() { return renderTarget; }
	void beginDraw() { renderTarget->BeginDraw(); }
	void endDraw() { renderTarget->EndDraw(); }
	void clearScreen(float r, float g, float b);
};