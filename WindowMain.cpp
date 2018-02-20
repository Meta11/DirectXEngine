#include <Windows.h>
#include "Graphics.h"
#include "GameController.h"
#include "Level1.h"

#define APPTITLE "Direct3D_Windowed"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

Graphics* graphics;

//forward declarations
LRESULT WINAPI WinProc(HWND, UINT, WPARAM, LPARAM);
ATOM MyRegisterClass(HINSTANCE);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR cmd, int nCmdShow) {

	MyRegisterClass(hInstance);

	RECT rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, false, WS_EX_OVERLAPPEDWINDOW);

	HWND hWnd;
	MSG msg;

	hWnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, APPTITLE, APPTITLE, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
			rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, NULL);

	if (!hWnd)
		return -1;

	graphics = new Graphics();

	if (!graphics->initialize(hWnd))
	{
		delete graphics;
		return -1;
	}

	GameLevel::initialize(graphics);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	GameController::initialize();
	GameController::loadLevel(new Level1());

	//main message loop
	int done = 0;
	while (!done) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT) {
				MessageBox(hWnd, "Recived WM_QUIT message", "WinMain", MB_OK);
				done = 1;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			GameController::update();
			graphics->beginDraw();
			GameController::render();
			graphics->endDraw();

		}
	}
	return msg.wParam;
}

//window event callback function
LRESULT WINAPI WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_DESTROY:
		//direct3D.Game_End(hWnd);
		//graphics->shutdown();
		delete graphics;
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

ATOM MyRegisterClass(HINSTANCE hInstance) {
	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(WNDCLASSEX);
	//filling the struct with info
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = APPTITLE;
	wc.hIconSm = NULL;

	return RegisterClassEx(&wc);
}