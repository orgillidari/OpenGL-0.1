#include "SkyBox.h"


namespace illidan
{
	SkyBox::SkyBox()
		: m_Front(0), m_Back(0), m_Left(0), m_Right(0), m_Top(0), m_Bottom(0), m_Pos(), m_Status(false)
	{

	}

	int SkyBox::LoadTexture2D(const char* front, const char* back, const char* left, const char* right, const char* top, const char* bottom)
	{
		m_Front = Texture2D::LoadTexture2D(front);
		m_Back = Texture2D::LoadTexture2D(back);
		m_Left = Texture2D::LoadTexture2D(left);
		m_Right = Texture2D::LoadTexture2D(right);
		m_Top = Texture2D::LoadTexture2D(top);
		m_Bottom = Texture2D::LoadTexture2D(bottom);

		if (!m_Front || !m_Back || !m_Left || !m_Right || !m_Top || !m_Bottom)
		{
			return -1;
		}

		m_Status = true;

		return 0;
	}

	void SkyBox::Update(Vector3f pos)
	{	
		if (!m_Status)
			return;

		glDisable(GL_DEPTH_TEST);
		glDisable(GL_BLEND);
		glEnable(GL_TEXTURE_2D);
		
		glColor4ub(255, 255, 255, 255);

		glPushMatrix();

		glTranslatef(pos.X, pos.Y, pos.Z);

		//front
		glBindTexture(GL_TEXTURE_2D, m_Front->GetTextureID());
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.5f, -0.5f, -0.5f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.5f, -0.5f, -0.5f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.5f, 0.5f, -0.5f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.5f, 0.5f, -0.5f);
		glEnd();

		//back
		glBindTexture(GL_TEXTURE_2D, m_Back->GetTextureID());
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0.5f, -0.5f, 0.5f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-0.5f, -0.5f, 0.5f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-0.5f, 0.5f, 0.5f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(0.5f, 0.5f, 0.5f);
		glEnd();

		//left
		glBindTexture(GL_TEXTURE_2D, m_Left->GetTextureID());
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.5f, -0.5f, 0.5f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-0.5f, -0.5f, -0.5f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-0.5f, 0.5f, -0.5f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.5f, 0.5f, 0.5f);
		glEnd();

		//right
		glBindTexture(GL_TEXTURE_2D, m_Right->GetTextureID());
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0.5f, -0.5f, -0.5f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.5f, -0.5f, 0.5f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.5f, 0.5f, 0.5f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(0.5f, 0.5f, -0.5f);
		glEnd();

		//top
		glBindTexture(GL_TEXTURE_2D, m_Top->GetTextureID());
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.5f, 0.5f, -0.5f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.5f, 0.5f, -0.5f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.5f, 0.5f, 0.5f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.5f, 0.5f, 0.5f);
		glEnd();

		//bottom
		glBindTexture(GL_TEXTURE_2D, m_Bottom->GetTextureID());
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.5f, -0.5f, 0.5f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.5f, -0.5f, 0.5f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.5f, -0.5f, -0.5f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.5f, -0.5f, -0.5f);
		glEnd();

		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glEnable(GL_DEPTH_TEST);
	}
}