#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include "OpenGLUAPI.h"


int API_gluPerspective(lua_State*L)
{
	gluPerspective((GLdouble)lua_tointeger(L, 1), (GLdouble)lua_tointeger(L, 2), (GLdouble)lua_tointeger(L, 3), (GLdouble)lua_tointeger(L, 4));
	return 0;
}

