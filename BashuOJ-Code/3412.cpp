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
const int MAXN=50005; 
const int INF=1e18;
struct node{int to,val;};
struct heap
{
	int u;ll dist;
	bool operator <(const heap &rhs)
	const {return dist>rhs.dist;}
};
priority_queue<heap>q;
vector<node>a[MAXN];
vector<int>Cir[MAXN],Branch[MAXN];
int t,r,p,s,part;
int Belong[MAXN],Deg[MAXN],List[MAXN];
ll dist[MAXN];
bool vst[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void putll(ll x)
{
     if(x<0)putchar('-'),x=-x;
     if(x>9)putll(x/10);
     putchar(x%10+'0');
}
void Staining(int u,int color)
{
	Belong[u]=color;
	Cir[color].push_back(u);//对每个环建边 
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(Belong[it->to])continue;//被染过色
		Staining(it->to,color);
	}
}
void Shrink()
{
	for(ri i=1;i<=t;i++)
		if(!Belong[i])Staining(i,++part);//缩点 
}
void GetDeg(int u)//求出环外支路的度 
{
	vst[u]=1;
	vector<int>::iterator it;
	for(it=Branch[u].begin();it!=Branch[u].end();++it)
	{
		Deg[*it]++;
		if(vst[*it])continue;
		GetDeg(*it);
	}
}
void Topsort()//对环拓扑排序 
{
	queue<int>q;
	q.push(Belong[s]);
	while(!q.empty())
	{
		int now=q.front();q.pop();
		vector<int>::iterator it;
		List[++List[0]]=now;
		for(it=Branch[now].begin();it!=Branch[now].end();++it)
		{
			Deg[*it]--;
			if(!Deg[*it])
				q.push(*it);
		} 
	}
}
void Dijkstra(int cur)
{
	while(!q.empty())
	{
		heap now=q.top();q.pop();
		if(vst[now.u])continue;
		vst[now.u]=1;
		vector<node>::iterator it;
		for(it=a[now.u].begin();it!=a[now.u].end();++it)
		{
			if(vst[it->to])continue;
			//对当前环进行内部更新
			if(dist[it->to]>dist[now.u]+it->val) 
			{
				dist[it->to]=dist[now.u]+it->val;
				if(Belong[it->to]==cur)q.push((heap){it->to,dist[it->to]});
				//可能出现其他环中的点没有被及时更新的情况 
			}
		}
	}
}
int main()
{
	t=getint(),r=getint(),p=getint(),s=getint();
	for(ri i=1;i<=r;i++)
	{
		int x=getint(),y=getint(),z=getint();
		a[x].push_back((node){y,z});
		a[y].push_back((node){x,z});//建环 
	}
	Shrink();
	for(ri i=1;i<=p;i++)
	{
		int x=getint(),y=getint(),z=getint();
		a[x].push_back((node){y,z});//完善原图 
		Branch[Belong[x]].push_back(Belong[y]);//构建环外支路 
	} 
	GetDeg(Belong[s]); 
	Topsort(); 
	memset(vst,0,sizeof(vst));
	for(ri i=1;i<=t;i++)dist[i]=INF;
	dist[s]=0; 
	for(ri i=1;i<=List[0];i++)//按照拓扑序 
	{
		vector<int>::iterator it;
		for(it=Cir[List[i]].begin();it!=Cir[List[i]].end();++it)
		{
			if(dist[*it]!=INF)
				q.push((heap){*it,dist[*it]});
		}//预处理能更新当前环的点 
		Dijkstra(List[i]);
	}
	for(ri i=1;i<=t;i++)
	{
		if(dist[i]==INF)printf("NO PATH\n");
		else putll(dist[i]),putchar('\n');
	}
	return 0;
}
