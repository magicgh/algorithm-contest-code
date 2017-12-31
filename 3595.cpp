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
const int MAXN=505;
stack<int>s;
vector<int>a[250005];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int w,l,N,part,cnt,In,Out,h[MAXN][MAXN];
int dfn[250005],low[250005],Size[250005],Belong[250005];
int Ind[250005],Outd[250005];
bool Ins[250005];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u)
{
	dfn[u]=low[u]=++cnt;
	s.push(u);Ins[u]=1;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(!dfn[*it])
		{
			DFS(*it);
			low[u]=min(low[u],low[*it]);
		}
		else if(Ins[*it])low[u]=min(low[u],dfn[*it]);
	}
	int t;
	if(low[u]==dfn[u])
	{
		part++;
		do
		{
			t=s.top();s.pop();
			Size[part]++,Ins[t]=0,Belong[t]=part;
		}
		while(t!=u);
	}
}
int main()
{
	w=getint(),l=getint();
	for(ri i=1;i<=l;i++)
		for(ri j=1;j<=w;j++)h[i][j]=getint();
	for(ri i=1;i<=l;i++)
		for(ri j=1;j<=w;j++)
			for(ri k=0;k<4;k++)
			{
				int nx=i+dx[k],ny=j+dy[k];
				if(nx>=1&&nx<=l&&ny>=1&&ny<=w&&h[nx][ny]<=h[i][j])
				a[(i-1)*w+j].push_back((nx-1)*w+ny);
			}
	N=w*l;
	for(ri i=1;i<=N;i++)if(!dfn[i])DFS(i);
	for(ri u=1;u<=N;u++)
	{
		vector<int>::iterator it;
		for(it=a[u].begin();it!=a[u].end();++it)
			if(Belong[u]!=Belong[*it])Ind[Belong[*it]]++,Outd[Belong[u]]++;
	}
	for(ri i=1;i<=part;i++)
	{
		if(Ind[i]==0)In++;
		if(Outd[i]==0)Out++;	
	}
	if(part==1)printf("0\n");
	else printf("%d\n",max(In,Out));
	return 0;
}
