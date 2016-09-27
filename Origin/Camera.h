#pragma once

#include "Vector3f.h"


namespace illidan
{
	class Camera
	{
	private:
		Vector3f m_Pos;
		Vector3f m_Aim;
		Vector3f m_Up;

	public:
		Camera();
		Camera(const Camera& that);
		Camera& operator=(const Camera& that);
		virtual ~Camera();
	};
}
