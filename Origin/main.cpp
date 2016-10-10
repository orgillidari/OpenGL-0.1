#pragma warning(disable:4996)

#include <stdio.h>

#include "Lua.h"
#include "NTWindow.h"
#include "OpenGLWindow.h"


using namespace illidan;

INT WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//重定向输出日志
	freopen("main.log", "w", stdout);

	////创建Lua环境
	//Lua* lua = new Lua();
	//lua->Init();
	//lua->CallFile("main.lua");
	//lua->CallFunction("Test");

	//注册NTWindow信息
	NTWindow::RegisterInstance(hInstance);
	NTWindow::RegisterNTWindowClass(L"OpenGL");

	//创建NTWindow窗口
	NTWindow* pWindow = NTWindow::CreateNTWindow<OpenGLWindow>(L"OpenGL", L"Demo", 1280, 800);
	pWindow->Init();
	pWindow->UpdateNTWindow();
	pWindow->Destroy();

	//清除NTWindow信息
	NTWindow::ClearNTWindow();
	NTWindow::ClearNTWindowClass();

	////清除Lua环境
	//lua->Destroy();
	//delete lua;

	//关闭输出日志
	fclose(stdout);
	return 0;
}