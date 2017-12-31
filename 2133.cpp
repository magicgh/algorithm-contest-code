#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int MAXN=205;
vector<int>a[MAXN];
bool vst[MAXN];
int belong[MAXN];
int N,M,Ans=0;
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
	int x;
	N=GetInt();
	M=GetInt();
	for(int i=1;i<=N;i++)
	{
		x=GetInt();
		for(int j=1;j<=x;j++)a[i].push_back(GetInt());
	}
	for(int i=1;i<=N;i++)
	{
		memset(vst,0,sizeof(vst));
		if(DFS(i))Ans++;
	}
	printf("%d",Ans);
	return 0;
}
