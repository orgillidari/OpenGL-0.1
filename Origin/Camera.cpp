#include "Camera.h"


namespace illidan
{
	Camera::Camera()
		:m_Pos(), m_Aim(), m_Up()
	{
	}

	Camera::Camera(const Camera& that)
		:m_Pos(that.m_Pos), m_Aim(that.m_Pos), m_Up(that.m_Up)
	{
	}

	Camera& Camera::operator=(const Camera& that)
	{
		if (this != &that)
		{
			m_Pos = that.m_Pos;
			m_Aim = that.m_Aim;
			m_Up = that.m_Up;
		}
		return *this;
	}

	Camera::~Camera()
	{

	}
}