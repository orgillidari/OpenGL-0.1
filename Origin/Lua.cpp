#include "Lua.h"


namespace illidan
{
	//Lua::Lua()
	//{
	//}

	//Lua::Lua(const Lua& that)
	//{

	//}

	//Lua& Lua::operator=(const Lua& that)
	//{

	//}

	//Lua::~Lua()
	//{

	//}

	void Lua::Init()
	{
		m_L = luaL_newstate();
		luaL_openlibs(m_L);
	}

	void Lua::CallFile(const char* pFile)
	{
		luaL_dofile(m_L, pFile);
	}

	int Lua::CallFunction(const char* pFunctionName)
	{
		lua_getglobal(m_L, pFunctionName);
		int cr = lua_pcall(m_L, 0, 0, 0);
		if (cr)
		{
			return -1;
		}
		return 0;
	}

	int Lua::CallFunction(const char* pFunctionName, int a, int b, int& r)
	{
		lua_getglobal(m_L, pFunctionName);
		lua_pushnumber(m_L, a);
		lua_pushnumber(m_L, b);
		int cr = lua_pcall(m_L, 2, 1, 0);
		if (cr)
		{
			return -1;
		}
		r = lua_tonumber(m_L, -1);
		return 0;
	}

	void Lua::Destroy()
	{
		lua_close(m_L);
	}
}