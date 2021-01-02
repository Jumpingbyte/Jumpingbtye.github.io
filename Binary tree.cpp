#include <iostream>
using namespace std;

struct BiNode{             //树的存储结构
  char data;
  BiNode *Ichild,*rchild;
};
BiNode *BiTree;  

BiNode *CreateBiTree(char *c,int i,int n)   //将二叉树的顺序结构转变为二叉链表结构
{
  BiNode *T;

  if(i>n) return(NULL);
  if(c[i]=='0') return(NULL);
  T=new BiNode;
  T->data=c[i];
  T->Ichild=CreateBiTree(c,2*i,n);
  T->rchild=CreateBiTree(c,2*i+1,n);
  return(T);
}                                    


void PreOrderTraverse(BiNode *T){     //先根遍历二叉树
 if(T){
   cout<< T->data;
   PreOrderTraverse(T->Ichild);
   PreOrderTraverse(T->rchild);
 }

}


void InOrderTraverse(BiNode *T){     //中根遍历二叉树
 if(T){InOrderTraverse(T->Ichild);
       cout<< T->data;
       InOrderTraverse(T->rchild);
       }
}

void PostOrderTraverse(BiNode *T){  //后根遍历二叉树
if (T)
{
  PostOrderTraverse(T->Ichild);
  PostOrderTraverse(T->rchild);
  cout<< T->data;
}

}

int main(){
  int i,SampleNum;
  char c[100];

  cin>>SampleNum;
  for(i=1;i<=SampleNum;i++) cin>>c[i];
  BiTree=CreateBiTree(c,1,SampleNum);
  PreOrderTraverse(BiTree); cout<<endl;
  InOrderTraverse(BiTree); cout<<endl;
  PostOrderTraverse(BiTree); cout<<endl;
  system("pause");
  return 0;
  
}