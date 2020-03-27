#include<iostream>
#include<iomanip>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
vector<int>a[1000005];
int map[305][305];
bool graph[305][305];
int vst[1000005];
int belong[1000005];
int cnt1=0,cnt2=0,ans=0,t=0;	
int dx[8]={-1,1,2,2,1,-1,-2,-2},dy[8]={2,-2,-1,1,2,-2,-1,1};
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
inline bool DFS(int x)
{
	vector<int>::iterator i;
	for(i=a[x].begin();i!=a[x].end();++i)
	{
		if(vst[*i]==t)continue;
		vst[*i]=t;
		if(!belong[*i]||DFS(belong[*i]))
		{
			belong[*i]=x;
			return 1;
		}
	}
	return 0;
}
int N,M;
int main(){
	N=GetInt();M=GetInt();
	for(int i=1;i<=M;i++)
	{
		int x=GetInt(),y=GetInt();
		graph[x][y]=1;
	}
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
		{
			if(graph[i][j]==1)continue;
		    if((i+j)&1)map[i][j]=++cnt1;
			else map[i][j]=++cnt2;
		}
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
		{
			if(graph[i][j])continue;
			for(int k=0;k<=7;k++)
			{
				int nx=i+dx[k];
				int ny=j+dy[k];
				if(nx<1||nx>N||ny<1||ny>N||(i+j)&1==(nx+ny)&1||graph[nx][ny])continue;
				if((i+j)&1)a[map[i][j]].push_back(map[nx][ny]);
			}
		}
		for(int i=1;i<=cnt1;i++)
		{t++;if(DFS(i))ans++;}
	printf("%d",cnt1+cnt2-ans);
	return 0;
}