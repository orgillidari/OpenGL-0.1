#include "NTWindow.h"

namespace illidan
{
	HINSTANCE NTWindow::s_Instance;
	std::map<LPCWSTR, WNDCLASSEX*> NTWindow::s_WndClassCache;


	LRESULT CALLBACK NTWindow::WinPro(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_CLOSE:
			DestroyWindow(hWnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		}
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	int NTWindow::RegisterInstance(HINSTANCE instance)
	{
		s_Instance = instance;

		return 0;
	}

	int NTWindow::RegisterNTWindowClass(LPCWSTR pName)
	{
		if (s_WndClassCache.find(pName) != s_WndClassCache.end())
		{
			return 1;
		}

		//注册窗口类
		WNDCLASSEX* pWCE = new WNDCLASSEX;
		pWCE->cbSize = sizeof(WNDCLASSEX);
		pWCE->style = CS_HREDRAW | CS_VREDRAW;
		pWCE->lpfnWndProc = NTWindow::WinPro;
		pWCE->cbClsExtra = 0;
		pWCE->cbWndExtra = 0;
		pWCE->hInstance = s_Instance;
		pWCE->hIcon = (HICON)LoadIcon(s_Instance, MAKEINTRESOURCE(101));
		pWCE->hCursor = LoadCursor(NULL, IDC_ARROW);
		pWCE->hbrBackground = CreateSolidBrush(RGB(0,0,0));
		pWCE->lpszMenuName = NULL;
		pWCE->lpszClassName = pName;
		pWCE->hIconSm = (HICON)LoadIcon(s_Instance, MAKEINTRESOURCE(101));
		DWORD res = RegisterClassEx(pWCE);
		if (res == 0)
		{
			DWORD err = GetLastError();
			return -1;
		}

		s_WndClassCache.insert(std::pair<LPCWSTR, WNDCLASSEX*>(pName, pWCE));

		return 0;
	}

	int NTWindow::ClearNTWindowClass()
	{
		for (std::map<LPCWSTR, WNDCLASSEX*>::iterator it = s_WndClassCache.begin(); it != s_WndClassCache.end(); ++it)
		{
			delete it->second;
		}
		s_WndClassCache.clear();

		return 0;
	}


	NTWindow::NTWindow()
		:
		m_Wnd(0)
	{

	}

	int NTWindow::CreateNTWindow(LPCWSTR pWCName, LPCWSTR pWName, int width, int height)
	{
		//计算窗口大小和位置
		int screenW = GetSystemMetrics(SM_CXSCREEN);
		int screenH = GetSystemMetrics(SM_CYSCREEN);

		RECT rect
		{
			(screenW - width) / 2,
			(screenH - height) / 2,
			rect.left + width,
			rect.top + height
		};

		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);


		//创建窗口并显示
		HWND hWnd = CreateWindowEx(NULL, pWCName, pWName, WS_OVERLAPPEDWINDOW, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, s_Instance, NULL);
		if (hWnd == 0)
		{
			DWORD err = GetLastError();
			return -1;
		}

		ShowWindow(hWnd, SW_SHOW);
		UpdateWindow(hWnd);

		return 0;
	}

	int NTWindow::UpdateNTWindow()
	{
		//消息循环
		MSG msg;
		while (true)
		{
			if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			{
				if (msg.message == WM_QUIT)
				{
					break;
				}

				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}

		return 0;
	}
}