#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


#include<string.h>

#pragma comment(lib,"winmm.lib") //���Ӿ�̬��
void play();//��������
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
	system("cls");//����
	system("color f4");
	printf("\t\t\t\t��ӭʹ��!!!\n\n");
	printf("1.������\t\t2.���Ű���\t\t3.��������\t\t0.�˳�\n\n");
	while(1)
	{
		printf("��ѡ��:");
		if(scanf("%d",&opt)==0)
		{
			while(getchar()!='\n');//��ջ�����
			opt=-1;
		}
		switch(opt)
		{
			case 0:return 1;
			case 1:
			{
				system("cls");//����
				printf("��ѡ����ǲ��Ű���!\n\n");
				printf("���Կ�ʼ���٣��س���������!!!!!\n\n");
				play();//������
				goto loop;
			}break;
			case 2:
			{
				system("cls");//����
				printf("1.ͯ��\t2.�������ʹ\t3.С����\t0.����\n\n");
				printf("��������Ҫѡ�񲥷ŵİ���:");
				while(1)
					{
						if(scanf("%d",&opt)==0)
							{
								while(getchar()!='\n');//��ջ�����
								opt=-1;
							}
					switch(opt)
						{case 0:goto loop;
						case 1:
						{
							printf("\n\n���ڲ��Ű��ࡶͯ����......\n\n");
							sing(music);
						}
						case 2:
						{
							printf("\n\n���ڲ��Ű��ࡶ�������ʹ��......\n\n");
							sing(music1);
						}break;
						case 3:
						{
							printf("\n\n���ڲ��Ű��ࡶС���ǡ�......\n\n");
							sing(music2);
						}break;
						default:
						{
							printf("�������ѡ������");
							printf("3����˳�!\n\n");
							Sleep(1800);
						}
					}
				}
				
			}break;
			case 3:
			{
				system("cls");//����
				printf("1.��İ���\t2.��С��\t3.�������\t0.����\n\n");
				printf("��������Ҫѡ�񲥷ŵĸ���:");
				while(1)
					{
						if(scanf("%d",&opt)==0)
							{
								while(getchar()!='\n');//��ջ�����
								opt=-1;
							}
					switch(opt)
						{case 0:goto loop;
						case 1:
						{
							printf("\n\n���ڲ��Ÿ�������İ��㡷......\n\n");
							sang(1);
						}
						case 2:
						{
							printf("\n\n���ڲ��Ű��ࡶ��С����......\n\n");
							sang(2);
						}break;
						case 3:
						{
							printf("\n\n���ڲ��Ű��ࡶ������衷......\n\n");
							sang(3);
						}break;
						default:
						{
							printf("�������ѡ������");
							printf("3����˳�!\n\n");
							Sleep(1800);
						}
					}
				}
			}break;
			default:	
				printf("�������ѡ������");		
		}
	}
	

	return 0;
}


//�ֶ�������
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
//��������
void sang(int m)
{
	sprintf(cmd,"play singsang//%d.mp3",m);
	mciSendString(cmd,NULL,0,NULL);//�������ֺ���
	Sleep(2400000);
}

//���Ű���
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