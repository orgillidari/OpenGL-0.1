#pragma once

#include <string>
#include <map>
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>


namespace illidan
{
	class Texture2D
	{
	private:
		static std::map<std::string, Texture2D*> m_Texture2DCache;

	public:
		static Texture2D* LoadTexture2D(const char* fileName);

	private:
		GLuint m_TextureID;
		unsigned int m_Width;
		unsigned int m_Height;

	public:
		Texture2D();
	};
}
