#pragma once

#include "Vector3f.h"
#include "Texture2D.h"
#include "Texture2D.h"

namespace illidan
{
	class SkyBox
	{
	private:
		Texture2D* m_Front;
		Texture2D* m_Back;
		Texture2D* m_Left;
		Texture2D* m_Right;
		Texture2D* m_Top;
		Texture2D* m_Bottom;
		Vector3f m_Pos;

		bool m_Status;

	public:
		SkyBox();

		int LoadTexture2D(const char* front, const char* back, const char* left, const char* right, const char* top, const char* bottom);
		void Update(Vector3f pos);
	};
}
