#include "Graphics.h"

Graphics::Graphics()
{
	factory = nullptr;
	renderTarget = nullptr;
	brush = nullptr;
}

Graphics::~Graphics()
{
	if (renderTarget != nullptr)
		renderTarget->Release();
	if (factory != nullptr)
		factory->Release();
}

bool Graphics::initialize(HWND hwnd)
{
	//create factory allows to create several things, such as the renderTarget
	HRESULT res = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);
	if (res != S_OK)
		return false;
	//now we create the render target. We need the size of the window.
	RECT rect;
	GetClientRect(hwnd, &rect);

	res = factory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(hwnd, D2D1::SizeU(rect.right, rect.bottom)),
		&renderTarget);
	if (res != S_OK)
		return false;

	return true;
}

bool Graphics::shutdown()
{
	if (renderTarget != nullptr)
		renderTarget->Release();
	if (factory != nullptr)
		factory->Release();
	return true;
}

void Graphics::clearScreen(float r, float g, float b)
{
	renderTarget->Clear(D2D1::ColorF(r, g, b));
}

void Graphics::drawCircle(float x, float y, float radius, float r, float g, float b)
{
	renderTarget->CreateSolidColorBrush(D2D1::ColorF(r, g, b, 1.0f), &brush);

	renderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius), brush, 3.0f);

	brush->Release();
}