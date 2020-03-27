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
const int MAXN=1005;
vector<int>a[MAXN];
bool Flag=0;
int N,M,part,Ans;
int Color[MAXN],Belong[MAXN],Len[MAXN],dist[MAXN];
bool vst[MAXN]; 
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS_Color(int u,int col)
{
	Color[u]=col;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(!Color[*it])DFS_Color(*it,3-col);
		else if(Color[*it]!=3-col){Flag=1;return;}
	}
}
inline bool Check()
{
	for(ri i=1;i<=N;i++)
	{
		if(!Color[i])
		{
			DFS_Color(i,1);
			if(Flag)return 1;
		}
	}
	return 0;
}
void DFS(int u)
{
	Belong[u]=part;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
		if(!Belong[*it])DFS(*it);
}
int BFS(int v0)
{
	int ret=0;
	queue<int>q;
	memset(vst,0,sizeof(vst));
	q.push(v0),dist[v0]=0,vst[v0]=1; 
	while(!q.empty())
	{
		int now=q.front();q.pop();
		vector<int>::iterator it;
		for(it=a[now].begin();it!=a[now].end();++it)
		{
			if(vst[*it])continue;
			vst[*it]=1,dist[*it]=dist[now]+1;
			ret=max(ret,dist[*it]);
			q.push(*it);
		}
	}
	return ret;
}
int main()
{
	N=GetInt(),M=GetInt();
	for(ri i=1;i<=M;i++)
	{
		int u=GetInt(),v=GetInt();
		a[u].push_back(v);
		a[v].push_back(u);
	}
	if(Check())return printf("-1\n"),0;
	for(ri i=1;i<=N;i++)
		if(!Belong[i])part++,DFS(i);
	for(ri i=1;i<=N;i++)Len[Belong[i]]=max(Len[Belong[i]],BFS(i));//ÇóÁ¬Í¨¿éµÄÖ±¾¶ 
	for(ri i=1;i<=part;i++)Ans+=Len[i];
	printf("%d\n",Ans);
	return 0;
}
