#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<list>
#include<queue>
#define Mod 100003
using namespace std;
int n,m,cnt[400005],dist[400005];
bool vst[400005];
list<int>a[400005];
inline void BFS(int x)
{
	queue<int>q;
	vst[x]=cnt[x]=1;
	q.push(x);
	while(!q.empty())
	{
		int now=q.front();
		list<int>::iterator i;
		for(i=a[now].begin();i!=a[now].end();++i)
		{
			if(!vst[*i])
			{
				vst[*i]=1;
				dist[*i]=dist[now]+1;
				cnt[*i]=cnt[now];
				q.push(*i);
			}
			else if(dist[now]+1==dist[*i])cnt[*i]=(cnt[*i]+cnt[now])%Mod;
			//cout<<now<<" "<<next<<" "<<dist[now]<<":"<<dist[next]<<endl;
		}
		q.pop();
	}
}
int main(){
	scanf("%d%d",&n,&m);
	int x,y;
	memset(vst,0,sizeof(vst));
	memset(cnt,0,sizeof(cnt));
	memset(dist,0,sizeof(dist));
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	BFS(1);
	for(int i=1;i<=n;i++)printf("%d\n",cnt[i]);
	return 0;
}