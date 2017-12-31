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
const int MAXN=100005;
const int Limit=100000;
const int INF=0x7fffffff/2;
vector<int>a[MAXN];
int T,N,K,ret;
int f[MAXN][2];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Init()
{
	for(ri i=1;i<=Limit;i++)a[i].clear();
}
void Tree_DP(int u,int fa)
{
	f[u][0]=f[u][1]=0;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		Tree_DP(*it,u);
		f[u][1]=max(f[u][1]+max(f[*it][0],f[*it][1]),f[u][0]+f[*it][0]+1);
		f[u][0]+=max(f[*it][0],f[*it][1]);
	}
}
int main()
{
	T=GetInt();
	while(T--)
	{
		Init();
		N=GetInt(),K=GetInt();
		for(ri i=1;i<N;i++)
		{
			int point=GetInt();
			a[i+1].push_back(point);
			a[point].push_back(i+1);
		}
		Tree_DP(1,0);
		ret=max(f[1][0],f[1][1]);
		if(ret*2>=K)printf("%d\n",(K+1)/2);
		else printf("%d\n",ret+(K-ret*2));
	}
	return 0;
}
