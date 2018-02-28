#include "Renderer.h"
#include "GameLevel.h"

Renderer::Renderer()
{
	factory = nullptr;
	renderTarget = nullptr;
	brush = nullptr;
}

Renderer::~Renderer()
{
	if (renderTarget != nullptr)
		renderTarget->Release();
	if (factory != nullptr)
		factory->Release();
}

bool Renderer::initialize(HWND hwnd)
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

bool Renderer::shutdown()
{
	if (renderTarget != nullptr)
		renderTarget->Release();
	if (factory != nullptr)
		factory->Release();
	return true;
}

void Renderer::clearScreen(float r, float g, float b)
{
	renderTarget->Clear(D2D1::ColorF(r, g, b));
}
