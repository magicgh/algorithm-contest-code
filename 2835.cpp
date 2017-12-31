#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
const int MAXN=100005;
int p[MAXN],Phi[MAXN];
bool vst[MAXN];
int n,m;
long long ans;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Init()//求欧拉函数 
{
	Phi[1]=1; 
	for(ri i=2;i<MAXN;i++)
	{
		if(!vst[i])p[++p[0]]=i,Phi[i]=i-1;//质数
		for(ri j=1;j<=p[0];j++)
		{
			if(i*p[j]>MAXN-1)break;//越界
			vst[i*p[j]]=1;
			if(i%p[j]==0){Phi[i*p[j]]=Phi[i]*p[j];break;}
			Phi[i*p[j]]=Phi[i]*Phi[p[j]];//i,p[j]互质,
		} 
	}
}
int main()
{
	Init();
	n=getint(),m=getint();
	for(ri i=1;i<=min(n,m);i++)ans+=(long long)(n/i)*(long long)(m/i)*(long long)Phi[i];
	ans=ans*2-(long long)m*n;
	printf("%lld",ans);
	return 0;
}

