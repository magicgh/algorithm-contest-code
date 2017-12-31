#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<queue>
#include<list>
#include<climits>
#define M 100000
#define N 10000
using namespace std;
struct node
{
	int to,value;
};
list<node>edge[M];
int n,m,dist[N];
bool used[N],ext[N];
inline int GetInt()
{
	char t;
	int num=0;
	while(t=getchar(),t>='0'&&t<='9')num=num*10+t-'0';
	return num;
}
inline bool SPFA(int u)
{
	queue<int>q;
	for(int i=1;i<=n;i++)dist[i]=INT_MAX;
	dist[u]=0,q.push(u),ext[u]=1;
	list<node>::iterator y;
	while(!q.empty())
	{
		int x=q.front();
		ext[x]=0;
		for(y=edge[x].begin();y!=edge[x].end();++y)
		{
			if(dist[y->to]>dist[x]+(y->value))
			{
				used[y->to]++;
				if(used[y->to]>=n)return 0;
		        dist[y->to]=dist[x]+(y->value);
		        if(!ext[y->to])q.push(y->to),ext[y->to]=1;
			}
		}
		q.pop();
	}
	return 1;
}
int main(){
	n=GetInt();
	m=GetInt();
	memset(dist,0,sizeof(dist));
	memset(used,0,sizeof(used));
	memset(ext,0,sizeof(ext));
	int x,y,z;
	for(int i=1;i<=m;i++)x=GetInt(),y=GetInt(),z=GetInt(),edge[x].push_back({y,z});
	int s,t;
	s=GetInt(),t=GetInt();
	if(SPFA(s))printf("%d",dist[t]);
	else puts("No Solution!");
	return 0;
}