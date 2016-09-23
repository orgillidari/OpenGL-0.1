#pragma once

#include <map>
#include <windows.h>

namespace illidan
{
	class NTWindow
	{
	//Static
	private:
		static HINSTANCE s_Instance;
		static std::map<LPCWSTR, WNDCLASSEX*> s_WndClassCache;

	private:
		static LRESULT CALLBACK WinPro(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	public:
		static int RegisterInstance(HINSTANCE instance);
		static int RegisterNTWindowClass(LPCWSTR pName);
		static int ClearNTWindowClass();


	//Member
	private:
		HWND m_Wnd;

	public:
		NTWindow();

		int CreateNTWindow(LPCWSTR pWCName, LPCWSTR pWName, int width, int height);
		int UpdateNTWindow();

	};
}
