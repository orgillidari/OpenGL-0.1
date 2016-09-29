#pragma once

#include "NTWindow.h"
#include "Lua.h"
#include "Camera.h"

#include <gl/GL.h>
#include <gl/GLU.h>


namespace illidan
{
	class OpenGLWindow : public NTWindow
	{
	//Member
	protected:
		int m_PixelID;
		HGLRC m_HGLRC;
		Lua* m_Lua;
		Camera* m_Camera;

	public:
		OpenGLWindow();
		OpenGLWindow(const OpenGLWindow& that);
		OpenGLWindow& operator=(const OpenGLWindow& that);
		virtual ~OpenGLWindow();

	//Virtual
	public:
		virtual int Construtor(LPCWSTR pWCName, LPCWSTR pWName, int width, int height) override;
		virtual void Init() override;
		virtual void Update() override;
		virtual void Destroy() override;

		virtual void OnRButtonDown(WPARAM wParam, LPARAM lParam) override;
		virtual void OnRButtonUp(WPARAM wParam, LPARAM lParam) override;
		virtual void OnMouseMove(WPARAM wParam, LPARAM lParam) override;
		virtual void OnKeyDown(WPARAM wParam, LPARAM lParam) override;
		virtual void OnKeyUp(WPARAM wParam, LPARAM lParam) override;

	};
}
