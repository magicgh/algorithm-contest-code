#include<iostream>
#include<iomanip>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
const int MAXN=105;
int ans=0;
vector<int>a[MAXN];
int belong[MAXN];
bool vst[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
int N,M,K;
bool DFS(int x)
{
	vector<int>::iterator i;
	for(i=a[x].begin();i!=a[x].end();++i)
	{
		if(vst[*i])continue;
		vst[*i]=1;
		if(!belong[*i]||DFS(belong[*i]))
		{
			belong[*i]=x;
			return 1;
		}
	}
	return 0;
}
int main(){
	N=GetInt();
	M=GetInt();
	K=GetInt();
	for(int i=1;i<=K;i++)
	{
		int cmd=GetInt(),x=GetInt(),y=GetInt();
		if(x==0||y==0)continue;//可能从0模式开始工作 
		a[x].push_back(y);
	}
	for(int i=1;i<=N;i++)
	{
		memset(vst,0,sizeof(vst));
		if(DFS(i))ans++;
	}
	printf("%d",ans);
	return 0;
}