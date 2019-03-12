#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


#include<string.h>

#pragma comment(lib,"winmm.lib") //链接静态库
void play();//函数声明
void sang(int m);
void sing(const char* mci);

char c ;
char cmd[200];
char music[200]="LONOL LONOL LONO OOMMLLONOL LQPPO LONOM MMOTS PPRRQQ QQNPOONO ONOR LSRQPPPRRQQ QQVUTUV VPOT TTSSSLSRQQRQ QRQ RQPOOQST TTSPPRQ OQST TTSPPRQRQPO PQMMOONO";
char music1[200]="STVTXXTW  WWVUVWXWSV VUTUVRRRVVWVSSS SYXWXX  STVTXXTW  WWVUVWXWSVV VUTUVRRRVVWVSSS  STUVVUVV";
char music2[200]="OOSSTTS   RRQQPPO SSRRQQP   SSRRQQPOOSSTTS   RRQQPPO";
int i=0,j=0;
int main()
{	
	int opt;
loop:
	system("cls");//清屏
	system("color f4");
	printf("\t\t\t\t欢迎使用!!!\n\n");
	printf("1.弹钢琴\t\t2.播放伴奏\t\t3.播放音乐\t\t0.退出\n\n");
	while(1)
	{
		printf("请选择:");
		if(scanf("%d",&opt)==0)
		{
			while(getchar()!='\n');//清空缓冲区
			opt=-1;
		}
		switch(opt)
		{
			case 0:return 1;
			case 1:
			{
				system("cls");//清屏
				printf("你选择的是播放伴奏!\n\n");
				printf("可以开始弹琴（回车键结束）!!!!!\n\n");
				play();//弹钢琴
				goto loop;
			}break;
			case 2:
			{
				system("cls");//清屏
				printf("1.童话\t2.会呼吸的痛\t3.小星星\t0.返回\n\n");
				printf("请输入你要选择播放的伴奏:");
				while(1)
					{
						if(scanf("%d",&opt)==0)
							{
								while(getchar()!='\n');//清空缓冲区
								opt=-1;
							}
					switch(opt)
						{case 0:goto loop;
						case 1:
						{
							printf("\n\n正在播放伴奏《童话》......\n\n");
							sing(music);
						}
						case 2:
						{
							printf("\n\n正在播放伴奏《会呼吸的痛》......\n\n");
							sing(music1);
						}break;
						case 3:
						{
							printf("\n\n正在播放伴奏《小星星》......\n\n");
							sing(music2);
						}break;
						default:
						{
							printf("您输入的选项有误！");
							printf("3秒后退出!\n\n");
							Sleep(1800);
						}
					}
				}
				
			}break;
			case 3:
			{
				system("cls");//清屏
				printf("1.真的爱你\t2.笨小孩\t3.单身情歌\t0.返回\n\n");
				printf("请输入你要选择播放的歌曲:");
				while(1)
					{
						if(scanf("%d",&opt)==0)
							{
								while(getchar()!='\n');//清空缓冲区
								opt=-1;
							}
					switch(opt)
						{case 0:goto loop;
						case 1:
						{
							printf("\n\n正在播放歌曲《真的爱你》......\n\n");
							sang(1);
						}
						case 2:
						{
							printf("\n\n正在播放伴奏《笨小孩》......\n\n");
							sang(2);
						}break;
						case 3:
						{
							printf("\n\n正在播放伴奏《单身情歌》......\n\n");
							sang(3);
						}break;
						default:
						{
							printf("您输入的选项有误！");
							printf("3秒后退出!\n\n");
							Sleep(1800);
						}
					}
				}
			}break;
			default:	
				printf("您输入的选项有误！");		
		}
	}
	

	return 0;
}


//手动弹钢琴
void play()
{
	while(1)
	{
		c=getche();
		if(c=='\r') break;
		sprintf(cmd,"open sound//%c.mp3 alias s%d",c,i);
		mciSendString(cmd,NULL,0,NULL);

		sprintf(cmd,"play s%d",i);
		mciSendString(cmd,NULL,0,NULL);
		i++;
	}
}
//播放音乐
void sang(int m)
{
	sprintf(cmd,"play singsang//%d.mp3",m);
	mciSendString(cmd,NULL,0,NULL);//播放音乐函数
	Sleep(2400000);
}

//播放伴奏
void sing(const char* mci)
{
	for(j=0;j < strlen(mci);j++)
	{
		sprintf(cmd,"open sound//%c.mp3 alias s%d",mci[j],i);
		mciSendString(cmd,NULL,0,NULL);
		sprintf(cmd,"play s%d",i);
		mciSendString(cmd,NULL,0,NULL);
		i++;
		Sleep(500);
	}

}