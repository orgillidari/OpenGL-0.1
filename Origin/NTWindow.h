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
		LPCWSTR m_pWCName;
		LPCWSTR m_pWName;
		int m_Width;
		int m_Height;
		HWND m_WND;
		HDC m_HDC;

	protected:
		NTWindow();
		NTWindow(const NTWindow& that);
		NTWindow& operator=(const NTWindow& that);
		virtual ~NTWindow();

	public:
		int UpdateNTWindow();

	//Virtual
	public:
		virtual int Construtor(LPCWSTR pWCName, LPCWSTR pWName, int width, int height);
		virtual void Init();
		virtual void Update();
		virtual void Destroy();

	};


	template <typename T>
	T* NTWindow::CreateNTWindow(LPCWSTR pWCName, LPCWSTR pWName, int width, int height)
	{
		T* pWindow = new T();
		pWindow->Construtor(pWCName, pWName, width, height);
		return pWindow;
	}
}
