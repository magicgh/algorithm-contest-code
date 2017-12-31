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
#define ll long long
using namespace std;
const int MAXN=48000;
bool vst[MAXN];
int n,m,cnt,p[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{ 
		if(c==EOF)return EOF;
		bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	} 
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Init()
{
	for(ri i=2;i<=MAXN;i++)
	{
		if(!vst[i])p[++p[0]]=i;
		for(ri j=1;j<=p[0]&&p[j]*i<MAXN;j++)
		{
			vst[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}
int main()
{
	Init();
	while(~(m=n=getint()))
	{
		cnt=0;
		for(ri i=1;i<=p[0]&&p[i]<=sqrt(m);i++)
		{
			while(n%p[i]==0)cnt++,n/=p[i];
			if(cnt>=4)break;
		}
		if(cnt>=4||(cnt==3&&n>1))printf("Niu!\n");
		else printf("Ruo...\n");
	}
	return 0;
}
