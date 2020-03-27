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
const int INF=0x7fffffff/2;
int k,m,s[105],SG[10005];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void GetSG(int x)
{
	if(SG[x]!=-INF)return;
	bool ext[10005];
	memset(ext,0,sizeof(ext));
	for(ri i=1;i<=k;i++)
	{
		if(x-s[i]<0)continue;
		if(SG[x-s[i]]==-INF)
			GetSG(x-s[i]);
		ext[SG[x-s[i]]]=1;//对后继的已有情况作标记 
	}
	for(ri i=0;;i++)
		if(!ext[i]){SG[x]=i;break;}//找到不存在后继状态集合中的最小自然数 
}
int main()
{
	while(k=getint())
	{
		if(k==0)break;
		for(ri i=1;i<=k;i++)s[i]=getint();
		for(ri i=0;i<=10005;i++)SG[i]=-INF;
		SG[0]=0;
		m=getint();
		for(ri i=1;i<=m;i++)
		{
			int cnt=getint(),Ans=0;
			for(ri j=1;j<=cnt;j++)
			{
				int x=getint();
				if(SG[x]==-INF)GetSG(x);//筛SG函数 
				Ans^=SG[x];
			}
			if(Ans)printf("W");
			else printf("L");
		}
		printf("\n");
	}
	return 0;
}
