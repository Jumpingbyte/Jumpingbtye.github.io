#include<iostream>
using namespace std;
#define ERROR -1
#define CORRECT 1

struct LNode{
       int data;
	   LNode *next;
};
LNode *LinkList;

LNode *SearchLinkList(LNode *L,int i)
{
	int j;
	LNode *p;
	p=L;
	j=1;
	while(p&&j<i)
	{
      p=p->next;
	  ++j;
	}
	if(!p||j>i) return(NULL);
	return(p);
}// SearchLinkList

int InsertLinkList(LNode *L,int e,int i)
{
 LNode *p,*s;
 p=SearchLinkList(L,i-1);if(!p) return(ERROR);
 s=new LNode;
 s->data=e;
 s->next=p->next;
 p->next=s;
 return(CORRECT);
}// InsertLinkList

LNode *CreateLinkList(int *r,int n)
{
  int j;
  LNode *L,*p,*s;

  if(n<=0) return(NULL);
  s=new LNode;
  s->data=r[1];
  s->next=NULL;
  L=s;
  p=L;
  for(j=2;j<=n;j++){
     s=new LNode;
	 s->data=r[j];
	 s->next=NULL;
	 p->next=s;
	 p=s;
  }
  return(L);
}

int DeleteLinkList(LNode *L,int i)
{
 int e;
 LNode *p,*q;

 p=SearchLinkList(L,i-1);if(!p)return(ERROR);
 q=p->next;
 p->next=q->next;
 e=q->data;delete(q);
 return(e);
}// DeleteLinkList


int ShowLinkList(LNode *L)
{
 LNode *p;
 if(!L) return(ERROR);
 p=L;
 while(p->next){
  cout<<p->data<<" ";
  p=p->next;
 }
 cout<<p->data<<endl;
 return(CORRECT);
}

int main(int argc,char*argv[])
{
 int r[100],i,SampleNum,SearchPos,NewPos,NewItem,DelPos;LNode *p;

 cin>>SampleNum;
 for(i=1;i<=SampleNum;i++) cin>>r[i];

 LinkList=CreateLinkList(r,SampleNum);
 ShowLinkList(LinkList);

 cin>>SearchPos;
 p=SearchLinkList(LinkList,SearchPos);
 cout<<p->data<<endl;

 cin>>NewPos;cin>>NewItem;
 InsertLinkList(LinkList,NewItem,NewPos);
 ShowLinkList(LinkList);

 cin>>DelPos;
 DeleteLinkList(LinkList,DelPos);
 ShowLinkList(LinkList);
 return 0;
}