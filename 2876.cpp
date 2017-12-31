#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<queue>
using namespace std;
int m,n,x,y,st,bj[405],cnt=0;
bool vst[405],f[2005][2005];
inline void BFS(int x)
{
	queue<int>q;
	q.push(x);
	vst[x]=1;
	while(!q.empty())
	{
		int now=q.front();
		cout<<now<<' ';
		for(int i=1;i<=n;i++)
		{
			if(f[now][i]&&(!vst[i]))
			{
				vst[i]=1;
                q.push(i);
			}
		}
		q.pop();
	}
}
int main(){
	cin>>n>>m;
	memset(vst,0,sizeof(vst));
	memset(f,0,sizeof(f));
	memset(bj,0,sizeof(bj));
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		f[x][y]=f[y][x]=1;
	}
	cin>>st;
    BFS(st);
	return 0;
}
