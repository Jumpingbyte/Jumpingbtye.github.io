//2019282076 ������ �ۺ�ʵ��4 ������

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<windows.h>
#include"myhead..h"


#define NUM 5
#define pi 3.14 

void initCharPicture(char cWin[24][80]);
void printChar(char cWin[24][80]);
double randN1N2(int rN1,int rN2);
void initBall(struct BALL ball[],int num);
void redrawCWin(struct BALL ball[],int num);
int moveBall(struct BALL ball[], int num);
void delay(unsigned int nTime);

int main()
{
 srand((unsigned)time(NULL));
 
 system("cls");
 	
  
 
 int num,n; 	
 printf("������С��ĸ�����");scanf("%d",&n);
 if(n<1) num=1;
 else if(n>NUM) num=NUM;
 else num=n; //�û��������ݣ�Ȼ�����ݽ��� 
 
 struct BALL ball[num];
 initBall(ball,num);//��ʼ��С��״̬
  
 char cWin[24][80]={0};
 initCharPicture(cWin);//��Ļ��ʼ��
 printChar(cWin);//��ʾ����
 
 redrawCWin(ball,cWin,num);//���С��ʵʱλ��ͼ
 
 delay(1); 
 
 int t=0;//tΪС������������ܴ��� 
 for(int i=0;i<50;i++)
 {
  system("cls");
  t+=moveBall(ball,cWin,num);
  delay(1); 	
 } 
 printf("������Ϊ%d",t); 	 
} 
