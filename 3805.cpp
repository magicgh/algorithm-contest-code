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
int n,w,f[20],c[20];	
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int x,int Dep)
{
	if(x>=n+1)
	{
		printf("%d\n",Dep);
		exit(0);
	}
	for(ri i=1;i<=Dep;i++)
	{
		if(x<i)return;
		if(f[i]+c[x]<=w)
		{
			f[i]+=c[x];
			DFS(x+1,Dep);
			f[i]-=c[x];
		}
	}
}
int main()
{
	n=getint(),w=getint();
	for(ri i=1;i<=n;i++)c[i]=getint();
	for(ri i=1;i<=n;i++)//枚举缆车数量(限定深度) 
		DFS(1,i);
	return 0;
}


