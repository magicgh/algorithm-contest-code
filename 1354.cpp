#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int N,M;
struct bit
{
	int C[105][105][105];
	inline int Lowbit(int x){return x&(-x);}
	inline void Init(){memset(C,0,sizeof(C));}
	inline void Modify(int x,int y,int z,int d)
	{
	for(int i=x;i<=N;i+=Lowbit(i))
	for(int j=y;j<=N;j+=Lowbit(j))
	for(int k=z;k<=N;k+=Lowbit(k))C[i][j][k]+=d;
	}
	inline int Sum(int x,int y,int z)
	{
	int Ans=0;
	for(int i=x;i>0;i-=Lowbit(i))
	for(int j=y;j>0;j-=Lowbit(j))
	for(int k=z;k>0;k-=Lowbit(k))Ans+=C[i][j][k];
	return Ans;
	}
}; 
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
bit tr;
int main(){
	while(~scanf("%d",&N))
	{
	tr.Init();
	M=GetInt();
	for(int i=1;i<=M;i++)
	{
		int x=GetInt();
		if(x==1)
		{
			int ax,ay,az,bx,by,bz;
			ax=GetInt();ay=GetInt();az=GetInt();
			bx=GetInt();by=GetInt();bz=GetInt();
			tr.Modify(ax,ay,az,1);tr.Modify(bx+1,ay,az,1);tr.Modify(bx+1,by+1,az,1);
			tr.Modify(ax,by+1,az,1);tr.Modify(ax,by+1,bz+1,1);tr.Modify(bx+1,ay,bz+1,1);
			tr.Modify(bx+1,by+1,bz+1,1);tr.Modify(ax,ay,bz+1,1);
		}
		if(x==0)
		{
		int ax,ay,az;
		ax=GetInt();ay=GetInt();az=GetInt();
		printf("%d\n",tr.Sum(ax,ay,az)&1);
		}
		
	}
	}
	return 0;
}
