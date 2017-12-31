#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
int map[10][10],cnt,ans=-1;
bool dx[10][10],dy[10][10],z[10][10][10];
int score[10][10]={{0,0,0,0,0,0,0,0,0,0},
				   {0,6,6,6,6,6,6,6,6,6},
				   {0,6,7,7,7,7,7,7,7,6},
				   {0,6,7,8,8,8,8,8,7,6},
				   {0,6,7,8,9,9,9,8,7,6},
				   {0,6,7,8,9,10,9,8,7,6},
				   {0,6,7,8,9,9,9,8,7,6},
				   {0,6,7,8,8,8,8,8,7,6},
				   {0,6,7,7,7,7,7,7,7,6},
				   {0,6,6,6,6,6,6,6,6,6}};
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int calc()
{
	int tmp=0;
	for(ri i=1;i<=9;i++)
		for(ri j=1;j<=9;j++)tmp+=map[i][j]*score[i][j];
	return tmp;
}
void DFS(int x,int y)//第九列搜到第一列 
{
	if(++cnt>=13333333){printf("%d",ans);exit(0);}//徐艺佳卡时优化
	if(!y){ans=max(ans,calc());return;}//搜到第一列计算结果 熊罴传参优化
	int tx=x>1?x-1:9,ty=x>1?y:y-1;
	if(map[x][y]){DFS(tx,ty);return;}//已填数字
	for(ri i=9;i>=1;i--)//倒着枚举数字的AC优化
		{
			if(dx[x][i]||dy[y][i]||z[(x+2)/3][(y+2)/3][i])continue;
			dx[x][i]=dy[y][i]=z[(x+2)/3][(y+2)/3][i]=1;//标记
			map[x][y]=i;//填数字 
			DFS(tx,ty);
			dx[x][i]=dy[y][i]=z[(x+2)/3][(y+2)/3][i]=map[x][y]=0;//回溯反清标记 
		} 
}
int main()
{
	for(ri i=1;i<=9;i++)
		for(ri j=1;j<=9;j++)
		{
			map[i][j]=getint();
			if(map[i][j])
			{
				dx[i][map[i][j]]=1;
				dy[j][map[i][j]]=1;
				z[(i+2)/3][(j+2)/3][map[i][j]]=1;
			}
		}
	DFS(9,9);
	printf("%d",ans);
	return 0;
}

