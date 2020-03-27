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
const int MAXN=105;
char ch[MAXN];
int n,m,Ans,Hash[MAXN][30],g[MAXN][MAXN];
int List[MAXN],f[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool Check(int a,int b)
{
	for(ri i=1;i<=26;i++)
		if(Hash[a][i]&&Hash[b][i]&&Hash[a][i]!=Hash[b][i])return 0;
		return 1;
}
inline bool DFS(int u,int cnt)
{
	for(ri i=u+1;i<=m;i++)
	{
		if(f[i]+cnt<=Ans)return 0;//最优性剪枝
		if(g[u][i])
		{
			bool bj=1;
			for(ri j=1;j<=cnt;j++)
				if(!g[i][List[j]]){bj=0;break;}
			if(bj)//u和i已匹配，由i点向下找到新的匹配串 
			{
				List[cnt+1]=i;
				if(DFS(i,cnt+1))return 1;
			}
		}
	}
	if(cnt>Ans)
	{
		Ans=cnt;
		return 1;
	} 
	return 0;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		scanf("%s",ch+1);
		int len=strlen(ch+1);
		for(ri j=1;j<=len;j++)
			Hash[i][int(ch[j]-64)]=getint();
	}
	for(ri i=1;i<m;i++)
		for(ri j=i+1;j<=m;j++)
		if(Check(i,j))g[i][j]=g[j][i]=1;
	for(ri i=m;i>=1;i--)
	{
		List[1]=i;
		DFS(i,1);
		f[i]=Ans;
	}
	printf("%d",Ans);
	return 0;
}

