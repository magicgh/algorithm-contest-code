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
const int MAXN=55;
const int INF=0x7fffffff;
char map[MAXN][MAXN];
struct node{int x,y;};
node Belong[8][MAXN*MAXN];
int n,m,cnt,ans=INF;
int Color[MAXN][MAXN],Size[8];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
queue<node>q; 
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void BFSx1(int x,int y)
{
	Color[x][y]=++cnt;
	q.push((node){x,y});
	while(!q.empty())
	{
		node now=q.front();q.pop();
		Belong[cnt][++Size[cnt]]=(node){now.x,now.y};
		for(ri i=0;i<4;i++)
		{
			node next=(node){now.x+dx[i],now.y+dy[i]};
			if(next.x>=1&&next.x<=n&&next.y>=1&&next.y<=m&&map[next.x][next.y]=='X'&&(Color[next.x][next.y]==0))
				Color[next.x][next.y]=cnt,q.push(next);
		}
	}
}
void FloodFill()
{
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
			if(map[i][j]=='X'&&(Color[i][j]==0))BFSx1(i,j);
}
inline int Dist(const node &a,const node &b)
{
	return abs(a.x-b.x)+abs(a.y-b.y)-1; 
}
inline int A2P(node now,int k)//点与块之间的距离 
{
	int ret=INF;
	for(ri i=1;i<=Size[k];i++)
	{
		node next=Belong[k][i];
		ret=min(ret,Dist(now,next));
	}
	return ret;
}
void Mapping()
{
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
		{
			if(map[i][j]=='.')
			{
				node t=(node){i,j};
				int t1=A2P(t,1);
				int t2=A2P(t,2);
				int t3=A2P(t,3);
				ans=min(ans,t1+t2+t3+1);
			}
		}
}
inline int A2A(int x,int y)
{
	int ret=INF;
	for(ri i=1;i<=Size[x];i++)
	{
		node now=Belong[x][i];
		for(ri j=1;j<=Size[y];j++)
		{
			node next=Belong[y][j];
			ret=min(ret,Dist(now,next));
		}
	}	
	return ret;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
		{
			char ch;
			while(ch=getchar())if(ch=='X'||ch=='.')break;
			map[i][j]=ch;
		}
	FloodFill();
	Mapping();
	int t1=A2A(1,2),t2=A2A(1,3),t3=A2A(2,3);
	ans=min(ans,min(min(t1+t2,t1+t3),t2+t3));
	printf("%d",ans);
	return 0;
}

