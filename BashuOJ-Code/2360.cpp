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
const int MAXN=100005;
vector<int>a[MAXN];
ll Ans,f[MAXN][15][3];
int n,m,q,value;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll Mod(const ll &x)
{
	if(x!=0&&x%q==0)return q;
	return x%q;
}
void Tree_DP(int u,int fa)
{
	for(ri j=0;j<=value;j++)f[u][j][0]=1,f[u][j][1]=f[u][j][2]=0;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		Tree_DP(*it,u);
		for(ri j=0;j<=value;j++)
		{
			ll tmp1=0,tmp2=0;
			tmp1=Mod(f[*it][j][0]+f[*it][j][1]);//u->*it修铁路
			if(j)tmp2=Mod(f[*it][j-1][0]+f[*it][j-1][1]+f[*it][j-1][2]);//u->*it不修铁路
			f[u][j][2]=Mod(f[u][j][1]*tmp1+f[u][j][2]*tmp2);
			f[u][j][1]=Mod(f[u][j][0]*tmp1+f[u][j][1]*tmp2);
			f[u][j][0]=Mod(f[u][j][0]*tmp2);
		}
	}
}
int main()
{
	n=getint(),m=getint(),q=getint();
	if(n-1!=m){printf("-1\n-1\n");return 0;}
	for(ri i=1;i<n;i++)
	{
		int u=getint(),v=getint();
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(value=0;;value++)
	{
		Tree_DP(1,0);
		Ans=f[1][value][0]+f[1][value][1]+f[1][value][2];
		if(Ans)break;
	}
	printf("%d\n%lld\n",value,Ans%q);
	return 0;
}
