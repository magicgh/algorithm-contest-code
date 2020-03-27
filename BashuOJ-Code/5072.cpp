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
const int MAXN=100005;
struct Path{int x,y,z;};
int n,m,dep[MAXN];
vector<int>a[MAXN];
vector<Path>Ans; 
bool vst[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int Tarjan(int u,int fa,int depth)
{
	vector<int>List;
	dep[u]=depth,vst[u]=1;
	for(auto it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		if(vst[*it])
		{
			if(dep[*it]<dep[u])List.push_back(*it);
		}
		else
		{
			int Extra=Tarjan(*it,u,depth+1);
			if(Extra!=-1)
				Ans.push_back((Path){u,*it,Extra});
			else List.push_back(*it);
		}
	}
	for(unsigned ri i=0;i+1<List.size();i+=2)
		Ans.push_back((Path){List[i],u,List[i+1]});
	if(List.size()&1)return List.back();
	else return -1;
}
int main()
{
	int size=40<<20;//40M
	__asm__ ("movq %0,%%rsp\n"::"r"((char*)malloc(size)+size));
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint();
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(ri i=1;i<=n;i++)
		if(!vst[i])Tarjan(i,0,0);
	printf("%d\n",Ans.size());
	for(auto it=Ans.begin();it!=Ans.end();++it)
		printf("%d %d %d\n",it->x,it->y,it->z);
	exit(0);
	return 0;
}


