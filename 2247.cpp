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
using namespace std;
const int MAXN=205;
const int INF=0x7fffffff;
int N,M,X,Y,K,s,t,dir,H,T,now,ans=-INF;
char map[MAXN][MAXN];
int f[MAXN][MAXN][MAXN];
int dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1};
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct Queue
{
	int q[MAXN],pos[MAXN];
	Queue(){H=1,T=0;return;}
	inline void push(int x,int val){q[++T]=x,pos[T]=val;}
	inline void pop_front(){H++;}
	inline void pop_back(){T--;}
	inline bool empty(){return H>=T||H<0||T<0;}
};
Queue q;
inline void push(int val,int now)
{
	if(val==-INF)return;
	while(val-now>q.q[T]&&H<=T)q.pop_back();
	q.push(val-now,now);
}
inline void DP(int ti,int dir,int x,int y,int tl)
{
	H=1,T=0,now=0;
	while(x>=1&&x<=N&&y>=1&&y<=M)
	{
		if(map[x][y]=='x')H=1,T=0,now=0;
		else push(f[ti-1][x][y],now);
		while(now-q.pos[H]>tl&&H<=T)q.pop_front();
		if(H<=T)f[ti][x][y]=q.q[H]+now;
		else f[ti][x][y]=-INF;
		ans=max(ans,f[ti][x][y]);
		x+=dx[dir],y+=dy[dir];
		now++;
	}
}
int main()
{
	N=getint(),M=getint(),X=getint(),Y=getint(),K=getint();
	char ch;
	for(ri i=1;i<=N;i++)
		for(ri j=1;j<=M;j++)
		{
			while(ch=getchar())if(ch=='.'||ch=='x')break;
			map[i][j]=ch;
			f[0][i][j]=-INF;
		}
	int s,t,dir;f[0][X][Y]=0;
	for(ri i=1;i<=K;i++)
	{
		s=getint(),t=getint(),dir=getint();
		if(dir==1)for(ri j=1;j<=M;j++)DP(i,dir,N,j,t-s+1);
		if(dir==2)for(ri j=1;j<=M;j++)DP(i,dir,1,j,t-s+1);
		if(dir==3)for(ri j=1;j<=N;j++)DP(i,dir,j,M,t-s+1);
		if(dir==4)for(ri j=1;j<=N;j++)DP(i,dir,j,1,t-s+1);
	}
	printf("%d",ans);
	return 0;
}
