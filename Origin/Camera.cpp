#include "Camera.h"

#pragma comment(lib, "OpenGL32.Lib")


namespace illidan
{
	void Camera::RotateView(float angle, float x, float y, float z)
	{
		Vector3f viewLine = m_Aim - m_Pos;
		Vector3f newViewLine;
		float C = (float)cos(angle);
		float S = (float)sin(angle);

		Vector3f tempX(C + x*x*(1 - C), x*y*(1 - C) - z*S, x*z*(1 - C) + y*S);
		newViewLine.X = viewLine*tempX;

		Vector3f tempY(z*S + x*y*(1 - C), y*y*(1 - C) + C, y*z*(1 - C) - x*S);
		newViewLine.Y = viewLine*tempY;

		Vector3f tempZ(x*z*(1 - C) - y*S, z*y*(1 - C) + x*S, z*z*(1 - C) + C);
		newViewLine.Z = viewLine*tempZ;

		m_Aim = m_Pos + newViewLine;
	}

	Camera::Camera(HWND wnd)
		:m_WND(wnd), m_Pos(0.0f, 0.0f, 1.0f), m_Aim(0.0f, 0.0f, 0.0f), m_Up(0.0f, 1.0f, 0.0f), m_RButtonDown(false), m_LastPoint(), m_bForward(false), m_bBack(false), m_bLeft(false), m_bRight(false), m_Speed(0.1f)
	{
	}

	Camera::Camera(const Camera& that)
		: m_WND(that.m_WND), m_Pos(that.m_Pos), m_Aim(that.m_Pos), m_Up(that.m_Up), m_RButtonDown(that.m_RButtonDown), m_LastPoint(that.m_LastPoint), m_bForward(that.m_bForward), m_bBack(that.m_bBack), m_bLeft(that.m_bLeft), m_bRight(that.m_bRight), m_Speed(that.m_Speed)
	{
	}

	Camera& Camera::operator=(const Camera& that)
	{
		if (this != &that)
		{
			m_WND = that.m_WND;

			m_Pos = that.m_Pos;
			m_Aim = that.m_Aim;
			m_Up = that.m_Up;

			m_RButtonDown = that.m_RButtonDown;
			m_LastPoint = that.m_LastPoint;
			m_bForward = that.m_bForward;
			m_bBack = that.m_bBack;
			m_bLeft = that.m_bLeft;
			m_bRight = that.m_bRight;
			m_Speed = that.m_Speed;
		}
		return *this;
	}

	Camera::~Camera()
	{

	}

	void Camera::Update(unsigned int delta)
	{
		if (m_bForward)
		{
			Vector3f forward = m_Aim - m_Pos;
			forward.Normalize();
			Vector3f offset = forward * m_Speed * (float)delta;
			m_Pos = m_Pos + offset;
			m_Aim = m_Aim + offset;
		}
		if (m_bBack)
		{
			Vector3f forward = m_Aim - m_Pos;
			forward.Normalize();
			Vector3f offset = forward * m_Speed * (float)delta;
			m_Pos = m_Pos - offset;
			m_Aim = m_Aim - offset;
		}
		if (m_bLeft)
		{
			Vector3f forward = m_Aim - m_Pos;
			Vector3f right = forward ^ m_Up;
			right.Normalize();
			Vector3f offset = right * m_Speed * (float)delta;
			m_Pos = m_Pos - offset;
			m_Aim = m_Aim - offset;
		}
		if (m_bRight)
		{
			Vector3f forward = m_Aim - m_Pos;
			Vector3f right = forward ^ m_Up;
			right.Normalize();
			Vector3f offset = right * m_Speed * (float)delta;
			m_Pos = m_Pos + offset;
			m_Aim = m_Aim + offset;
		}

		gluLookAt(m_Pos.X, m_Pos.Y, m_Pos.Z, m_Aim.X, m_Aim.Y, m_Aim.Z, m_Up.X, m_Up.Y, m_Up.Z);
	}

	Vector3f Camera::GetPos()
	{
		return m_Pos;
	}

	void Camera::OnRButtonDown(WPARAM wParam, LPARAM lParam)
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);

		m_LastPoint.x = x;
		m_LastPoint.y = y;
		
		m_RButtonDown = true;

		m_OriginPoint.x = x;
		m_OriginPoint.y = y;
		ClientToScreen(m_WND, &m_OriginPoint);
		ShowCursor(false);
		SetCapture(m_WND);
	}

	void Camera::OnRButtonUp(WPARAM wParam, LPARAM lParam)
	{
		m_RButtonDown = false;

		SetCursorPos(m_OriginPoint.x, m_OriginPoint.y);
		ShowCursor(true);
		ReleaseCapture();
	}

	void Camera::OnMouseMove(WPARAM wParam, LPARAM lParam)
	{
		if (!m_RButtonDown)
			return;

		int x = LOWORD(lParam);
		int y = HIWORD(lParam);

		long deltaX = m_LastPoint.x - x;
		long deltaY = m_LastPoint.y - y;

		float angleY = deltaX / 1000.0f;
		float angleX = deltaY / 1000.0f;

		Vector3f forward = m_Aim - m_Pos;
		Vector3f right = forward ^ m_Up;

		RotateView(angleY, m_Up.X, m_Up.Y, m_Up.Z);
		RotateView(angleX, right.X, right.Y, right.Z);

		//防止鼠标移动出屏幕出现跳转
		SetCursorPos(m_OriginPoint.x, m_OriginPoint.y);
		m_LastPoint.x = m_OriginPoint.x;
		m_LastPoint.y = m_OriginPoint.y;
		ScreenToClient(m_WND, &m_LastPoint);
	}

	void Camera::OnKeyDown(WPARAM wParam, LPARAM lParam)
	{
		if (wParam == 'W')
		{
			m_bForward = true;
		}
		if (wParam == 'S')
		{
			m_bBack = true;
		}
		if (wParam == 'A')
		{
			m_bLeft = true;
		}
		if (wParam == 'D')
		{
			m_bRight = true;
		}
	}

	void Camera::OnKeyUp(WPARAM wParam, LPARAM lParam)
	{
		if (wParam == 'W')
		{
			m_bForward = false;
		}
		if (wParam == 'S')
		{
			m_bBack = false;
		}
		if (wParam == 'A')
		{
			m_bLeft = false;
		}
		if (wParam == 'D')
		{
			m_bRight = false;
		}
	}
}