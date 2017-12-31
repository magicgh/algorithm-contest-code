#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<deque>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=1005;
const int INF=0x7fffffff/2;
const int MAXS=(1<<6);
struct node{int to,val;};
struct heap{int u,sta;};
vector<node>a[MAXN];
deque<heap>q;
int N,n,m,p,status;
int sta[MAXN],dist[MAXN][MAXS];
bool ext[MAXN][MAXS];
inline void addedge(int x,int y,int z)
{
	a[x].push_back((node){y,z});
	a[y].push_back((node){x,z});
}
void Init()
{
	for(ri i=0;i<=1005;i++)a[i].clear();
	memset(ext,0,sizeof(ext));
	memset(sta,0,sizeof(sta));
	status=1<<(n+1),N=n+m;
	for(ri i=0;i<=N;i++)
		for(ri j=0;j<status;j++)dist[i][j]=INF;
	for(ri i=0;i<=n;i++)sta[i]=1<<i,dist[i][sta[i]]=0;//i节点当前状态代价为0 (只有和尚所在的n个点才需要水) 
}
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
inline void SPFA()
{
	while(!q.empty())
	{
		heap now=q.front();q.pop_front();ext[now.u][now.sta]=0;
		vector<node>::iterator it;
		for(it=a[now.u].begin();it!=a[now.u].end();++it)
		{
			heap next=(heap){it->to,(now.sta|sta[it->to])};
			if(dist[next.u][next.sta]>dist[now.u][now.sta]+it->val)
			{
				dist[next.u][next.sta]=dist[now.u][now.sta]+it->val;
				if(now.sta==next.sta&&!ext[next.u][next.sta])//把处于相同层的节点加到队列中
				{
					if(!q.empty()&&dist[q.front().u][q.front().sta]>dist[next.u][next.sta])q.push_front(next);
					else q.push_back(next);
					ext[next.u][next.sta]=1;
				}
			}
		}	
	}	
} 
inline void Steiner()
{
	for(int i=0;i<status;i++)//枚举连通情况 
	{
		for(int j=0;j<=N;j++)//枚举所有点 
		{
			if(!(i&sta[j])&&j<=n)continue;
			for(int k=i;k;k=(k-1)&i)//枚举i连通情况的子集 
				dist[j][i]=min(dist[j][i],dist[j][k|sta[j]]+dist[j][(i-k)|sta[j]]);
			if(dist[j][i]!=INF)
			{
				heap t=(heap){j,i};
				q.push_back(t);
				ext[t.u][t.sta]=1;
			}
		}	
		SPFA();//对于连通状态的转移 
	}
}
inline int DP()
{
	int Ans=INF;
	for(ri i=0;i<=N;i++)Ans=min(Ans,dist[i][status-1]);
	//枚举根节点，status-1表示全部连通的代价 	
	return Ans;
}
int main()
{
	while(~(n=getint()))
	{
		m=getint(),p=getint();
		Init();
		for(ri i=1;i<=N;i++)
			addedge(0,i,getint());
		for(ri i=1;i<=p;i++)
		{
			int u=getint(),v=getint(),w=getint();
			addedge(u,v,w);	
		}
		Steiner();
		printf("%d\n",DP());
	}
	return 0;
}

