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
const ll Mod=1000000007ll;
const int MAXN=10000010;
const int MAXM=200005;
int T,n,m,tot,prt[MAXN],List[MAXM];
ll Ans;
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	return prt[u]=getfa(prt[u]);
}
int main()
{
	T=GetInt();
	for(ri i=1;i<=10000005;i++)prt[i]=i;
	while(T--)
	{
		n=GetInt(),m=GetInt(),Ans=1,tot=0;
		for(ri i=1;i<=m;i++)
		{
			int l=GetInt(),r=GetInt()+1;
			List[++tot]=l,List[++tot]=r;
			int f1=getfa(l),f2=getfa(r);
			if(f1!=f2)
			{
				prt[f1]=f2;
				Ans=(Ans<<1)%Mod;
			}
		}
		for(ri i=1;i<=tot;i++)prt[List[i]]=List[i];
		printf("%lld\n",Ans);
	}
	return 0;
}


