#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int MAXN=505;
int N,M,Ans;
vector<int>Edge[MAXN];
bool map[MAXN][MAXN];
int vst[MAXN],belong[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
bool DFS(int x,int k)
{
	vector<int>::iterator it;
	for(it=Edge[x].begin();it!=Edge[x].end();++it)
	{
		if(vst[*it]==k)continue;
		vst[*it]=k;
		if(!belong[*it] or DFS(belong[*it],k))
		{
			belong[*it]=x;
			return 1;
		}
	}
	return 0;
}
int main(){
	while(~scanf("%d%d",&N,&M))
	{
		if(M==0&&N==0)break;
		if(M==0){printf("%d\n",N);continue;} 
		Ans=0;
		for(int i=1;i<=N;i++)Edge[i].clear();
		memset(map,0,sizeof(map));
		memset(belong,0,sizeof(belong));
		memset(vst,0,sizeof(vst));
		for(int i=1;i<=M;i++)map[GetInt()][GetInt()]=1;
		for(int k=1;k<=N;k++)
		for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)map[i][j]=map[i][j]||map[i][k]&&map[k][j];
		for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)if(map[i][j])Edge[i].push_back(j);
		for(int i=1;i<=N;i++)if(DFS(i,i))Ans++;
		printf("%d\n",N-Ans);
	}
	return 0;
}