#include<stdio.h>
#include<windows.h>
#include "itmojun.h"//同目录下自己编写的文件

#pragma comment(lib,"itmojun.lib")//链接库
#pragma comment(lib,"winmm.lib")
//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )//隐藏命令窗口

int main()
{
	char msg[10];
	system("color f4");
//	AutoRun();//开机自动运行
	while(1){
		GetPCCmd("yq",msg);//接受微信端发送的命令
		printf("%s",msg);
		if(strstr(msg,"播放"))
		{
			mciSendString("play bg.mp3",NULL,0,NULL);//播放歌曲
		}
		else if(strstr(msg,"暂停"))
		{
			mciSendString("pause bg.mp3",NULL,0,NULL);//暂停播放
		}
		else if(strstr(msg,"关机"))
		{
			WinExec("shutdown -s -t 0",0);//关机
		}
		else if(strstr(msg,"关QQ"))
		{
			WinExec("cmd /C taskkill /f /im qq.exe",0);//关掉QQ进程
		}
		else if(strstr(msg,"关桌面"))
		{
			//WinExec("cmd /C taskkill /f /im explorer.exe",0); //关桌面
			//1.找到窗口
			//2.关闭窗口
			HWND desktop,taskker;
			desktop=FindWindow("ProgMan",NULL);//找到桌面句柄
			taskker=FindWindow("Shell_TrayWnd",NULL);//找到任务了句柄

			ShowWindow(desktop,SW_HIDE);//关闭桌面
			ShowWindow(taskker,SW_HIDE);//关闭任务栏
		}
		else if(strstr(msg,"打开桌面"))
		{
			//WinExec("C:\\windows\\explorer.exe",1);//打开桌面
			HWND desktop,taskker;
			desktop=FindWindow("ProgMan",NULL);//找到桌面句柄
			taskker=FindWindow("Shell_TrayWnd",NULL);//找到任务了句柄

			ShowWindow(desktop,SW_SHOW);
			ShowWindow(taskker,SW_SHOW);
		}
		else if(strstr(msg,"killself"))
		{
			WinExec("cmd /C taskkill /f /im main.exe",0);
		}
		else if(strstr(msg,"百度"))
		{
			WinExec("explorer http://www.baidu.com",1);//打开百度
		}
		
		Sleep(3000);
	}

	return 0;
}

