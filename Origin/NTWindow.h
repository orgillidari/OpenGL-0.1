#pragma once

#include <map>
#include <windows.h>

namespace illidan
{
	class NTWindow
	{
	//Static
	protected:
		static HINSTANCE s_Instance;
		static std::map<LPCWSTR, WNDCLASSEX*> s_WndClassCache;

	protected:
		static LRESULT CALLBACK WinPro(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	public:
		static int RegisterInstance(HINSTANCE instance);
		static int RegisterNTWindowClass(LPCWSTR pName);
		static int ClearNTWindowClass();

		template <typename T>
		static T* CreateNTWindow(LPCWSTR pWCName, LPCWSTR pWName, int width, int height);

	//Member
	protected:
		HWND m_Wnd;
		NTWindow();
		NTWindow(const NTWindow& that);
		NTWindow operator=(const NTWindow& that);
		~NTWindow();

		int InnerCreateNTWindow(LPCWSTR pWCName, LPCWSTR pWName, int width, int height);
	public:
		

		
		int UpdateNTWindow();

	};

	template <typename T>
	T* NTWindow::CreateNTWindow(LPCWSTR pWCName, LPCWSTR pWName, int width, int height)
	{
		T* pWindow= new T();
		pWindow->InnerCreateNTWindow(pWCName, pWName, width, height);
		return pWindow;
	}
}
