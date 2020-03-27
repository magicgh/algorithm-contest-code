#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath> 
using namespace std;
int M;
int C[100005];
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
	for(int i=x;i<=M;i+=Lowbit(i))C[i]+=d;
}
inline int Sum(int x)
{
	int Ans=0;
	for(int i=x;i>0;i-=Lowbit(i))Ans+=C[i];
	return Ans;
} 
int main(){
	int x,y;
	while(scanf("%d",&M),M!=0)
	{
	memset(C,0,sizeof(C)); 
	for(int i=1;i<=M;i++)
	{
		x=GetInt();
		y=GetInt();
		Modify(x,1);
		Modify(y+1,-1);//差分思路 
	}
	for(int i=1;i<M;i++)printf("%d ",Sum(i));
	printf("%d\n",Sum(M));
	}
	return 0;
}
