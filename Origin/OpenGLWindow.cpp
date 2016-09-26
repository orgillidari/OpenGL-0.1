#include "OpenGLWindow.h"

#pragma comment(lib, "OpenGL32.Lib")
#pragma comment(lib, "GlU32.Lib")

namespace illidan
{
	OpenGLWindow::OpenGLWindow()
		: NTWindow(), m_PixelID(0), m_HGLRC(0), m_Lua(0)
	{
	}

	OpenGLWindow::OpenGLWindow(const OpenGLWindow& that)
		: NTWindow(that), m_PixelID(that.m_PixelID), m_HGLRC(that.m_HGLRC)
	{
		if (m_Lua)
			delete m_Lua;

		m_Lua = that.m_Lua;
	}
	OpenGLWindow& OpenGLWindow::operator=(const OpenGLWindow& that)
	{
		if (this != &that)
		{
			NTWindow::operator=(that);
			m_PixelID = that.m_PixelID;
			m_HGLRC = that.m_HGLRC;
			
			if (m_Lua)
				delete m_Lua;

			m_Lua = that.m_Lua;
		}

		return *this;
	}
	OpenGLWindow::~OpenGLWindow()
	{
		m_PixelID = 0;
		m_HGLRC = 0;
		m_Lua = 0;
	}

	int OpenGLWindow::Construtor(LPCWSTR pWCName, LPCWSTR pWName, int width, int height)
	{
		NTWindow::Construtor(pWCName, pWName, width, height);

		PIXELFORMATDESCRIPTOR pfd;
		pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
		pfd.nVersion = 1;
		pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		pfd.iPixelType = PFD_TYPE_RGBA;
		pfd.cColorBits = 32;
		pfd.cRedBits = 8;
		pfd.cRedShift = 0;
		pfd.cGreenBits = 8;
		pfd.cGreenShift = 0;
		pfd.cBlueBits = 8;
		pfd.cBlueShift = 0;
		pfd.cAlphaBits = 8;
		pfd.cAlphaShift = 0;
		pfd.cAccumBits = 0;
		pfd.cAccumRedBits = 0;
		pfd.cAccumGreenBits = 0;
		pfd.cAccumBlueBits = 0;
		pfd.cAccumAlphaBits = 0;
		pfd.cDepthBits = 24;
		pfd.cStencilBits = 8;
		pfd.cAuxBuffers = 0;
		pfd.iLayerType = PFD_MAIN_PLANE;
		pfd.bReserved = 0;
		pfd.dwLayerMask = 0;
		pfd.dwVisibleMask = 0;
		pfd.dwDamageMask = 0;

		m_PixelID = ChoosePixelFormat(m_HDC, &pfd);
		SetPixelFormat(m_HDC, m_PixelID, &pfd);

		m_HGLRC = wglCreateContext(m_HDC);
		wglMakeCurrent(m_HDC, m_HGLRC);

		return 0;
	}

	void OpenGLWindow::Init()
	{
		//创建Lua环境
		m_Lua = new Lua();
		m_Lua->Init();
		m_Lua->ExportOpenGLAPI();
		m_Lua->CallFile("OpenGLWindow.lua");
		
		//调用Init
		m_Lua->CallFunction("Init");	
	}

	void OpenGLWindow::Update()
	{
		//调用Update
		m_Lua->CallFunction("Update");

		SwapBuffers(m_HDC);
	}

	void OpenGLWindow::Destroy()
	{
		//调用Destroy
		m_Lua->CallFunction("Destroy");

		//清除Lua环境
		m_Lua->Destroy();
		delete m_Lua;
	}
}