#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=100005;
map<ll,int>List;
map<int,int>Hash;
int n,k,cnt,Size,Ans;
ll a[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline const ll getll()
{
	ll num=0;int bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Delete(int x)
{
	Hash[List[a[x]]]--;
	if(!Hash[List[a[x]]])Size--;
}
inline void Add(int x)
{
	if(!Hash[List[a[x]]])Size++;
	Hash[List[a[x]]]++;
}
int main()
{
	n=getint(),k=getint();
	for(ri i=1;i<=n;i++)
	{
		a[i]=getll();
		if(!List[a[i]])List[a[i]]=++cnt;
	}
	int l=1,r;
	for(r=1;r<=n;r++)
	{
		Add(r);
		while(Size>k+1)
			Delete(l),l++;
		Ans=max(Ans,Hash[List[a[r]]]);
	}
	printf("%d\n",Ans);
	return 0;
}


