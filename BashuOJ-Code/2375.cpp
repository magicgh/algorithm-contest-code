#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
int num[35];
ll f[35][15];
ll A,B;
inline ll getll()
{
	ll num=0;
	int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
ll DFS(int pos,int last,bool bj)
{
	if(!pos)return 1;
	if(f[pos][last]!=-1&&!bj)return f[pos][last];
	int Limit=bj?num[pos]:9;ll Ans=0;
	for(int i=0;i<=Limit;i++)
	{
		if(abs(last-i)<2)continue;
		if(last==11&&i==0)Ans+=DFS(pos-1,11,bj&&i==Limit);
		else Ans+=DFS(pos-1,i,bj&&i==Limit);
	}
	if(!bj)f[pos][last]=Ans;
	return Ans;
}
inline ll Calc(ll x)
{
	num[0]=0;
	while(x)
	{
		num[++num[0]]=x%10;
		x/=10;
	}
	num[num[0]+1]=-1;
	return DFS(num[0],11,1);
}
int main()
{
	A=getll(),B=getll();
	if(A>B)swap(A,B);
	memset(f,-1,sizeof(f));
	printf("%lld",Calc(B)-Calc(A-1));
	return 0;
}

