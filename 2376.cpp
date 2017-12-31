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
const int INF=0x7fffffff/2;
struct point{int x,y;};
int map[35][35],dist[35][35];
bool ext[35][35];
int n,m,t,dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
double Ans=-1e300;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline double Dist(const point &a,const point &b)
{
	return sqrt((double)(a.x-b.x)*(double)(a.x-b.x)+(double)(a.y-b.y)*(double)(a.y-b.y));
}
void SPFA(int sx,int sy)
{
	deque<point>q;
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)dist[i][j]=INF;
		q.push_back((point){sx,sy}),dist[sx][sy]=0,ext[sx][sy]=1;
	while(!q.empty())
	{
		point now=q.front();q.pop_front();ext[now.x][now.y]=0;
		for(ri i=0;i<4;i++)
		{
			point next=(point){now.x+dx[i],now.y+dy[i]};
			if(next.x>=1&&next.x<=n&&next.y>=1&&next.y<=m)
			{
				if(dist[next.x][next.y]>dist[now.x][now.y]+map[next.x][next.y])
				{
					dist[next.x][next.y]=dist[now.x][now.y]+map[next.x][next.y];
					if(!ext[next.x][next.y])
					{
						if(!q.empty()&&dist[q.front().x][q.front().y]<dist[next.x][next.y])
							q.push_back(next);
						else q.push_front(next);
						ext[next.x][next.y]=1;
					}
				}
			}
		}
	}
}
inline void Calc(const point &cur)
{
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
			if(dist[i][j]<=t-map[cur.x][cur.y])
				Ans=max(Ans,Dist(cur,(point){i,j}));
}
int main()
{
	char ch;
	n=getint(),m=getint(),t=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
		{
			while(ch=getchar())if(ch=='0'||ch=='1')break;
			map[i][j]=ch-'0';
		}
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
		{
			SPFA(i,j);
			Calc((point){i,j});
		}
	printf("%.6lf",Ans);
	return 0;
}
