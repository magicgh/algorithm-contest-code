#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int Mod=1000000007;
const int MAXN=505;
const int MAXS=260;
int p[]={0,2,3,5,7,11,13,17,19};
int Num[MAXN],sta[MAXN];
vector<int>Prime[MAXN];
int T,N,K;
ll Ans,f[MAXN][MAXS];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Add(ll &A,ll B){A=(A+B>=Mod)?A+B-Mod:A+B;}
inline void Clear()
{
	Ans=0;
	for(ri i=1;i<=N;i++)Prime[i].clear();
	memset(sta,0,sizeof(sta));
} 
inline void Solve()
{
	for(ri i=1;i<=N;i++)
	{
		Num[i]=i;
		for(ri j=1;j<=8;j++)
		{
			if(Num[i]%(p[j]*p[j])==0)sta[i]=-1;
			else if(Num[i]%p[j]==0)Num[i]/=p[j],sta[i]|=(1<<(j-1));
		}
	}
	for(ri i=1;i<=N;i++)
	{
		if(~sta[i])
		{
			if(Num[i]==1)Prime[i].push_back(i);
			else Prime[Num[i]].push_back(i);
		}
	}
	memset(f,0,sizeof(f));
	f[0][0]=1;
	for(ri i=1;i<=N;i++)
	{
		if(~sta[i]&&Prime[i].size())
		{
			for(ri j=K-1;j>=0;j--)
				for(vector<int>::iterator it=Prime[i].begin();it!=Prime[i].end();++it)
					for(ri v=sta[*it],s=255^v;;s=(s-1)&(255^v))
					{
						if((s&sta[*it])==0)Add(f[j+1][s|v],f[j][s]);
						if(!s)break;
					}
		}
	}
	for(ri i=1;i<=K;i++)
		for(ri j=0;j<=255;j++)Add(Ans,f[i][j]);
	printf("%lld\n",Ans);
}
int main()
{
	T=GetInt();
	while(T--)
	{
		N=GetInt(),K=GetInt();
		Clear();
		Solve();
	}
	return 0;
}

