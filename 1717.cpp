#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <climits>
using namespace std;
int n,m;
struct node
{
	int x,y;
};
char map[1005][1005];
bool used[1005][1005];
int catch_cnt=0,Ship=0,rx=0,ry=0;
int dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1};
void BFS(int x,int y)
{
	queue<node>q;
	q.push({x,y});
	used[x][y]=1;
	while(!q.empty())
	{
		node now=q.front();
		rx=max(rx,now.x),ry=max(ry,now.y);
		for(int i=1;i<=4;i++)
		{
			node next={now.x+dx[i],now.y+dy[i]};
			if(map[next.x][next.y]=='#'&&(!used[next.x][next.y])&&next.x>=1&&next.x<=n&&next.y>=1&&next.y<=m)
			{
				catch_cnt++;
				//cout<<next.x<<' '<<next.y<<":"<<catch_cnt<<endl;
				used[next.x][next.y]=1;
                q.push(next);
			}
		}
		q.pop();
	}
	return;
}
int main() {
	int sx=0,sy=0;
	memset(used,0,sizeof(used));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=m;j++)cin>>map[i][j];
	   for(int i=1;i<=n;i++)
	     for(int j=1;j<=m;j++)
	     {
	     	if(map[i][j]=='#'&&!used[i][j])
	     	{
	     		catch_cnt=1;
	     		rx=INT_MIN,ry=INT_MIN;
	     		BFS(i,j);
	     		//cout<<i<<' '<<j<<' '<<rx<<' '<<ry<<' '<<catch_cnt<<endl;
	     		if((rx-i+1)*(ry-j+1)==catch_cnt)Ship++;
	     		else
	     		{
	     			puts("Bad placement.");
	     			return 0;
	     		}
	     	}
	     }
	  printf("There are %d ships.",Ship);
	return 0;
}