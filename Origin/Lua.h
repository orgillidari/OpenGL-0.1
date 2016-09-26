#pragma once

extern "C"
{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}


namespace illidan
{
	class Lua
	{
	private:
		lua_State* m_L;

	private:
		void PrintError(lua_State* L, int sErr);

	public:
		//Lua();
		//Lua(const Lua& that);
		//Lua& operator=(const Lua& that);
		//virtual ~Lua();

		void Init();
		void ExportOpenGLAPI();
		int CallFile(const char* pFile);
		int CallFunction(const char* pFunctionName);
		int CallFunction(const char* pFunctionName, int p1, int p2, int& r);
		void Destroy();
	};
}
