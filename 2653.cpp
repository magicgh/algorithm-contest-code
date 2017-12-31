#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int N,M;
int C[1050][1050];
inline int Lowbit(int x){return x&(-x);}
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Modify(int x,int y,int d)
{
	for(int i=x;i<=M;i+=Lowbit(i))
	for(int j=y;j<=M;j+=Lowbit(j))C[i][j]+=d;
}
inline int Sum(int x,int y)
{
	int Ans=0;
	for(int i=x;i>=1;i-=Lowbit(i))
	for(int j=y;j>=1;j-=Lowbit(j))Ans+=C[i][j];
	return Ans;
}
inline void Add()
{
	int x,y,a;
	x=GetInt()+1;
	y=GetInt()+1;
	a=GetInt();
	Modify(x,y,a);
}
inline void Query()
{
	int l,b,r,t;
	l=GetInt()+1;
	b=GetInt()+1;
	r=GetInt()+1;
	t=GetInt()+1;
	printf("%d\n",Sum(r,t)-Sum(r,b-1)-Sum(l-1,t)+Sum(l-1,b-1));//二维树状数组区间求和 
}
int main(){
	while(N=GetInt(),N!=3)
	{
		if(N==0)M=GetInt();
		if(N==1)Add();
		if(N==2)Query();	
	}
	return 0;
}
