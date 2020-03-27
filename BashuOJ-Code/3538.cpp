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
const int MAXN=105;
const int INF=0x7fffffff/2;
struct node{int to,val;};
int n,k,m,s,t,cnt,Ans=INF;
int c[MAXN];
bool cul[MAXN][MAXN],Hash[MAXN],vst[MAXN];
vector<node>a[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u,int dist)
{
	vector<node>::iterator it;
	if(dist>Ans)return;
	if(++cnt>=50000){printf("%d\n",Ans==INF?-1:Ans);exit(0);}
	if(u==t){Ans=min(Ans,dist);return;}
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(vst[it->to]||Hash[c[it->to]])continue;
		bool flag=0;
		for(ri i=1;i<=k;i++)
		if(cul[c[it->to]][i]&&Hash[i]){flag=1;break;}
		if(!flag)
		{
			vst[it->to]=Hash[c[it->to]]=1;
			DFS(it->to,dist+it->val);
			vst[it->to]=Hash[c[it->to]]=0;
		}
	}
}
int main()
{
	n=getint(),k=getint(),m=getint(),s=getint(),t=getint();
	for(ri i=1;i<=n;i++)c[i]=getint();
	char ch;
	for(ri i=1;i<=k;i++)
		for(ri j=1;j<=k;j++)
		{
			while(ch=getchar())
				if(ch=='0'||ch=='1')break;
			cul[i][j]=ch-'0';
		}
	for(ri i=1;i<=m;i++)
	{
		int u=getint(),v=getint(),d=getint();
		a[u].push_back((node){v,d});
		a[v].push_back((node){u,d});
	}
	vst[s]=1,Hash[c[s]]=1,DFS(s,0);
	printf("%d\n",Ans==INF?-1:Ans);
	return 0;
}

