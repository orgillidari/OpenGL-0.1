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

	public:
		//Lua();
		//Lua(const Lua& that);
		//Lua& operator=(const Lua& that);
		//virtual ~Lua();

		void Init();
		void CallFile(const char* pFile);
		int CallFunction(const char* pFunctionName);
		int CallFunction(const char* pFunctionName, int p1, int p2, int& r);
		void Destroy();
	};
}
