#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int MAXN=1005;
vector<int>a[MAXN];
bool vst[MAXN];
int belong[MAXN];
int N,M,K,Ans=0;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
bool DFS(int x)
{
	vector<int>::iterator it;
	for(it=a[x].begin();it!=a[x].end();++it)
	{
		if(vst[*it])continue;
		vst[*it]=1;
		if(!belong[*it]||DFS(belong[*it]))
		{
			belong[*it]=x;return 1;
		}
	}
	return 0;
}
int main(){
	K=GetInt();
	while(K--)
	{
		Ans=0;
		for(int i=1;i<=1005;i++)a[i].clear(),vst[i]=0,belong[i]=0;
		N=GetInt();M=GetInt();
		if(N<M)swap(N,M);
		for(int i=1;i<=M;i++)
		{
			int x=GetInt(),y=GetInt();
			a[x].push_back(i);
			a[y].push_back(i);
		}
		for(int i=1;i<=N;i++)
		{
			memset(vst,0,sizeof(vst));
			if(DFS(i))Ans++;
		}
		printf(Ans==M?"YES\n":"NO\n");
	}
	return 0;
}