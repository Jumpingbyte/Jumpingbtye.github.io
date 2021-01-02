#include <iostream>
#include <string.h>
using namespace std;
#define ERROR -1
#define CORRECT 1

#define MAXSTACKSIZE 100
typedef struct SqStack{
   char base[MAXSTACKSIZE];
   char *top;
}SqStack;
SqStack MBStack;

int InitStack(SqStack &S)
{
  if(S.base==NULL) return (ERROR);
  S.top=S.base;
  return(CORRECT);
}


int Push(SqStack &S,char e)
{
  if((S.top-S.base)>=MAXSTACKSIZE) return (ERROR);
  *S.top=e;
  S.top++;
  return(CORRECT);
}

int Pop(SqStack &S,char &e)
{
   if(S.top<=S.base) return (ERROR);
   S.top--;
   e=*S.top;
   return (CORRECT);
}

int StackEmpty(SqStack &S)
{
 if(S.top<=S.base) return (ERROR);
 else return (CORRECT);
}

int MatchBracket(SqStack &S,char *BracketString)
{
 int i;
 char C,sC;

 InitStack(S);
 for(i=0;i<strlen(BracketString);i++){
   C=BracketString[i];
   if((C=='(')||(C=='[')||(C=='{')) Push(S,C);
   if((C==')')||(C==']')||(C=='}')){
     if(StackEmpty(S)==ERROR) return(-2);
	 else Pop(S,sC);
	 if((C==')')&&(sC!='(')) return(-1);
     if((C==']')&&(sC!='[')) return(-1);
     if((C=='}')&&(sC!='{')) return(-1);
   }
 }
 if(StackEmpty(S)!=ERROR) return (-3);
 else return(0);
}

int main(int argc,char* argv[])
{
    int i,SampleNum;
	char BracketString[MAXSTACKSIZE];

	cin>>SampleNum;
	for(i=0;i<SampleNum;i++){
	  cin>>BracketString;
	  cout<<MatchBracket(MBStack,BracketString)<<endl;
	}
	
}