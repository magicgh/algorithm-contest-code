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
vector<int>order;
int money,gunx,guny,gunz,used[10][10];
int b[10][10]=
{
	{0},{5,400,500,600,650,750},
	{2,1700,3000},{4,1250,1500,1700,2350},
	{6,2250,2750,3100,3500,4200,4750},
	{1,5750},{1,50},{1,25},
	{8,650,1000,200,300,300,200,1250,2200}
};
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{ 
		if(c==EOF)return EOF;
		bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	} 
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool Check(int x,int y)
{
	if(money<b[x][y])return 0;
	if(x>=1&&x<=5&&used[x][y])return 0;
	if(x==6||x==7)
	{
		if(used[x][1]>=5)return 0;
		if((x==6&&!gunx)||(x==7&&!gunz))return 0;
	}
	if(x==8)
	{
		if(y!=3&&used[x][y]||y==1&&used[8][2])return 0;
		if((y==8&&gunx)||(y==3&&used[x][y]>=2))return 0;
	}
	return 1;	
}
int main()
{
	money=getint(),used[1][2]=1,gunz=2;
	while(true)
	{
		int t=getint();
		if(t==EOF)break;
		order.push_back(t);
	}
	vector<int>::iterator it;
	for(it=order.begin();it!=order.end();++it)
	{
		int x=!(*it/10)?(*it%10):(*it/10),y=!(*it/10)?1:(*it%10);
		if(!Check(x,y))continue;
		money-=b[x][y];
		if(x==1)
		{
			used[1][gunz]=0,used[7][1]=0;
			gunz=y,used[1][gunz]++;
		}
		if(x>=2&&x<=5)
		{
			used[gunx][guny]=0,used[6][1]=0;
			gunx=x,guny=y,used[gunx][guny]++;
		}
		if(x>=6&&x<=7)used[x][1]++;
		if(x==8)
		{
			if(y==2&&used[8][1])used[8][1]--,used[8][2]++;
			else if(y==8)gunx=8,guny=8,used[x][y]++,used[6][1]=0;
			else used[x][y]++;
		}
	}
	printf("%d\n",money);
	if(gunx)printf("B%d%d %d\n",gunx,guny,used[6][1]);
	else printf("empty\n");
	if(gunz)printf("B1%d %d\n",gunz,used[7][1]);
	else printf("empty\n");	
	for(ri i=1;i<b[8][0];i++)
		for(ri j=1;j<=used[8][i];j++)printf("B8%d",i); 
	return 0;
}
