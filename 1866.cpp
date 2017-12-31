#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<queue>
using namespace std;
struct data {
	int x,y,cnt;
} Bit[100005];
int n,m,map[205][205],dx[5]= {0,-1,1,0,0},dy[5]= {0,0,0,-1,1};
char map_ch[205][205];
bool vst[205][205];
queue<data>q;
void bfs_queue() 
{
	while(!q.empty()) 	
	{
		data now=q.front();
		vst[now.x][now.y]=1;
		for(int i=1; i<=4; i++) 		  		
		{
			data next;
			next.x=now.x+dx[i];
			next.y=now.y+dy[i];
			next.cnt=now.cnt+1;
			//cout<<"NOW---"<<now.x<<' '<<now.y<<' '<<now.cnt<<endl;
			//cout<<"TODO---"<<next.x<<' '<<next.y<<' '<<next.cnt<<endl<<endl;
			if((!vst[next.x][next.y])&&next.x>0&&next.x<=n&&next.y>0&&next.y<=m)
			{
			if(map_ch[next.x][next.y]=='1') 
			{
				map[next.x][next.y]=0;
				vst[next.x][next.y]=1;
				continue;
			}
			//cout<<"ARRIVE---"<<next.x<<' '<<next.y<<' '<<next.cnt<<endl<<endl;
			if(map_ch[next.x][next.y]=='0') 				
			{
				q.push(next);
				vst[next.x][next.y]=1;
				map[next.x][next.y]=next.cnt;
			}
			}
		}
		q.pop();
	}
	return;
}
int main() {
	scanf("%d%d",&n,&m);
	//freopen("test.txt","w",stdout);
	memset(map,0,sizeof(map));
	memset(Bit,0,sizeof(Bit));
	memset(vst,0,sizeof(vst));
	for(int i=1; i<=n; i++) 	 
	for(int j=1; j<=m; j++) 	 
	{
			cin>>map_ch[i][j];
			if(map_ch[i][j]=='1')q.push((data) {i,j,0});
	}
	bfs_queue();
	for(int i=1; i<=n; i++) 	 
	{
	for(int j=1; j<=m; j++) printf("%d ",map[i][j]);
	printf("\n");
	}
	return 0;
}