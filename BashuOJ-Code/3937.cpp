#include<iostream>
#include<iomanip>
#include<cstring>
#include<vector>
#include<cstdio>
#define ri register int
using namespace std;
const int MAXN=205;
vector<int>a[MAXN*MAXN];
int map[MAXN][MAXN];
bool graph[MAXN][MAXN];
int vst[MAXN*MAXN];
int belong[MAXN*MAXN];
int cnt1=0,cnt2=0,ans=0,t=0;	
int dx[8]={-1,1,2,2,1,-1,-2,-2},dy[8]={2,-2,-1,1,2,-2,-1,1};
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
bool DFS(int x)
{
	vector<int>::iterator it;
	for(it=a[x].begin();it!=a[x].end();++it)
	{
		if(vst[*it]==t)continue;
		vst[*it]=t;
		if(!belong[*it]||DFS(belong[*it]))
		{
			belong[*it]=x;
			return 1;
		}
	}
	return 0;
}
int N,M;
int main(){
	char ch;
	N=getint();
	for(ri i=1;i<=N;i++)
		for(ri j=1;j<=N;j++)
		{
			while(ch=getchar())
				if(ch=='0'||ch=='1')break;
			graph[i][j]=ch-'0';
		}
	for(ri i=1;i<=N;i++)
		for(ri j=1;j<=N;j++)
		{
			if(graph[i][j]==1)continue;
		    if((i+j)&1)map[i][j]=++cnt1;
			else map[i][j]=++cnt2;
		}
	for(ri i=1;i<=N;i++)
		for(ri j=1;j<=N;j++)
		{
			if(graph[i][j])continue;
			for(ri k=0;k<=7;k++)
			{
				int nx=i+dx[k];
				int ny=j+dy[k];
				if(nx<1||nx>N||ny<1||ny>N||(i+j)&1==(nx+ny)&1||graph[nx][ny])continue;
				if((i+j)&1)a[map[i][j]].push_back(map[nx][ny]);
			}
		}
		for(ri i=1;i<=cnt1;i++)
		{
			t++;
			if(DFS(i))ans++;
		}
	printf("%d\n",cnt1+cnt2-ans);
	return 0;
}