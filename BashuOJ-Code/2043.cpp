#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct bit
	{
		int C[20005];
		inline int Lowbit(int x){return x&(-x);}
		inline void Modify(int x,int d)
		{
		for(int i=x;i<=20000;i+=Lowbit(i))C[i]^=d; 
		}
		inline int Sum(int x)
		{
		int Ans=0;
		for(int i=x;i>0;i-=Lowbit(i))Ans^=C[i];
		return Ans;
		}
	};
char cmd[11];
bit tr;
int main(){
	while(~scanf("%s",cmd))
	{
		if(strcmp(cmd,"ADD")==0||strcmp(cmd,"REMOVE")==0)
		{
			int x=GetInt();
			tr.Modify(x,x);//此处区间与值相同 因为XOR NUM1 NUM2转化成了区间  
			/*
			ADD x^0=x
			REMOVE x^x=0
			*/ 
		}	
		if(strcmp(cmd,"XOR")==0)
		{
			int x=GetInt(),y=GetInt();
			if(x>y)printf("0\n");
			else printf("%d\n",tr.Sum(y)^tr.Sum(x-1));
			/*
			   --------x-1(##########)->[x,y]
			   ---------------------y
			*/
		}
	}
	return 0;
}
