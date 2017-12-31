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
const int MAXN=35;
const int INF=0x7fffffff/2;
struct que{int x,y;};
struct node{int x,y,dir;}; 
int n,m,q;
bool map[MAXN][MAXN];
int f[MAXN][MAXN][MAXN][MAXN][4];
//空格在(Ex,Ey),走到(x,y)且(x,y)在(Ex,Ey)d方向的代价 
int dist[MAXN][MAXN][4];
//棋子从起始点到(x,y)且(x,y)在空格d方向的代价
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
bool vst[MAXN][MAXN];
bool ext[MAXN][MAXN][4];
int Sx,Sy,Ex,Ey,Tx,Ty;
namespace FastIO
{
    const ll L=1<<15;
    char buffer[L],*S,*T;
    inline char getchar()
	{
        if(S==T){T=(S=buffer)+fread(buffer,1,L,stdin);if(S==T)return EOF;}
		return *S++;
    }
    inline int getint()
	{
        ri num=0,bj=1;
		register char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
    }
}using FastIO::getint;
void BFS(int x,int y,int dir)//预处理 
{
	queue<que>q;
	memset(vst,0,sizeof(vst));
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
				f[x][y][i][j][dir]=INF;
	vst[x][y]=1;
	int fx=x+dx[dir],fy=y+dy[dir];//限制第一步的方向 
	if(map[fx][fy])
	{
		f[x][y][fx][fy][dir]=0;
		q.push((que){fx,fy});
	}
	while(!q.empty())//以空格为中心搜索空格可到达的点 
	{
		que now=q.front();q.pop();
		if(vst[now.x][now.y])continue;
		vst[now.x][now.y]=1;
		for(ri i=0;i<4;i++)
		{
			que next=(que){now.x+dx[i],now.y+dy[i]};
			if(!vst[next.x][next.y]&&map[next.x][next.y])
			{
				f[x][y][next.x][next.y][dir]=f[x][y][now.x][now.y][dir]+1;
				q.push(next);
			}
		}
	}
}
void SPFA()
{
	queue<node>q; 
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
			for(ri k=0;k<4;k++)dist[i][j][k]=INF,ext[i][j][k]=0;
	for(ri i=0;i<4;i++)
	{
		dist[Sx][Sy][i]=f[Sx][Sy][Ex][Ey][i];//初始化dist(包括空格走到(Sx,Sy)d方向上的代价) 
		q.push((node){Sx,Sy,i});
		ext[Sx][Sy][i]=1;
	}
	while(!q.empty())
	{
		node now=q.front();q.pop();ext[now.x][now.y][now.dir]=0;
		for(ri i=0;i<4;i++)
		{
			node next=(node){now.x+dx[i],now.y+dy[i],i^1};
			if(!map[next.x][next.y])continue;
			if(dist[next.x][next.y][next.dir]>dist[now.x][now.y][now.dir]+f[now.x][now.y][next.x][next.y][now.dir]+1)
			{
				dist[next.x][next.y][next.dir]=dist[now.x][now.y][now.dir]+f[now.x][now.y][next.x][next.y][now.dir]+1;
				//空格从起始点移动到目标点的次数+空格和棋子交换了1次 
				//空格的发生了相对方向变化 
				if(!ext[next.x][next.y][next.dir])
				{
					q.push(next);
					ext[next.x][next.y][next.dir]=1;
				}
			}
		}
	}
}
int main()
{
	n=getint(),m=getint(),q=getint();
	for(ri i=1;i<=n;i++) 
		for(ri j=1;j<=m;j++)
			map[i][j]=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
			for(ri k=0;k<4;k++)
				if(map[i][j])BFS(i,j,k); 
	for(ri i=1;i<=q;i++)
	{
		int Ans=INF;
		Ex=getint(),Ey=getint(); 
		Sx=getint(),Sy=getint(); 
		Tx=getint(),Ty=getint();
		if(Sx==Tx&&Sy==Ty){printf("0\n");continue;}
		SPFA();
		for(ri j=0;j<4;j++)
			Ans=min(dist[Tx][Ty][j],Ans);
		printf("%d\n",Ans==INF?-1:Ans);
	}
	return 0;
}
