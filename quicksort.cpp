#include <iostream>
#include <stdio.h>
using namespace std;
void ShowSeqList();

#define MAXLISTLEN 20
//定义顺序表
typedef struct 
{
    int Key[MAXLISTLEN];
    int Len;
}List;
List SeqList;
//快速排序函数
int FirstQuick='T';
void QuickSort( int low,int high)
{
     int i,j,Pivotkey,k;
     int temp;

     i=low;
     j=high;
     Pivotkey=SeqList.Key[low];

     while (low<high)
     {
         for ( k = high; k >= low; k--)
         {
             if( SeqList.Key[k]<Pivotkey){
               temp=SeqList.Key[low];
               SeqList.Key[low]=SeqList.Key[k] ;
               SeqList.Key[k]=temp;
               low ++;
               break;
             }
         }
         for ( k = low; k <= high; k++)
         {
             if( SeqList.Key[k]>Pivotkey){
              temp=SeqList.Key[high];
              SeqList.Key[high]=SeqList.Key[k];
              SeqList.Key[k]=temp;
               high --;
               break;
             }
         }
         if(high-low==1 && SeqList.Key[low]==SeqList.Key[high]) break;
    }
    if(FirstQuick=='T') ShowSeqList();
    FirstQuick='F';
    if(i<(low-1)) QuickSort(i,low-1);
    if(high+1<j)  QuickSort(high+1,j);
}
//顺序表显示函数
void ShowSeqList()
{
    int i;
    for ( i = 1; i < SeqList.Len; i++)
    {
        cout << SeqList.Key[i] << " ";
    }
    cout << SeqList.Key[i]<< endl;
}
//主函数
int main(int argc,char *argv[])
{
    int i;
    cin >> SeqList.Len;
    for ( i = 1; i <= SeqList.Len; i++)
    {
        cin >> SeqList.Key[i];
    }
    ShowSeqList();
    QuickSort(1,SeqList.Len);
    ShowSeqList();

    system("pause");
    return 1;
}