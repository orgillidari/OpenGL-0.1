#pragma once

#include "NTWindow.h"

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
	};
}
