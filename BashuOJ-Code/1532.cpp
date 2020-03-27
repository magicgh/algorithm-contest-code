#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=505;
const int INF=0x7fffffff;
int N,M,Edge[MAXN][MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
struct StoerWagner
{
	int S,T,wage[MAXN];
	bool vst[MAXN],ext[MAXN];
	int Cut()
	{
		memset(vst,0,sizeof(vst));
		memset(wage,0,sizeof(wage));
		S=T=-1;
		int mincut,Num=0;
		for(int i=0;i<N;i++)
		{
			int Max=-INF;
			for(int j=0;j<N;j++)
				if(!ext[j]&&!vst[j]&&Max<wage[j])Max=wage[j],Num=j;
			if(Num==T)return mincut;
			S=T,T=Num;
			mincut=Max;
			vst[Num]=1;
			for(int j=0;j<N;j++)
				if(!ext[j]&&!vst[j])wage[j]+=Edge[Num][j];
		}
		return mincut;
	}
	int main()
	{
		int ans=INF;
		memset(ext,0,sizeof(ext));
		for(int i=1;i<N;i++)//需要合并N-1次
		{
			ans=min(ans,Cut());//更新 
			if(!ans)return ans;
			ext[T]=1;
			for(int j=0;j<N;j++)
			{
				if(!ext[j]&&j!=S)//合并S,T 
				{
					Edge[S][j]+=Edge[T][j];
					Edge[j][S]+=Edge[j][T];
				}
			}
		}
		return ans;
	}
};
StoerWagner MinCut;
int main()
{
	while(~scanf("%d%d",&N,&M))
	{
		memset(Edge,0,sizeof(Edge));
		for(int i=1;i<=M;i++)
		{
			int x=GetInt(),y=GetInt(),v=GetInt();
			Edge[x][y]+=v;
			Edge[y][x]+=v;
		}
		printf("%d\n",MinCut.main());
	}
   return 0;
}
