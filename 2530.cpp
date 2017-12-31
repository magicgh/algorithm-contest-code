#include<iostream>
#include<iomanip>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
const int MAXN=505;
struct node
{
	int x,y;
 };
vector<int>a[MAXN];
int belong[MAXN];
int ans=0,cntx=0,cnty=0;
char map[MAXN][MAXN];
node num[MAXN][MAXN];
bool vst[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int N,M;
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
	char c;
	for(int i=1;i<=N;i++)
	for(int j=1;j<=M;j++)
	{
		while(c=getchar())if(c=='.'||c=='*')break;
		map[i][j]=c;
	}
	for(int i=1;i<=N;i++)
	for(int j=1;j<=M;j++)
		if(map[i][j]=='*')
		{
			if(map[i][j-1]=='*')num[i][j].x=cntx;
			else num[i][j].x=++cntx;
		}
	for(int j=1;j<=M;j++)
	for(int i=1;i<=N;i++)
		if(map[i][j]=='*')
		{
			if(map[i-1][j]=='*')num[i][j].y=cnty;
			else num[i][j].y=++cnty;
		}
	for(int i=1;i<=N;i++)
	for(int j=1;j<=M;j++)
		if(map[i][j]=='*')a[num[i][j].x].push_back(num[i][j].y);
	for(int i=1;i<=cntx;i++)
	{
		memset(vst,0,sizeof(vst));
		if(DFS(i))ans++;
	}
	printf("%d",ans);
	return 0;
}

