#include<stdio.h>
#include<windows.h>
#include "itmojun.h"//ͬĿ¼���Լ���д���ļ�

#pragma comment(lib,"itmojun.lib")//���ӿ�
#pragma comment(lib,"winmm.lib")
//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )//���������

int main()
{
	char msg[10];
	system("color f4");
//	AutoRun();//�����Զ�����
	while(1){
		GetPCCmd("yq",msg);//����΢�Ŷ˷��͵�����
		printf("%s",msg);
		if(strstr(msg,"����"))
		{
			mciSendString("play bg.mp3",NULL,0,NULL);//���Ÿ���
		}
		else if(strstr(msg,"��ͣ"))
		{
			mciSendString("pause bg.mp3",NULL,0,NULL);//��ͣ����
		}
		else if(strstr(msg,"�ػ�"))
		{
			WinExec("shutdown -s -t 0",0);//�ػ�
		}
		else if(strstr(msg,"��QQ"))
		{
			WinExec("cmd /C taskkill /f /im qq.exe",0);//�ص�QQ����
		}
		else if(strstr(msg,"������"))
		{
			//WinExec("cmd /C taskkill /f /im explorer.exe",0); //������
			//1.�ҵ�����
			//2.�رմ���
			HWND desktop,taskker;
			desktop=FindWindow("ProgMan",NULL);//�ҵ�������
			taskker=FindWindow("Shell_TrayWnd",NULL);//�ҵ������˾��

			ShowWindow(desktop,SW_HIDE);//�ر�����
			ShowWindow(taskker,SW_HIDE);//�ر�������
		}
		else if(strstr(msg,"������"))
		{
			//WinExec("C:\\windows\\explorer.exe",1);//������
			HWND desktop,taskker;
			desktop=FindWindow("ProgMan",NULL);//�ҵ�������
			taskker=FindWindow("Shell_TrayWnd",NULL);//�ҵ������˾��

			ShowWindow(desktop,SW_SHOW);
			ShowWindow(taskker,SW_SHOW);
		}
		else if(strstr(msg,"killself"))
		{
			WinExec("cmd /C taskkill /f /im main.exe",0);
		}
		else if(strstr(msg,"�ٶ�"))
		{
			WinExec("explorer http://www.baidu.com",1);//�򿪰ٶ�
		}
		
		Sleep(3000);
	}

	return 0;
}

