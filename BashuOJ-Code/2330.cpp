#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
const int INF=0x7fffffff;
const int MAXN=1605;
struct node{int to,val;};
vector<node>a[MAXN];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int ans,N,w,h;
int map[45][45];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void addedge(int x,int y,int z)
{
	a[x].push_back({y,z});
	a[y].push_back({x,z});
}
struct heap
{
	int num,val;
	bool operator <(const heap &rhs)const{return val>rhs.val;}
};
struct MST
{
	int dist[MAXN];
	bool vst[MAXN];
	inline bool Prim(int v0)
	{
		int cnt=0;
		priority_queue<heap>q;
		for(int i=1;i<=N;i++)dist[i]=INF;
		dist[v0]=0;q.push((heap){v0,0});
		while(!q.empty()&&cnt<=N)
		{
			heap now=q.top();
			q.pop();
			if(vst[now.num])continue;
			ans+=now.val;	
			vst[now.num]=1;
			cnt++;
			vector<node>::iterator j;
			for(j=a[now.num].begin();j!=a[now.num].end();++j)
			{ 
				if(!vst[j->to]&&dist[j->to]>j->val)
				{
					dist[j->to]=j->val;
					q.push((heap){j->to,dist[j->to]});
				}
			}
		}
		if(cnt==N)return 1;
		else return 0;
	}
};
MST st;
int main()
{
	w=getint(),h=getint();N=w*h;
	for(ri i=1;i<=h;i++)
		for(ri j=1;j<=w;j++)map[i][j]=getint();
	for(ri i=1;i<=h;i++)
		for(ri j=1;j<=w;j++)
		{
			for(ri k=0;k<=3;k++)	
			{
				int x=i+dx[k],y=j+dy[k];
				if(x>=1&&x<=h&&y>=1&&y<=w)
				{
					if(i==1&&j==1)addedge((i-1)*w+j,(x-1)*w+y,map[x][y]+map[i][j]);
					addedge((i-1)*w+j,(x-1)*w+y,map[x][y]);
				}
			
			}
		}
	st.Prim(1);
	printf("%d",ans);
	return 0;
}

