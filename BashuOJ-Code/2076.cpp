/*
ID: baymax01
PROG: castle
LANG: C++                  
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cmath>
#define N 1
#define S 2
#define W 3
#define E 4
using namespace std;
int n,m,Color=0,dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1},Cnt[10005];
bool GFW[85][85][5];
int Vst[85][85];
struct node
{
	int X;
	int Y;
	int Sqaure;
}S_Max[10];
void Castle(int x,int y)
{
	if(x<=0||y<=0)return;
	if(x>n||y>m)return;
	if(GFW[x][y][N]==1&&GFW[x][y][S]==1&&GFW[x][y][E]==1&&GFW[x][y][W]==1)
	{
		Vst[x][y]=Color;
		Cnt[Color]++;
		return;
	}
	for(int i=1;i<=4;i++)
	{
		//cout<<i<<" : "<<x<<' '<<y<<' '<<GFW[x][y][i]<<' '<<Vst[x][y]<<endl; 
		if(GFW[x][y][i]==0&&Vst[x+dx[i]][y+dy[i]]==0)
		{
			Cnt[Color]++;
			//cout<<"Find:::"<<i<<" : "<<x+dx[i]<<' '<<y+dy[i]<<' '<<GFW[x][y][i]<<' '<<Vst[x+dx[i]][y+dx[i]]<<endl; 
			Vst[x+dx[i]][y+dy[i]]=Color;
			Castle(x+dx[i],y+dy[i]);
		}
	}
	return;
}
void CheckWall(int x,int y,int value)
{
	if(value>=8)value-=8,GFW[x][y][S]=1;
	if(value>=4)value-=4,GFW[x][y][E]=1;
	if(value>=2)value-=2,GFW[x][y][N]=1;
	if(value>=1)value-=1,GFW[x][y][W]=1;
	return;
}
void Output_E()
{
	cout<<S_Max[1].Sqaure<<endl<<S_Max[1].X<<' '<<S_Max[1].Y<<" E"<<endl;
	return;
}
void Output_N()
{
	cout<<S_Max[2].Sqaure<<endl<<S_Max[2].X<<' '<<S_Max[2].Y<<" N"<<endl;
	return;
}
int main(){
	/*写疯了2333333333333333333333333333333333333333333333333333333333333333333333*/
	/*By Magicgh  .................CopyRight*/
	//freopen("castle.in","r",stdin);
	//freopen("castle.out","w",stdout);
	int i,j,t,Max=0;
	cin>>m>>n;
	memset(GFW,0,sizeof(GFW));
	memset(Vst,0,sizeof(Vst));
	memset(Cnt,0,sizeof(Cnt));
	memset(S_Max,0,sizeof(S_Max));
	for(i=1;i<=n;i++)
	   for(j=1;j<=m;j++)
	   {
	   	cin>>t;
	   	CheckWall(i,j,t);
       }
      for(i=1;i<=n;i++)
	   for(j=1;j<=m;j++)
	   {
	   	
	   	if(!Vst[i][j])
	   	{
	   		Color++;
	   		Castle(i,j);
	   	}
	   	Max=max(Max,Cnt[Color]);
       }
       cout<<Color<<endl<<Max<<endl;
       //for(i=1;i<=cnt;i++)cout<<Path[i].X<<','<<Path[i].Y<<endl;
       for(j=1;j<=m;j++)
       for(i=n;i>=1;i--)
	   {
   //cout<<i<<' '<<j<<endl;
        	if(GFW[i][j][W]&&(Vst[i][j]!=Vst[i][j-1]))
        	{
        	//cout<<i<<' '<<j<<' '<<Cnt[Vst[i][j]]<<' '<<Cnt[Vst[i][j-1]]<<endl;
        	if(S_Max[1].Sqaure<(Cnt[Vst[i][j]]+Cnt[Vst[i][j-1]]))
        	{
             S_Max[1].Sqaure=Cnt[Vst[i][j]]+Cnt[Vst[i][j-1]];
             S_Max[1].X=i;S_Max[1].Y=j-1;
        	}
         }
         if(GFW[i][j][S]&&(Vst[i][j]!=Vst[i+1][j]))
         {
         	if(S_Max[2].Sqaure<(Cnt[Vst[i][j]]+Cnt[Vst[i+1][j]]))
        	{
             S_Max[2].Sqaure=Cnt[Vst[i][j]]+Cnt[Vst[i+1][j]];
             S_Max[2].X=i+1;S_Max[2].Y=j;
        	}
	   
	}
}
	//cout<<S_Max[1].Sqaure<<' '<<S_Max[1].X<<','<<S_Max[1].Y<<endl;
	//cout<<S_Max[2].Sqaure<<' '<<S_Max[2].X<<','<<S_Max[2].Y<<endl;
if(S_Max[2].Sqaure>S_Max[1].Sqaure)Output_N();
else if(S_Max[2].Sqaure==S_Max[1].Sqaure)
{
	if(S_Max[2].X>S_Max[1].X)Output_N();
    if(S_Max[1].X>S_Max[2].X)Output_E();
	if(S_Max[2].X==S_Max[1].X)
	{
	if(S_Max[2].Y<=S_Max[1].Y)Output_N();
	else Output_E();
}
}
if(S_Max[2].Sqaure<S_Max[1].Sqaure)Output_E();
	return 0;
}