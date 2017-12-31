#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int W,H,N;
long long f[15][1<<15];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool Judge(int x)
{
	int cnt=0;
	while(x>0)
	{
		if(x&1)cnt++;
		else if(cnt&1){cnt=0;return 0;}
		x>>=1;
	}
	if(cnt&1)return 0;
	else return 1;
}
inline bool Check(int a,int b)
{
	for(int i=1;i<N;)
	{
		if(((a&i)==0)&&((b&i)==0))return false;
		if((a&i)&&(b&i))
		{
			if((a&(i<<1))&&(b&(i<<1))){i<<=2;continue;}
			else return false;
		}
		i<<=1;
	}
	return true;
}
void DP()
{
	N=1<<H;
	memset(f,0,sizeof(f));
	for(int i=0;i<N;i++)if(Judge(i))f[1][i]=1;
	for(int i=2;i<=W;i++)
	for(int j=0;j<N;j++)
	for(int k=0;k<N;k++)if(Check(j,k))f[i][j]+=f[i-1][k];
}
int main(){
	while(scanf("%d%d",&W,&H)!=EOF)
	{
		if((W*H)&1)puts("0");
		else 
		{
			if(W<H)swap(W,H);
			DP();
			printf("%lld\n",f[W][N-1]);
		}
	}
	return 0;
}