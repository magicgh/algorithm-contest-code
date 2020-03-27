#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<queue>
using namespace std;
struct data
{
	int x,y,cnt;
}Angel[100005];
char map[205][205];
bool vst[205][205];
int n,m,amn=0,dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1};
bool bfs_queue(int xx,int yy)
{
	queue<data>q;
	q.push((data){xx,yy,0});
	vst[xx][yy]=1;
	//cout<<xx<<' '<<yy<<' '<<vst[xx][yy]<<endl;
	while(!q.empty())
	{
		data now=q.front();
		//cout<<"NOW-----"<<":"<<now.x<<' '<<now.y<<' '<<' '<<map[now.x][now.y]<<' '<<vst[now.x][now.y]<<endl;
		if(map[now.x][now.y]=='x')
		{
			//cout<<"here"<<endl;
			map[now.x][now.y]='.';
			vst[now.x][now.y]=0;
			now.cnt+=1;
			q.pop();
			q.push(now);
			continue;
		}
		for(int i=1;i<=4;i++)
		{
			
			data next;
			next.x=now.x+dx[i];
			next.y=now.y+dy[i];
			next.cnt=now.cnt+1;
			
	        //cout<<now.x<<' '<<dx[i]<<"###"<<endl;
			//cout<<"###"<<i<<":"<<next.x<<' '<<next.y<<' '<<' '<<map[next.x][next.y]<<' '<<vst[next.x][next.y]<<endl;
			if(next.x>0&&next.x<=n&&next.y>0&&next.y<=m&&(!vst[next.x][next.y])&&(map[next.x][next.y]!='#'))
			{
				//cout<<"yes"<<endl<<endl;
				//cout<<"GOTO"<<next.x<<' '<<next.y<<' '<<' '<<' '<<vst[next.x][next.y]<<"No."<<next.cnt<<endl;
					q.push(next);
					vst[next.x][next.y]=1;
				    	if(map[next.x][next.y]=='r')
				    	{
				    		cout<<next.cnt;
				    		return 1;
						}
			}
		}
		q.pop();
	}
	return 0;
}
int main(){
	//freopen("test.txt","w",stdout);
	int anx,any;
	scanf("%d%d",&n,&m);
	memset(vst,0,sizeof(vst));
	memset(Angel,0,sizeof(Angel));
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=m;j++)
	   {
	   cin>>map[i][j];
	   if(map[i][j]=='a')anx=i,any=j;
}
if(!(bfs_queue(anx,any)))cout<<"Poor ANGEL.";
	return 0;
}
