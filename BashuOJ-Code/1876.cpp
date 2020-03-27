#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#define ri register int
#define ll long long
using namespace std;
int T;
ll n,num[25],f[25][10];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll GetLL()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
ll DFS(int d,int last,bool flag)
{
	if(!d)return 1;
	if(f[d][last]!=-1&&!flag)return f[d][last];
	ll ret=0,Limit=flag?num[d]:9;
	for(ri i=0;i<=Limit;i++)
	{
		if(last==4&&i==9)continue;
		ret+=DFS(d-1,i,(i==Limit&&flag));
	}
	if(!flag)f[d][last]=ret;
	return ret;
}
inline ll DP()
{
	int len=0;ll t=n;
	while(t)
	{
		num[++len]=t%10;
		t/=10;
	}
	return n-DFS(len,0,1)+1;
}
int main()
{
	T=GetInt();
	while(T--)
	{
		memset(f,-1,sizeof(f));
		n=GetLL();
		printf("%lld\n",DP());
	}
	return 0;
}