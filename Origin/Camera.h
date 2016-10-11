#pragma once

#include <windows.h>
#include "Vector3f.h"
#include <gl/GL.h>
#include <gl/GLU.h>

namespace illidan
{
	class Camera
	{
	//Member
	private:
		HWND m_WND;

		Vector3f m_Pos;
		Vector3f m_Aim;
		Vector3f m_Up;

		bool m_RButtonDown;
		POINT m_LastPoint;
		POINT m_OriginPoint;
		bool m_bForward;
		bool m_bBack;
		bool m_bLeft;
		bool m_bRight;
		float m_Speed;
	private:
		void RotateView(float angle, float x, float y, float z);

	public:
		Camera(HWND wnd);
		Camera(const Camera& that);
		Camera& operator=(const Camera& that);
		virtual ~Camera();

		void Update(unsigned int delta);

		Vector3f GetPos();
	//Virtual
	public:
		void OnRButtonDown(WPARAM wParam, LPARAM lParam);
		void OnRButtonUp(WPARAM wParam, LPARAM lParam);
		void OnMouseMove(WPARAM wParam, LPARAM lParam);
		void OnKeyDown(WPARAM wParam, LPARAM lParam);
		void OnKeyUp(WPARAM wParam, LPARAM lParam);
	};
}
