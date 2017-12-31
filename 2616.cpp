#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1};
int R,C,map[45][45],ans=0;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int x,int y)
{
	ans+=map[x][y];
	if(x==R&&y==C)return;
	map[x][y]=-0x7fffffff/2;
	int Max=-0x7fffffff,Mx=0,My=0;
	for(int i=1;i<=4;i++)
	{
		if(x+dx[i]<1||x+dx[i]>R||y+dy[i]<1||y+dy[i]>C)continue;
		if(Max<map[x+dx[i]][y+dy[i]])
		{
			Max=map[x+dx[i]][y+dy[i]];
			Mx=x+dx[i],My=y+dy[i];
		}
	}
	DFS(Mx,My);
}
int main(){
	R=GetInt();
	C=GetInt();
	for(int i=1;i<=R;i++)
	for(int j=1;j<=C;j++)map[i][j]=GetInt();
	DFS(1,1);
	printf("%d",ans);
	return 0;
}
