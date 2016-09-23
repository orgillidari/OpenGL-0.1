#include <stdio.h>

#include "NTWindow.h"

using namespace illidan;

int __stdcall WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//重定向输出日志
	freopen("main.log", "w", stdout);

	//创建窗口
	NTWindow::RegisterInstance(hInstance);
	NTWindow::RegisterNTWindowClass(L"OpenGL");

	NTWindow* pWindow = new NTWindow();
	pWindow->CreateNTWindow(L"OpenGL", L"Demo", 1280, 800);
	pWindow->UpdateNTWindow();

	NTWindow::ClearNTWindowClass();

	//关闭输出日志
	fclose(stdout);
	return 0;
}