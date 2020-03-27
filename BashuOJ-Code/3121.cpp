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
int n,tot,a[MAXN],ch[MAXN][2],val[MAXN],b[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u)
{
	if(!u)return;
	DFS(ch[u][0]);
	a[++tot]=val[u];
	DFS(ch[u][1]);
}
int LIS()
{
	int len=0;
	for(ri i=1;i<=tot;i++)
	{
		if(a[i]>=b[len]){b[++len]=a[i];continue;}
		int pos=upper_bound(b+1,b+len+1,a[i])-b;
		b[pos]=a[i];
	}
	return len;
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)val[i]=getint();
	for(ri i=2;i<=n;i++)
	{
		int fa=getint(),x=getint();
		ch[fa][x]=i;
	}
	DFS(1);
	for(ri i=1;i<=tot;i++)a[i]-=i;
	printf("%d\n",tot-LIS());
	return 0;
}

