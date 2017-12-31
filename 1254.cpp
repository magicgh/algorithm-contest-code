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
#define ll long long
using namespace std;
int lx[6]={0,0,1,1,0,1},ly[6]={1,1,0,0,1,0},rx[6]={0,1,2,1,1,1},ry[6]={2,1,0,1,0,-1};
bool vst[10][10];
int n,cnt,block,ans=-0x7fffffff;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int x,int y)
{
	if(++cnt>=1600){printf("%d",ans);exit(0);}
	if(y>8){DFS(x+1,1);return;}
	if(x>n){ans=max(ans,block);return;}
	if(vst[x][y]){DFS(x,y+1);return;}
	vst[x][y]=1;
	for(ri i=0;i<6;i++)
	{
		int ax=x+lx[i],ay=y+ly[i],bx=x+rx[i],by=y+ry[i];
		if(ax>=1&&ax<=n&&ay>=1&&ay<=8&&bx>=1&&bx<=n&&by>=1&&by<=8&&!vst[ax][ay]&&!vst[bx][by])
		{
			vst[ax][ay]=vst[bx][by]=1,block++;DFS(x,y+1);
			vst[ax][ay]=vst[bx][by]=0;block--;
		}
	}
	vst[x][y]=0;DFS(x,y+1);
}
int main()
{
	char ch;
	n=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=8;j++)
		{
			while(ch=getchar())if(isdigit(ch))break;
			vst[i][j]=ch-'0';
		}
	DFS(1,1);
	printf("%d",ans);
	return 0;
}

