#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
using namespace std;
struct mojang
{
	int x,y,count;
}map[100005];
bool vst[105][105],data[105][105];
int w,m,x1,x2,y1,y2;
int dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1};
bool bfs()
{	
	memset(vst,0,sizeof(vst));
	memset(map,0,sizeof(map));
	map[1].x=x1,map[1].y=y1,map[1].count=0;
	int h=1,t=1,x,y;
	vst[x1][y1]=1;
	//cout<<x1<<' '<<y1<<' '<<vst[x1][y1]<<endl;
	while(h<=t)
	{
		for(int i=1;i<=4;i++)
		for(int j=1;;j++)
		{
			x=map[h].x+dx[i]*j;
			y=map[h].y+dy[i]*j;
			//cout<<"###"<<h<<' '<<t<<"    "<<x<<' '<<y<<' '<<' '<<data[x][y]<<' '<<vst[x][y]<<endl;
			//cout<<(x>h+1)<<endl<<endl;
			if(x<0||x>m+1||y<0||y>w+1||(data[x][y]))break;
			//cout<<"yes"<<endl<<endl;
			if((!vst[x][y]))
			{
			
				t++;
				map[t].x=x,map[t].y=y,map[t].count=map[h].count+1;
				vst[x][y]=1;
				if(x==x2&&y==y2)
				{
					cout<<map[t].count<<endl;
					return 1;
				}
				}
				//	cout<<h<<' '<<t<<"    "<<x<<' '<<y<<' '<<vst[x][y]<<endl;
		}
	   h++;
	}
	return 0;
}
int main(){
	scanf("%d%d",&w,&m);
	memset(data,0,sizeof(data));
	getchar();
	for(int i=1;i<=m;i++)
	   for(int j=1;j<=w+1;j++)
	   {
	   	if(getchar()=='X')data[i][j]=1;
	   }
	while(scanf("%d%d%d%d",&y1,&x1,&y2,&x2))
	{
	if((y1==0&&x1==0&&y2==0&&x2==0))break;
    data[x2][y2]=0;
    if(!bfs())cout<<0<<endl;
    data[x2][y2]=1;
	}
	return 0;
}
