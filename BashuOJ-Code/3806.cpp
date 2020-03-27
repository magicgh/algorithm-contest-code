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
const int MAXN=20005;
const int INF=0x7fffffff/2;
struct node{int to,val;};
vector<node>a[MAXN]; 
int n,m,N,S,Ans=INF,C[25],dist[MAXN];
bool ext[MAXN];	
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void AddEdge(int x,int y,int z)
{
	a[x].push_back((node){y,z});
}
void SPFA(int v0)
{
	deque<int>q;
	for(int i=0;i<=N;i++)dist[i]=INF;
	q.push_back(v0);dist[v0]=0;ext[v0]=1;
	while(!q.empty())
	{
		int now=q.front();
		q.pop_front();
		ext[now]=0;
		vector<node>::iterator it;
		for(it=a[now].begin();it!=a[now].end();++it)
		{
			if(dist[it->to]>dist[now]+it->val)
			{
				dist[it->to]=dist[now]+it->val;
				if(!ext[it->to])
				{
					if(!q.empty()&&dist[q.front()]>dist[it->to])q.push_front(it->to);
					else q.push_back(it->to);
				}
			}                                                                                      
		}
	}
}
int main()
{
	n=getint(),m=getint(),N=n*m;
	for(ri i=1;i<=m;i++)
	{
		C[i]=getint();
		if(!C[i])S=i;
	}
	for(ri x=1;x<=n;x++)
	{
		for(ri i=1;i<=m;i++)
		{
			ri y=x+C[i];
			if(y<1||y>n)continue;
			AddEdge((i-1)*n+x,(i-1)*n+y,abs(x-y)*2); 
		}
	}
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<m;j++)
			for(ri k=j+1;k<=m;k++) 
			{
				AddEdge((j-1)*n+i,(k-1)*n+i,abs(j-k));
				AddEdge((k-1)*n+i,(j-1)*n+i,abs(j-k));
			}
	SPFA((S-1)*n+1);
	for(ri i=1;i<=m;i++)
		Ans=min(Ans,dist[i*n]);
	printf("%d\n",Ans==INF?-1:Ans);
	return 0;
}

