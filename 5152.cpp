#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=20;
int Ans,pos,Cnt[5][20];
struct Card
{
	int x,y;
	inline void Input()
	{
		register char ch;
		register int x,y;
		scanf("%d%c",&y,&ch);
		if(ch=='w')x=1;
		if(ch=='p')x=2;
		if(ch=='s')x=3;
		this->x=x,this->y=y;
		Cnt[x][y]++;
	}
};
Card c[MAXN];
inline bool Check(int color)
{
	int Cnt2=0;
	for(ri i=1;i<=9;i++)
	{
		if(!Cnt[color][i])continue;
		else if(Cnt[color][i]!=2&&Cnt[color][i]!=3)return 0;
		else if(Cnt[color][i]==2)
		{
			Cnt2++;
			if(Cnt2>1)return 0;
		}
	}
	return 1;
}
inline bool DFS(int color)
{
	for(ri i=1;i<=7;i++)
	{
		if(Cnt[color][i]&&Cnt[color][i+1]&&Cnt[color][i+2])
		{
			Cnt[color][i]--;
			Cnt[color][i+1]--;
			Cnt[color][i+2]--;
			bool bj=DFS(color);
			Cnt[color][i]++;
			Cnt[color][i+1]++;
			Cnt[color][i+2]++;
			if(bj)return 1;
		}
	}
	return Check(color);
}
inline int Search(int id)
{
	int ret=0;
	Card &now=c[id];
	for(ri j=1;j<=9;j++)
		for(ri i=1;i<=3;i++)	
		{
			bool Flag=0;
			Cnt[i][j]++,Cnt[now.x][now.y]--;
			for(ri k=1;k<=3;k++)
				if(!DFS(k)){Flag=1;break;}
			Cnt[i][j]--,Cnt[now.x][now.y]++;
			if(!Flag)ret+=4-Cnt[i][j];
		}
	return ret;
}
int main()
{
	for(ri i=1;i<=14;i++)c[i].Input();
	for(ri i=1;i<=14;i++)
	{
		int ret=Search(i);
		if(ret>Ans)Ans=ret,pos=i;
	}
	printf("%d %d\n",pos,Ans);
	return 0;
}
