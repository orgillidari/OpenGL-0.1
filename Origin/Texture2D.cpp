#include "Texture2D.h"

#include "Global.h"
#include "Tools.h"
#include "FileSystem.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

#define GL_CLAMP_TO_EDGE 0x812F


namespace illidan
{
	std::map<std::string, Texture2D*> Texture2D::m_Texture2DCache;

	Texture2D* Texture2D::LoadTexture2D(const char* fileName)
	{
		if (m_Texture2DCache.find(fileName) != m_Texture2DCache.end())
			return m_Texture2DCache[fileName];

		const char* fileExtension = Tools::FileExtension(fileName);
		if (strcmp(fileExtension, "bmp") == 0)
		{
			Data data;

			int res = FileSystem::LoadFile(fileName, data);
			if (res != RES_OK)
				return NULL;

			BITMAPFILEHEADER bfh;
			memcpy(&bfh, data.m_Data, sizeof(BITMAPFILEHEADER));
			if (bfh.bfType != 0x4D42)
				return NULL;

			BITMAPINFOHEADER bih;
			memcpy(&bih, data.m_Data + sizeof(BITMAPFILEHEADER), sizeof(BITMAPINFOHEADER));

			Texture2D* texture = new Texture2D;
			texture->m_Width = bih.biWidth;
			texture->m_Height = bih.biHeight;

			GLuint textureID;
			glGenTextures(1, &textureID);
			glBindTexture(GL_TEXTURE_2D, textureID);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture->m_Width, texture->m_Height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data.m_Data + bfh.bfOffBits);
			glBindTexture(GL_TEXTURE_2D, 0);

			texture->m_TextureID = textureID;

			m_Texture2DCache.insert(std::pair<std::string, Texture2D*>(fileName, texture));

			return texture;
		}

		return 0;
	}

	Texture2D::Texture2D()
		:
		m_TextureID(0), m_Width(0), m_Height(0)
	{

	}

	GLuint Texture2D::GetTextureID()
	{
		return m_TextureID;
	}
}