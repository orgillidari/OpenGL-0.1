#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include"lgl.h"
int API_glAccum(lua_State*L)
{
	glAccum((GLenum)lua_tointeger(L,1),(GLfloat)lua_tonumber(L,2));
	return 0;
}
int API_glAlphaFunc(lua_State*L)
{
	glAlphaFunc((GLenum)lua_tointeger(L,1),(GLclampf)lua_tonumber(L,2));
	return 0;
}
int API_glArrayElement(lua_State*L)
{
	glArrayElement((GLint)lua_tointeger(L,1));
	return 0;
}
int API_glBegin(lua_State*L)
{
	glBegin((GLenum)lua_tointeger(L,1));
	return 0;
}
int API_glBindTexture(lua_State*L)
{
	glBindTexture((GLenum)lua_tointeger(L,1),(GLuint)lua_tointeger(L,2));
	return 0;
}
int API_glBlendFunc(lua_State*L)
{
	glBlendFunc((GLenum)lua_tointeger(L,1),(GLenum)lua_tointeger(L,2));
	return 0;
}
int API_glCallList(lua_State*L)
{
	glCallList((GLuint)lua_tointeger(L,1));
	return 0;
}
int API_glClear(lua_State*L)
{
	int argC = lua_gettop(L);
	unsigned int temp=0;
	for (int i = 0; i < argC; ++i)
	{
		temp |= lua_tointeger(L, i+1);
	}
	glClear((GLbitfield)temp);
	return 0;
}
int API_glClearAccum(lua_State*L)
{
	glClearAccum((GLfloat)lua_tonumber(L,1),(GLfloat)lua_tonumber(L,2),(GLfloat)lua_tonumber(L,3),(GLfloat)lua_tonumber(L,4));
	return 0;
}
int API_glClearColor(lua_State*L)
{
	glClearColor((GLclampf)lua_tonumber(L,1),(GLclampf)lua_tonumber(L,2),(GLclampf)lua_tonumber(L,3),(GLclampf)lua_tonumber(L,4));
	return 0;
}
int API_glClearDepth(lua_State*L)
{
	glClearDepth((GLclampd)lua_tonumber(L,1));
	return 0;
}
int API_glClearIndex(lua_State*L)
{
	glClearIndex((GLfloat)lua_tonumber(L,1));
	return 0;
}
int API_glClearStencil(lua_State*L)
{
	glClearStencil((GLint)lua_tointeger(L,1));
	return 0;
}
int API_glColor3b(lua_State*L)
{
	glColor3b((GLbyte)lua_tointeger(L,1),(GLbyte)lua_tointeger(L,2),(GLbyte)lua_tointeger(L,3));
	return 0;
}
int API_glColor3d(lua_State*L)
{
	glColor3d((GLdouble)lua_tonumber(L,1),(GLdouble)lua_tonumber(L,2),(GLdouble)lua_tonumber(L,3));
	return 0;
}
int API_glColor3f(lua_State*L)
{
	glColor3f((GLfloat)lua_tonumber(L,1),(GLfloat)lua_tonumber(L,2),(GLfloat)lua_tonumber(L,3));
	return 0;
}
int API_glColor3i(lua_State*L)
{
	glColor3i((GLint)lua_tointeger(L,1),(GLint)lua_tointeger(L,2),(GLint)lua_tointeger(L,3));
	return 0;
}
int API_glColor3s(lua_State*L)
{
	glColor3s((GLshort)lua_tointeger(L,1),(GLshort)lua_tointeger(L,2),(GLshort)lua_tointeger(L,3));
	return 0;
}
int API_glColor3ub(lua_State*L)
{
	glColor3ub((GLubyte)lua_tointeger(L,1),(GLubyte)lua_tointeger(L,2),(GLubyte)lua_tointeger(L,3));
	return 0;
}
int API_glColor3ui(lua_State*L)
{
	glColor3ui((GLuint)lua_tointeger(L,1),(GLuint)lua_tointeger(L,2),(GLuint)lua_tointeger(L,3));
	return 0;
}
int API_glColor3us(lua_State*L)
{
	glColor3us((GLushort)lua_tointeger(L,1),(GLushort)lua_tointeger(L,2),(GLushort)lua_tointeger(L,3));
	return 0;
}
int API_glColor4b(lua_State*L)
{
	glColor4b((GLbyte)lua_tointeger(L,1),(GLbyte)lua_tointeger(L,2),(GLbyte)lua_tointeger(L,3),(GLbyte)lua_tointeger(L,4));
	return 0;
}
int API_glColor4d(lua_State*L)
{
	glColor4d((GLdouble)lua_tonumber(L,1),(GLdouble)lua_tonumber(L,2),(GLdouble)lua_tonumber(L,3),(GLdouble)lua_tonumber(L,4));
	return 0;
}
int API_glColor4f(lua_State*L)
{
	glColor4f((GLfloat)lua_tonumber(L,1),(GLfloat)lua_tonumber(L,2),(GLfloat)lua_tonumber(L,3),(GLfloat)lua_tonumber(L,4));
	return 0;
}
int API_glColor4i(lua_State*L)
{
	glColor4i((GLint)lua_tointeger(L,1),(GLint)lua_tointeger(L,2),(GLint)lua_tointeger(L,3),(GLint)lua_tointeger(L,4));
	return 0;
}
int API_glColor4s(lua_State*L)
{
	glColor4s((GLshort)lua_tointeger(L,1),(GLshort)lua_tointeger(L,2),(GLshort)lua_tointeger(L,3),(GLshort)lua_tointeger(L,4));
	return 0;
}
int API_glColor4ub(lua_State*L)
{
	glColor4ub((GLubyte)lua_tointeger(L,1),(GLubyte)lua_tointeger(L,2),(GLubyte)lua_tointeger(L,3),(GLubyte)lua_tointeger(L,4));
	return 0;
}
int API_glColor4ui(lua_State*L)
{
	glColor4ui((GLuint)lua_tointeger(L,1),(GLuint)lua_tointeger(L,2),(GLuint)lua_tointeger(L,3),(GLuint)lua_tointeger(L,4));
	return 0;
}
int API_glColor4us(lua_State*L)
{
	glColor4us((GLushort)lua_tointeger(L,1),(GLushort)lua_tointeger(L,2),(GLushort)lua_tointeger(L,3),(GLushort)lua_tointeger(L,4));
	return 0;
}
int API_glColorMask(lua_State*L)
{
	glColorMask((GLboolean)lua_toboolean(L,1),(GLboolean)lua_toboolean(L,2),(GLboolean)lua_toboolean(L,3),(GLboolean)lua_toboolean(L,4));
	return 0;
}
int API_glColorMaterial(lua_State*L)
{
	glColorMaterial((GLenum)lua_tointeger(L,1),(GLenum)lua_tointeger(L,2));
	return 0;
}
int API_glCopyPixels(lua_State*L)
{
	glCopyPixels((GLint)lua_tointeger(L,1),(GLint)lua_tointeger(L,2),(GLsizei)lua_tointeger(L,3),(GLsizei)lua_tointeger(L,4),(GLenum)lua_tointeger(L,5));
	return 0;
}
int API_glCopyTexImage1D(lua_State*L)
{
	glCopyTexImage1D((GLenum)lua_tointeger(L,1),(GLint)lua_tointeger(L,2),(GLenum)lua_tointeger(L,3),(GLint)lua_tointeger(L,4),(GLint)lua_tointeger(L,5),(GLsizei)lua_tointeger(L,6),(GLint)lua_tointeger(L,7));
	return 0;
}
int API_glCopyTexImage2D(lua_State*L)
{
	glCopyTexImage2D((GLenum)lua_tointeger(L,1),(GLint)lua_tointeger(L,2),(GLenum)lua_tointeger(L,3),(GLint)lua_tointeger(L,4),(GLint)lua_tointeger(L,5),(GLsizei)lua_tointeger(L,6),(GLsizei)lua_tointeger(L,7),(GLint)lua_tointeger(L,8));
	return 0;
}
int API_glCopyTexSubImage1D(lua_State*L)
{
	glCopyTexSubImage1D((GLenum)lua_tointeger(L,1),(GLint)lua_tointeger(L,2),(GLint)lua_tointeger(L,3),(GLint)lua_tointeger(L,4),(GLint)lua_tointeger(L,5),(GLsizei)lua_tointeger(L,6));
	return 0;
}
int API_glCopyTexSubImage2D(lua_State*L)
{
	glCopyTexSubImage2D((GLenum)lua_tointeger(L,1),(GLint)lua_tointeger(L,2),(GLint)lua_tointeger(L,3),(GLint)lua_tointeger(L,4),(GLint)lua_tointeger(L,5),(GLint)lua_tointeger(L,6),(GLsizei)lua_tointeger(L,7),(GLsizei)lua_tointeger(L,8));
	return 0;
}
int API_glCullFace(lua_State*L)
{
	glCullFace((GLenum)lua_tointeger(L,1));
	return 0;
}
int API_glDeleteLists(lua_State*L)
{
	glDeleteLists((GLuint)lua_tointeger(L,1),(GLsizei)lua_tointeger(L,2));
	return 0;
}
int API_glDepthFunc(lua_State*L)
{
	glDepthFunc((GLenum)lua_tointeger(L,1));
	return 0;
}
int API_glDepthMask(lua_State*L)
{
	glDepthMask((GLboolean)lua_toboolean(L,1));
	return 0;
}
int API_glDepthRange(lua_State*L)
{
	glDepthRange((GLclampd)lua_tonumber(L,1),(GLclampd)lua_tonumber(L,2));
	return 0;
}
int API_glDisable(lua_State*L)
{
	glDisable((GLenum)lua_tointeger(L,1));
	return 0;
}
int API_glDisableClientState(lua_State*L)
{
	glDisableClientState((GLenum)lua_tointeger(L,1));
	return 0;
}
int API_glDrawArrays(lua_State*L)
{
	glDrawArrays((GLenum)lua_tointeger(L,1),(GLint)lua_tointeger(L,2),(GLsizei)lua_tointeger(L,3));
	return 0;
}
int API_glDrawBuffer(lua_State*L)
{
	glDrawBuffer((GLenum)lua_tointeger(L,1));
	return 0;
}
int API_glEdgeFlag(lua_State*L)
{
	glEdgeFlag((GLboolean)lua_toboolean(L,1));
	return 0;
}
int API_glEnable(lua_State*L)
{
	glEnable((GLenum)lua_tointeger(L,1));
	return 0;
}
int API_glEnableClientState(lua_State*L)
{
	glEnableClientState((GLenum)lua_tointeger(L,1));
	return 0;
}
int API_glEnd(lua_State*L)
{
	glEnd();
	return 0;
}
int API_glEndList(lua_State*L)
{
	glEndList();
	return 0;
}
int API_glEvalCoord1d(lua_State*L)
{
	glEvalCoord1d((GLdouble)lua_tonumber(L,1));
	return 0;
}
int API_glEvalCoord1f(lua_State*L)
{
	glEvalCoord1f((GLfloat)lua_tonumber(L,1));
	return 0;
}
int API_glEvalCoord2d(lua_State*L)
{
	glEvalCoord2d((GLdouble)lua_tonumber(L,1),(GLdouble)lua_tonumber(L,2));
	return 0;
}
int API_glEvalCoord2f(lua_State*L)
{
	glEvalCoord2f((GLfloat)lua_tonumber(L,1),(GLfloat)lua_tonumber(L,2));
	return 0;
}
int API_glEvalMesh1(lua_State*L)
{
	glEvalMesh1((GLenum)lua_tointeger(L,1),(GLint)lua_tointeger(L,2),(GLint)lua_tointeger(L,3));
	return 0;
}
int API_glEvalMesh2(lua_State*L)
{
	glEvalMesh2((GLenum)lua_tointeger(L,1),(GLint)lua_tointeger(L,2),(GLint)lua_tointeger(L,3),(GLint)lua_tointeger(L,4),(GLint)lua_tointeger(L,5));
	return 0;
}
int API_glEvalPoint1(lua_State*L)
{
	glEvalPoint1((GLint)lua_tointeger(L,1));
	return 0;
}
int API_glEvalPoint2(lua_State*L)
{
	glEvalPoint2((GLint)lua_tointeger(L,1),(GLint)lua_tointeger(L,2));
	return 0;
}
int API_glFinish(lua_State*L)
{
	glFinish();
	return 0;
}
int API_glFlush(lua_State*L)
{
	glFlush();
	return 0;
}
int API_glFogf(lua_State*L)
{
	glFogf((GLenum)lua_tointeger(L,1),(GLfloat)lua_tonumber(L,2));
	return 0;
}
int API_glFogi(lua_State*L)
{
	glFogi((GLenum)lua_tointeger(L,1),(GLint)lua_tointeger(L,2));
	return 0;
}
int API_glFrontFace(lua_State*L)
{
	glFrontFace((GLenum)lua_tointeger(L,1));
	return 0;
}
int API_glFrustum(lua_State*L)
{
	glFrustum((GLdouble)lua_tonumber(L,1),(GLdouble)lua_tonumber(L,2),(GLdouble)lua_tonumber(L,3),(GLdouble)lua_tonumber(L,4),(GLdouble)lua_tonumber(L,5),(GLdouble)lua_tonumber(L,6));
	return 0;
}
int API_glGenLists(lua_State*L)
{
	glGenLists((GLsizei)lua_tointeger(L,1));
	return 1;
}
int API_glGetError(lua_State*L)
{
	glGetError();
	return 1;
}
int API_glGetString(lua_State*L)
{
	glGetString((GLenum)lua_tointeger(L,1));
	return 1;
}
int API_glHint(lua_State*L)
{
	glHint((GLenum)lua_tointeger(L,1),(GLenum)lua_tointeger(L,2));
	return 0;
}
int API_glIndexMask(lua_State*L)
{
	glIndexMask((GLuint)lua_tointeger(L,1));
	return 0;
}
int API_glIndexd(lua_State*L)
{
	glIndexd((GLdouble)lua_tonumber(L,1));
	return 0;
}
int API_glIndexf(lua_State*L)
{
	glIndexf((GLfloat)lua_tonumber(L,1));
	return 0;
}
int API_glIndexi(lua_State*L)
{
	glIndexi((GLint)lua_tointeger(L,1));
	return 0;
}
int API_glIndexs(lua_State*L)
{
	glIndexs((GLshort)lua_tointeger(L,1));
	return 0;
}
int API_glIndexub(lua_State*L)
{
	glIndexub((GLubyte)lua_tointeger(L,1));
	return 0;
}
int API_glInitNames(lua_State*L)
{
	glInitNames();
	return 0;
}
int API_glIsEnabled(lua_State*L)
{
	glIsEnabled((GLenum)lua_tointeger(L,1));
	return 1;
}
int API_glIsList(lua_State*L)
{
	glIsList((GLuint)lua_tointeger(L,1));
	return 1;
}
int API_glIsTexture(lua_State*L)
{
	glIsTexture((GLuint)lua_tointeger(L,1));
	return 1;
}
int API_glLightModelf(lua_State*L)
{
	glLightModelf((GLenum)lua_tointeger(L,1),(GLfloat)lua_tonumber(L,2));
	return 0;
}
int API_glLightModeli(lua_State*L)
{
	glLightModeli((GLenum)lua_tointeger(L,1),(GLint)lua_tointeger(L,2));
	return 0;
}
int API_glLightf(lua_State*L)
{
	glLightf((GLenum)lua_tointeger(L,1),(GLenum)lua_tointeger(L,2),(GLfloat)lua_tonumber(L,3));
	return 0;
}
int API_glLighti(lua_State*L)
{
	glLighti((GLenum)lua_tointeger(L,1),(GLenum)lua_tointeger(L,2),(GLint)lua_tointeger(L,3));
	return 0;
}
int API_glLineStipple(lua_State*L)
{
	glLineStipple((GLint)lua_tointeger(L,1),(GLushort)lua_tointeger(L,2));
	return 0;
}
int API_glLineWidth(lua_State*L)
{
	glLineWidth((GLfloat)lua_tonumber(L,1));
	return 0;
}
int API_glListBase(lua_State*L)
{
	glListBase((GLuint)lua_tointeger(L,1));
	return 0;
}
int API_glLoadIdentity(lua_State*L)
{
	glLoadIdentity();
	return 0;
}
int API_glLoadName(lua_State*L)
{
	glLoadName((GLuint)lua_tointeger(L,1));
	return 0;
}
int API_glLogicOp(lua_State*L)
{
	glLogicOp((GLenum)lua_tointeger(L,1));
	return 0;
}
int API_glMapGrid1d(lua_State*L)
{
	glMapGrid1d((GLint)lua_tointeger(L,1),(GLdouble)lua_tonumber(L,2),(GLdouble)lua_tonumber(L,3));
	return 0;
}
int API_glMapGrid1f(lua_State*L)
{
	glMapGrid1f((GLint)lua_tointeger(L,1),(GLfloat)lua_tonumber(L,2),(GLfloat)lua_tonumber(L,3));
	return 0;
}
int API_glMapGrid2d(lua_State*L)
{
	glMapGrid2d((GLint)lua_tointeger(L,1),(GLdouble)lua_tonumber(L,2),(GLdouble)lua_tonumber(L,3),(GLint)lua_tointeger(L,4),(GLdouble)lua_tonumber(L,5),(GLdouble)lua_tonumber(L,6));
	return 0;
}
int API_glMapGrid2f(lua_State*L)
{
	glMapGrid2f((GLint)lua_tointeger(L,1),(GLfloat)lua_tonumber(L,2),(GLfloat)lua_tonumber(L,3),(GLint)lua_tointeger(L,4),(GLfloat)lua_tonumber(L,5),(GLfloat)lua_tonumber(L,6));
	return 0;
}
int API_glMaterialf(lua_State*L)
{
	glMaterialf((GLenum)lua_tointeger(L,1),(GLenum)lua_tointeger(L,2),(GLfloat)lua_tonumber(L,3));
	return 0;
}
int API_glMateriali(lua_State*L)
{
	glMateriali((GLenum)lua_tointeger(L,1),(GLenum)lua_tointeger(L,2),(GLint)lua_tointeger(L,3));
	return 0;
}
int API_glMatrixMode(lua_State*L)
{
	glMatrixMode((GLenum)lua_tointeger(L,1));
	return 0;
}
int API_glNewList(lua_State*L)
{
	glNewList((GLuint)lua_tointeger(L,1),(GLenum)lua_tointeger(L,2));
	return 0;
}
int API_glNormal3b(lua_State*L)
{
	glNormal3b((GLbyte)lua_tointeger(L,1),(GLbyte)lua_tointeger(L,2),(GLbyte)lua_tointeger(L,3));
	return 0;
}
int API_glNormal3d(lua_State*L)
{
	glNormal3d((GLdouble)lua_tonumber(L,1),(GLdouble)lua_tonumber(L,2),(GLdouble)lua_tonumber(L,3));
	return 0;
}
int API_glNormal3f(lua_State*L)
{
	glNormal3f((GLfloat)lua_tonumber(L,1),(GLfloat)lua_tonumber(L,2),(GLfloat)lua_tonumber(L,3));
	return 0;
}
int API_glNormal3i(lua_State*L)
{
	glNormal3i((GLint)lua_tointeger(L,1),(GLint)lua_tointeger(L,2),(GLint)lua_tointeger(L,3));
	return 0;
}
int API_glNormal3s(lua_State*L)
{
	glNormal3s((GLshort)lua_tointeger(L,1),(GLshort)lua_tointeger(L,2),(GLshort)lua_tointeger(L,3));
	return 0;
}
int API_glOrtho(lua_State*L)
{
	glOrtho((GLdouble)lua_tonumber(L,1),(GLdouble)lua_tonumber(L,2),(GLdouble)lua_tonumber(L,3),(GLdouble)lua_tonumber(L,4),(GLdouble)lua_tonumber(L,5),(GLdouble)lua_tonumber(L,6));
	return 0;
}
int API_glPassThrough(lua_State*L)
{
	glPassThrough((GLfloat)lua_tonumber(L,1));
	return 0;
}
int API_glPixelStoref(lua_State*L)
{
	glPixelStoref((GLenum)lua_tointeger(L,1),(GLfloat)lua_tonumber(L,2));
	return 0;
}
int API_glPixelStorei(lua_State*L)
{
	glPixelStorei((GLenum)lua_tointeger(L,1),(GLint)lua_tointeger(L,2));
	return 0;
}
int API_glPixelTransferf(lua_State*L)
{
	glPixelTransferf((GLenum)lua_tointeger(L,1),(GLfloat)lua_tonumber(L,2));
	return 0;
}
int API_glPixelTransferi(lua_State*L)
{
	glPixelTransferi((GLenum)lua_tointeger(L,1),(GLint)lua_tointeger(L,2));
	return 0;
}
int API_glPixelZoom(lua_State*L)
{
	glPixelZoom((GLfloat)lua_tonumber(L,1),(GLfloat)lua_tonumber(L,2));
	return 0;
}
int API_glPointSize(lua_State*L)
{
	glPointSize((GLfloat)lua_tonumber(L,1));
	return 0;
}
int API_glPolygonMode(lua_State*L)
{
	glPolygonMode((GLenum)lua_tointeger(L,1),(GLenum)lua_tointeger(L,2));
	return 0;
}
int API_glPolygonOffset(lua_State*L)
{
	glPolygonOffset((GLfloat)lua_tonumber(L,1),(GLfloat)lua_tonumber(L,2));
	return 0;
}
int API_glPopAttrib(lua_State*L)
{
	glPopAttrib();
	return 0;
}
int API_glPopClientAttrib(lua_State*L)
{
	glPopClientAttrib();
	return 0;
}
int API_glPopMatrix(lua_State*L)
{
	glPopMatrix();
	return 0;
}
int API_glPopName(lua_State*L)
{
	glPopName();
	return 0;
}
int API_glPushAttrib(lua_State*L)
{
	int argC = lua_gettop(L);
	unsigned int temp=0;
	for (int i = 0; i < argC; ++i)
	{
		temp |= lua_tointeger(L, i+1);
	}
	glPushAttrib((GLbitfield)temp);
	return 0;
}
int API_glPushClientAttrib(lua_State*L)
{
	int argC = lua_gettop(L);
	unsigned int temp=0;
	for (int i = 0; i < argC; ++i)
	{
		temp |= lua_tointeger(L, i+1);
	}
	glPushClientAttrib((GLbitfield)temp);
	return 0;
}
int API_glPushMatrix(lua_State*L)
{
	glPushMatrix();
	return 0;
}
int API_glPushName(lua_State*L)
{
	glPushName((GLuint)lua_tointeger(L,1));
	return 0;
}
int API_glRasterPos2d(lua_State*L)
{
	glRasterPos2d((GLdouble)lua_tonumber(L,1),(GLdouble)lua_tonumber(L,2));
	return 0;
}
int API_glRasterPos2f(lua_State*L)
{
	glRasterPos2f((GLfloat)lua_tonumber(L,1),(GLfloat)lua_tonumber(L,2));
	return 0;
}
int API_glRasterPos2i(lua_State*L)
{
	glRasterPos2i((GLint)lua_tointeger(L,1),(GLint)lua_tointeger(L,2));
	return 0;
}
int API_glRasterPos2s(lua_State*L)
{
	glRasterPos2s((GLshort)lua_tointeger(L,1),(GLshort)lua_tointeger(L,2));
	return 0;
}
int API_glRasterPos3d(lua_State*L)
{
	glRasterPos3d((GLdouble)lua_tonumber(L,1),(GLdouble)lua_tonumber(L,2),(GLdouble)lua_tonumber(L,3));
	return 0;
}
int API_glRasterPos3f(lua_State*L)
{
	glRasterPos3f((GLfloat)lua_tonumber(L,1),(GLfloat)lua_tonumber(L,2),(GLfloat)lua_tonumber(L,3));
	return 0;
}
int API_glRasterPos3i(lua_State*L)
{
	glRasterPos3i((GLint)lua_tointeger(L,1),(GLint)lua_tointeger(L,2),(GLint)lua_tointeger(L,3));
	return 0;
}
int API_glRasterPos3s(lua_State*L)
{
	glRasterPos3s((GLshort)lua_tointeger(L,1),(GLshort)lua_tointeger(L,2),(GLshort)lua_tointeger(L,3));
	return 0;
}
int API_glRasterPos4d(lua_State*L)
{
	glRasterPos4d((GLdouble)lua_tonumber(L,1),(GLdouble)lua_tonumber(L,2),(GLdouble)lua_tonumber(L,3),(GLdouble)lua_tonumber(L,4));
	return 0;
}
int API_glRasterPos4f(lua_State*L)
{
	glRasterPos4f((GLfloat)lua_tonumber(L,1),(GLfloat)lua_tonumber(L,2),(GLfloat)lua_tonumber(L,3),(GLfloat)lua_tonumber(L,4));
	return 0;
}
int API_glRasterPos4i(lua_State*L)
{
	glRasterPos4i((GLint)lua_tointeger(L,1),(GLint)lua_tointeger(L,2),(GLint)lua_tointeger(L,3),(GLint)lua_tointeger(L,4));
	return 0;
}
int API_glRasterPos4s(lua_State*L)
{
	glRasterPos4s((GLshort)lua_tointeger(L,1),(GLshort)lua_tointeger(L,2),(GLshort)lua_tointeger(L,3),(GLshort)lua_tointeger(L,4));
	return 0;
}
int API_glReadBuffer(lua_State*L)
{
	glReadBuffer((GLenum)lua_tointeger(L,1));
	return 0;
}
int API_glRectd(lua_State*L)
{
	glRectd((GLdouble)lua_tonumber(L,1),(GLdouble)lua_tonumber(L,2),(GLdouble)lua_tonumber(L,3),(GLdouble)lua_tonumber(L,4));
	return 0;
}
int API_glRectf(lua_State*L)
{
	glRectf((GLfloat)lua_tonumber(L,1),(GLfloat)lua_tonumber(L,2),(GLfloat)lua_tonumber(L,3),(GLfloat)lua_tonumber(L,4));
	return 0;
}
int API_glRecti(lua_State*L)
{
	glRecti((GLint)lua_tointeger(L,1),(GLint)lua_tointeger(L,2),(GLint)lua_tointeger(L,3),(GLint)lua_tointeger(L,4));
	return 0;
}
int API_glRects(lua_State*L)
{
	glRects((GLshort)lua_tointeger(L,1),(GLshort)lua_tointeger(L,2),(GLshort)lua_tointeger(L,3),(GLshort)lua_tointeger(L,4));
	return 0;
}
int API_glRenderMode(lua_State*L)
{
	glRenderMode((GLenum)lua_tointeger(L,1));
	return 1;
}
int API_glRotated(lua_State*L)
{
	glRotated((GLdouble)lua_tonumber(L,1),(GLdouble)lua_tonumber(L,2),(GLdouble)lua_tonumber(L,3),(GLdouble)lua_tonumber(L,4));
	return 0;
}
int API_glRotatef(lua_State*L)
{
	glRotatef((GLfloat)lua_tonumber(L,1),(GLfloat)lua_tonumber(L,2),(GLfloat)lua_tonumber(L,3),(GLfloat)lua_tonumber(L,4));
	return 0;
}
int API_glScaled(lua_State*L)
{
	glScaled((GLdouble)lua_tonumber(L,1),(GLdouble)lua_tonumber(L,2),(GLdouble)lua_tonumber(L,3));
	return 0;
}
int API_glScalef(lua_State*L)
{
	glScalef((GLfloat)lua_tonumber(L,1),(GLfloat)lua_tonumber(L,2),(GLfloat)lua_tonumber(L,3));
	return 0;
}
int API_glScissor(lua_State*L)
{
	glScissor((GLint)lua_tointeger(L,1),(GLint)lua_tointeger(L,2),(GLsizei)lua_tointeger(L,3),(GLsizei)lua_tointeger(L,4));
	return 0;
}
int API_glShadeModel(lua_State*L)
{
	glShadeModel((GLenum)lua_tointeger(L,1));
	return 0;
}
int API_glStencilFunc(lua_State*L)
{
	glStencilFunc((GLenum)lua_tointeger(L,1),(GLint)lua_tointeger(L,2),(GLuint)lua_tointeger(L,3));
	return 0;
}
int API_glStencilMask(lua_State*L)
{
	glStencilMask((GLuint)lua_tointeger(L,1));
	return 0;
}
int API_glStencilOp(lua_State*L)
{
	glStencilOp((GLenum)lua_tointeger(L,1),(GLenum)lua_tointeger(L,2),(GLenum)lua_tointeger(L,3));
	return 0;
}
int API_glTexCoord1d(lua_State*L)
{
	glTexCoord1d((GLdouble)lua_tonumber(L,1));
	return 0;
}
int API_glTexCoord1f(lua_State*L)
{
	glTexCoord1f((GLfloat)lua_tonumber(L,1));
	return 0;
}
int API_glTexCoord1i(lua_State*L)
{
	glTexCoord1i((GLint)lua_tointeger(L,1));
	return 0;
}
int API_glTexCoord1s(lua_State*L)
{
	glTexCoord1s((GLshort)lua_tointeger(L,1));
	return 0;
}
int API_glTexCoord2d(lua_State*L)
{
	glTexCoord2d((GLdouble)lua_tonumber(L,1),(GLdouble)lua_tonumber(L,2));
	return 0;
}
int API_glTexCoord2f(lua_State*L)
{
	glTexCoord2f((GLfloat)lua_tonumber(L,1),(GLfloat)lua_tonumber(L,2));
	return 0;
}
int API_glTexCoord2i(lua_State*L)
{
	glTexCoord2i((GLint)lua_tointeger(L,1),(GLint)lua_tointeger(L,2));
	return 0;
}
int API_glTexCoord2s(lua_State*L)
{
	glTexCoord2s((GLshort)lua_tointeger(L,1),(GLshort)lua_tointeger(L,2));
	return 0;
}
int API_glTexCoord3d(lua_State*L)
{
	glTexCoord3d((GLdouble)lua_tonumber(L,1),(GLdouble)lua_tonumber(L,2),(GLdouble)lua_tonumber(L,3));
	return 0;
}
int API_glTexCoord3f(lua_State*L)
{
	glTexCoord3f((GLfloat)lua_tonumber(L,1),(GLfloat)lua_tonumber(L,2),(GLfloat)lua_tonumber(L,3));
	return 0;
}
int API_glTexCoord3i(lua_State*L)
{
	glTexCoord3i((GLint)lua_tointeger(L,1),(GLint)lua_tointeger(L,2),(GLint)lua_tointeger(L,3));
	return 0;
}
int API_glTexCoord3s(lua_State*L)
{
	glTexCoord3s((GLshort)lua_tointeger(L,1),(GLshort)lua_tointeger(L,2),(GLshort)lua_tointeger(L,3));
	return 0;
}
int API_glTexCoord4d(lua_State*L)
{
	glTexCoord4d((GLdouble)lua_tonumber(L,1),(GLdouble)lua_tonumber(L,2),(GLdouble)lua_tonumber(L,3),(GLdouble)lua_tonumber(L,4));
	return 0;
}
int API_glTexCoord4f(lua_State*L)
{
	glTexCoord4f((GLfloat)lua_tonumber(L,1),(GLfloat)lua_tonumber(L,2),(GLfloat)lua_tonumber(L,3),(GLfloat)lua_tonumber(L,4));
	return 0;
}
int API_glTexCoord4i(lua_State*L)
{
	glTexCoord4i((GLint)lua_tointeger(L,1),(GLint)lua_tointeger(L,2),(GLint)lua_tointeger(L,3),(GLint)lua_tointeger(L,4));
	return 0;
}
int API_glTexCoord4s(lua_State*L)
{
	glTexCoord4s((GLshort)lua_tointeger(L,1),(GLshort)lua_tointeger(L,2),(GLshort)lua_tointeger(L,3),(GLshort)lua_tointeger(L,4));
	return 0;
}
int API_glTexEnvf(lua_State*L)
{
	glTexEnvf((GLenum)lua_tointeger(L,1),(GLenum)lua_tointeger(L,2),(GLfloat)lua_tonumber(L,3));
	return 0;
}
int API_glTexEnvi(lua_State*L)
{
	glTexEnvi((GLenum)lua_tointeger(L,1),(GLenum)lua_tointeger(L,2),(GLint)lua_tointeger(L,3));
	return 0;
}
int API_glTexGend(lua_State*L)
{
	glTexGend((GLenum)lua_tointeger(L,1),(GLenum)lua_tointeger(L,2),(GLdouble)lua_tonumber(L,3));
	return 0;
}
int API_glTexGenf(lua_State*L)
{
	glTexGenf((GLenum)lua_tointeger(L,1),(GLenum)lua_tointeger(L,2),(GLfloat)lua_tonumber(L,3));
	return 0;
}
int API_glTexGeni(lua_State*L)
{
	glTexGeni((GLenum)lua_tointeger(L,1),(GLenum)lua_tointeger(L,2),(GLint)lua_tointeger(L,3));
	return 0;
}
int API_glTexParameterf(lua_State*L)
{
	glTexParameterf((GLenum)lua_tointeger(L,1),(GLenum)lua_tointeger(L,2),(GLfloat)lua_tonumber(L,3));
	return 0;
}
int API_glTexParameteri(lua_State*L)
{
	glTexParameteri((GLenum)lua_tointeger(L,1),(GLenum)lua_tointeger(L,2),(GLint)lua_tointeger(L,3));
	return 0;
}
int API_glTranslated(lua_State*L)
{
	glTranslated((GLdouble)lua_tonumber(L,1),(GLdouble)lua_tonumber(L,2),(GLdouble)lua_tonumber(L,3));
	return 0;
}
int API_glTranslatef(lua_State*L)
{
	glTranslatef((GLfloat)lua_tonumber(L,1),(GLfloat)lua_tonumber(L,2),(GLfloat)lua_tonumber(L,3));
	return 0;
}
int API_glVertex2d(lua_State*L)
{
	glVertex2d((GLdouble)lua_tonumber(L,1),(GLdouble)lua_tonumber(L,2));
	return 0;
}
int API_glVertex2f(lua_State*L)
{
	glVertex2f((GLfloat)lua_tonumber(L,1),(GLfloat)lua_tonumber(L,2));
	return 0;
}
int API_glVertex2i(lua_State*L)
{
	glVertex2i((GLint)lua_tointeger(L,1),(GLint)lua_tointeger(L,2));
	return 0;
}
int API_glVertex2s(lua_State*L)
{
	glVertex2s((GLshort)lua_tointeger(L,1),(GLshort)lua_tointeger(L,2));
	return 0;
}
int API_glVertex3d(lua_State*L)
{
	glVertex3d((GLdouble)lua_tonumber(L,1),(GLdouble)lua_tonumber(L,2),(GLdouble)lua_tonumber(L,3));
	return 0;
}
int API_glVertex3f(lua_State*L)
{
	glVertex3f((GLfloat)lua_tonumber(L,1),(GLfloat)lua_tonumber(L,2),(GLfloat)lua_tonumber(L,3));
	return 0;
}
int API_glVertex3i(lua_State*L)
{
	glVertex3i((GLint)lua_tointeger(L,1),(GLint)lua_tointeger(L,2),(GLint)lua_tointeger(L,3));
	return 0;
}
int API_glVertex3s(lua_State*L)
{
	glVertex3s((GLshort)lua_tointeger(L,1),(GLshort)lua_tointeger(L,2),(GLshort)lua_tointeger(L,3));
	return 0;
}
int API_glVertex4d(lua_State*L)
{
	glVertex4d((GLdouble)lua_tonumber(L,1),(GLdouble)lua_tonumber(L,2),(GLdouble)lua_tonumber(L,3),(GLdouble)lua_tonumber(L,4));
	return 0;
}
int API_glVertex4f(lua_State*L)
{
	glVertex4f((GLfloat)lua_tonumber(L,1),(GLfloat)lua_tonumber(L,2),(GLfloat)lua_tonumber(L,3),(GLfloat)lua_tonumber(L,4));
	return 0;
}
int API_glVertex4i(lua_State*L)
{
	glVertex4i((GLint)lua_tointeger(L,1),(GLint)lua_tointeger(L,2),(GLint)lua_tointeger(L,3),(GLint)lua_tointeger(L,4));
	return 0;
}
int API_glVertex4s(lua_State*L)
{
	glVertex4s((GLshort)lua_tointeger(L,1),(GLshort)lua_tointeger(L,2),(GLshort)lua_tointeger(L,3),(GLshort)lua_tointeger(L,4));
	return 0;
}
int API_glViewport(lua_State*L)
{
	glViewport((GLint)lua_tointeger(L,1),(GLint)lua_tointeger(L,2),(GLsizei)lua_tointeger(L,3),(GLsizei)lua_tointeger(L,4));
	return 0;
}
