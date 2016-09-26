#pragma once

#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include "OpenGLAPI.h"
#include "OpenGLUAPI.h"

int ExportGLAPI(lua_State*L);

int ExportGLUAPI(lua_State*L);