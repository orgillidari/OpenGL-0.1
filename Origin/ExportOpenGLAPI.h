#pragma once

#include <windows.h>
#include "OpenGLAPI.h"
#include "OpenGLUAPI.h"
#include <gl/GL.h>
#include <gl/GLU.h>


int ExportGLAPI(lua_State*L);

int ExportGLUAPI(lua_State*L);