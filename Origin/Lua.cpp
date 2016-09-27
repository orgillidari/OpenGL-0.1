#include "Lua.h"

#include "ExportOpenGLAPI.h"


namespace illidan
{
	void Lua::PrintError(lua_State* L, int sErr)
	{
		if (sErr == 0)
		{
			return;
		}

		const char* error;
		char sErrorType[256] = { 0 };
		switch (sErr)
		{
		case LUA_ERRSYNTAX://编译时错误  
			sprintf_s(sErrorType, sizeof(sErrorType), "%s", "syntax error during pre-compilation");
			break;
		case LUA_ERRMEM://内存错误  
			sprintf_s(sErrorType, sizeof(sErrorType), "%s", "memory allocation error");
			break;
		case LUA_ERRRUN://运行时错误
			sprintf_s(sErrorType, sizeof(sErrorType), "%s", "a runtime error");
			break;
		case LUA_YIELD://线程被挂起错误  
			sprintf_s(sErrorType, sizeof(sErrorType), "%s", "Thread has Suspended");
			break;
		case LUA_ERRERR://在进行错误处理时发生错误  
			sprintf_s(sErrorType, sizeof(sErrorType), "%s", "error while running the error handler function");
			break;
		default:
			break;
		}
		error = lua_tostring(L, -1);//打印错误结果  
		printf("%s:%s", sErrorType, error);
		lua_pop(L, 1);
	}

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

	void Lua::ExportOpenGLAPI()
	{
		ExportGLAPI(m_L);
		ExportGLUAPI(m_L);
	}

	int Lua::CallFile(const char* pFile)
	{
		int res = luaL_dofile(m_L, pFile);
		if (res)
		{
			PrintError(m_L, res);
			return -1;
		}
		return 0;
	}

	int Lua::CallFunction(const char* pFunctionName)
	{
		lua_getglobal(m_L, pFunctionName);
		int res = lua_pcall(m_L, 0, 0, 0);
		if (res)
		{
			PrintError(m_L, res);
			return -1;
		}
		return 0;
	}

	int Lua::CallFunction(const char* pFunctionName, int a, int b, int& r)
	{
		lua_getglobal(m_L, pFunctionName);
		lua_pushnumber(m_L, a);
		lua_pushnumber(m_L, b);
		int res = lua_pcall(m_L, 2, 1, 0);
		if (res)
		{
			PrintError(m_L, res);
			return -1;
		}
		r = (int)lua_tonumber(m_L, -1);
		return 0;
	}

	void Lua::Destroy()
	{
		lua_close(m_L);
	}
}