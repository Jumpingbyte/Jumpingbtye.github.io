//2019282076 梁镇澎 综合实验4 主函数

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
 printf("请输入小球的个数：");scanf("%d",&n);
 if(n<1) num=1;
 else if(n>NUM) num=NUM;
 else num=n; //用户输入数据，然后数据矫正 
 
 struct BALL ball[num];
 initBall(ball,num);//初始化小球状态
  
 char cWin[24][80]={0};
 initCharPicture(cWin);//屏幕初始化
 printChar(cWin);//显示背景
 
 redrawCWin(ball,cWin,num);//输出小球实时位置图
 
 delay(1); 
 
 int t=0;//t为小球碰到地面的总次数 
 for(int i=0;i<50;i++)
 {
  system("cls");
  t+=moveBall(ball,cWin,num);
  delay(1); 	
 } 
 printf("触地数为%d",t); 	 
} 
