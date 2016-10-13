#include "OpenGLWindow.h"

#pragma comment(lib, "OpenGL32.Lib")
#pragma comment(lib, "GlU32.Lib")

namespace illidan
{
	OpenGLWindow::OpenGLWindow()
		: NTWindow(), m_PixelID(0), m_HGLRC(0), m_Lua(0), m_Camera(0), m_SkyBox(0)
	{
	}

	OpenGLWindow::OpenGLWindow(const OpenGLWindow& that)
		: NTWindow(that), m_PixelID(that.m_PixelID), m_HGLRC(that.m_HGLRC), m_Camera(that.m_Camera), m_SkyBox(that.m_SkyBox)
	{
	}
	OpenGLWindow& OpenGLWindow::operator=(const OpenGLWindow& that)
	{
		if (this != &that)
		{
			NTWindow::operator=(that);

			m_PixelID = that.m_PixelID;
			m_HGLRC = that.m_HGLRC;
			m_Camera = that.m_Camera;
			m_SkyBox = that.m_SkyBox;
		}

		return *this;
	}
	OpenGLWindow::~OpenGLWindow()
	{
		m_PixelID = 0;
		m_HGLRC = 0;
		m_Lua = 0;
		m_Camera = 0;
		m_SkyBox = 0;
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
		
		//创建Camera
		m_Camera = new Camera(m_WND);
		m_SkyBox = new SkyBox();
		m_SkyBox->LoadTexture2D("./Pic/front.bmp", "./Pic/back.bmp", "./Pic/left.bmp", "./Pic/right.bmp", "./Pic/top.bmp", "./Pic/bottom.bmp");

		//调用Init
		m_Lua->CallFunction("Init");	
	}

	void OpenGLWindow::Update(unsigned int delta)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//视口Left
		//设置投影矩阵
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60, m_Width / m_Height, 0.1, 1000.0);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		glViewport(0, 0, 1200, 900);

		m_Camera->Update(delta);
		m_SkyBox->Update(m_Camera->GetPos());

		//调用Update
		m_Lua->CallFunction("Update");

		//视口Right
		//设置投影矩阵
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60, m_Width / m_Height, 0.1, 1000.0);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glViewport(1200, 500, 400, 400);
		m_SkyBox->Update(Vector3f(0, 0, 0));


		//调用Update
		m_Lua->CallFunction("Update");
		
		SwapBuffers(m_HDC);
	}

	void OpenGLWindow::Destroy()
	{
		//调用Destroy
		m_Lua->CallFunction("Destroy");

		//销毁Camera
		delete m_Camera;

		//清除Lua环境
		m_Lua->Destroy();
		delete m_Lua;
	}

	void OpenGLWindow::OnRButtonDown(WPARAM wParam, LPARAM lParam)
	{
		if (m_Camera)
			m_Camera->OnRButtonDown(wParam, lParam);
	}

	void OpenGLWindow::OnRButtonUp(WPARAM wParam, LPARAM lParam)
	{
		if (m_Camera)
			m_Camera->OnRButtonUp(wParam, lParam);
	}

	void OpenGLWindow::OnMouseMove(WPARAM wParam, LPARAM lParam)
	{
		if (m_Camera)
			m_Camera->OnMouseMove(wParam, lParam);
	}

	void OpenGLWindow::OnKeyDown(WPARAM wParam, LPARAM lParam)
	{
		if (m_Camera)
			m_Camera->OnKeyDown(wParam, lParam);
	}

	void OpenGLWindow::OnKeyUp(WPARAM wParam, LPARAM lParam)
	{
		if (m_Camera)
			m_Camera->OnKeyUp(wParam, lParam);
	}
}