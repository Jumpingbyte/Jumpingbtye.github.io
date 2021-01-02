#include <iostream>
#include <stdio.h>
using namespace std;

//折半查找变量定义
int BinSuccess; //查找是否成功，成功为1
int BinPos;     //查找所得的位置，0为不成功
int BinCount;   //查找次数

int BinList[32]; //有序表
int BinListLen;  //有序表长度

void QuickSort(int*, int,int);//函数声明

//快速排序算法
void QuickSort(int *r, int low,int high)

{
     int i,j,Pivotkey,k;
     int temp;

     i=low;
     j=high;
     Pivotkey=r[low];

     while (low<high)
     {
         for ( k = high; k >= low; k--)
         {
             if( r[k]<Pivotkey){
               temp=r[low];
               r[low]=r[k] ;
               r[k]=temp;
               low ++;
               break;
             }
         }
         for ( k = low; k <= high; k++)
         {
             if( r[k]>Pivotkey){
              temp=r[high];
              r[high]=r[k];
              r[k]=temp;
               high --;
               break;
             }
         }
         if(high-low==1 && r[low]==r[high]) break;
    }
    if(i<(low-1)) QuickSort(r,i,low-1);
    if(high+1<j)  QuickSort(r,high+1,j);
}

//生成有序顺序表
void CreateSequence(int *r, int n)
{   
    int i;
    QuickSort(r,1,n);
    //将排好序的序列放到有序顺序表中
    for ( i = 1; i <= n; i++)
    {
        BinList[i] = r[i];
    }
    for ( i = 1; i <= n; i++)
    {
        cout << BinList[i] << " ";
    }
    
}

//折半查找算法实现
 int BinSearchKey (int Key)
 {
    int Low, Mid, High;
    Low = 1;
    High = BinListLen;

    BinSuccess = 0;
    BinPos = 0;
    BinCount = 0;

    while (Low <= High)
    {
        Mid = (Low + High)/2;
        BinCount++;
        if (Key == BinList[Mid])
        {
           BinSuccess = 1;
           BinPos = Mid;
           break;
        }
        if (Key < BinList[Mid])
        {
            High = Mid-1;
        }
        if (Key > BinList[Mid])
        {
            Low = Mid+1;
        }
    }
    return (BinCount);
 }

 //主函数
 int main()
 {
     int r[32];
     int i,j,Key;
     int TestNum,SampleNum;
     cout << "input testnum";
     cin >> TestNum;

     for ( i = 0; i < TestNum; i++)
     {
         cout << "input samplenum";
         cin >> SampleNum;
         BinListLen=SampleNum;
         cout << "input data";
         for ( j = 1; j <= SampleNum; j++)
         {
             cin >> r[j];
         }
         CreateSequence(r,SampleNum);

         cout << "input Key";
         cin >> Key;
         BinSearchKey(Key);
         cout << BinSuccess << " " << BinPos 
         << " " << BinCount << endl;
     }
     
     system("pause");
     return 0;

 }