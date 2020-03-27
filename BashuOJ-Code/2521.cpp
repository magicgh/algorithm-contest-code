#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#define ri register int
using namespace std;
int M,N,C[100005];
inline int Lowbit(int x){return x&(-x);}
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Modify(int x,int d)
{
	for(ri i=x;i<=N;i+=Lowbit(i))C[i]+=d;
}
inline int Sum(int x)
{
	int Ans=0;
	for(ri i=x;i>0;i-=Lowbit(i))Ans+=C[i];
	return Ans;
} 
int main(){
	N=GetInt(),M=GetInt();
	int x,y;char ch;
	for(ri i=1;i<=M;i++)
	{
		while(ch=getchar())if(ch=='d'||ch=='u'||ch=='s')break;
		x=GetInt(),y=GetInt();
		if(ch=='d')Modify(x,y);
		if(ch=='u')Modify(x,-y);
		if(ch=='s')printf("%d\n",Sum(y)-Sum(x-1));
	} 
	return 0;
}