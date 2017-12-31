#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
#include<stack>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=40005;
const int INF=0x7fffffff/2;
int n,m,len,part;
int num[MAXN],val[MAXN],block[MAXN],Cnt[MAXN],f[205][205];
vector<int>a[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Init(int x)
{
	memset(Cnt,0,sizeof(Cnt));
	int cnt=0,ans=0;
	for(ri i=(x-1)*part+1;i<=n;i++)
	{
		int belong=block[i];
		Cnt[val[i]]++;
		if(Cnt[val[i]]>cnt||(cnt==Cnt[val[i]]&&ans>val[i]))
			cnt=Cnt[val[i]],ans=val[i];
		f[x][belong]=ans;
	}
}
inline int Binary(int l,int r,int v)
{
	return upper_bound(a[v].begin(),a[v].end(),r)-lower_bound(a[v].begin(),a[v].end(),l);
}
inline int Query(int l,int r)
{
	int ans=f[block[l]+1][block[r]-1];
	int cnt=Binary(l,r,ans);
	for(ri i=l;i<=min(block[l]*part,r);i++)
	{
		int Count=Binary(l,r,val[i]);
		if(Count>cnt||(cnt==Count&&ans>val[i]))
			cnt=Count,ans=val[i];
	}
	if(block[l]==block[r])return num[ans];
	for(ri i=(block[r]-1)*part+1;i<=r;i++)
	{
		int Count=Binary(l,r,val[i]);
		if(Count>cnt||(cnt==Count&&ans>val[i]))
			cnt=Count,ans=val[i];
	}
	return num[ans];
}
int main()
{
	n=GetInt(),m=GetInt(),part=sqrt(n);
	for(ri i=1;i<=n;i++)
		val[i]=num[i]=GetInt();
	sort(num+1,num+n+1);
	len=unique(num+1,num+n+1)-(num+1);
	for(ri i=1;i<=n;i++)
	{
		int x=lower_bound(num+1,num+len+1,val[i])-num;
		val[i]=x;
		a[x].push_back(i);
	}	
	for(ri i=1;i<=n;i++)block[i]=(i-1)/part+1;
	for(ri i=1;i<=block[n];i++)Init(i);
	int x=0;
	for(ri i=1;i<=m;i++)
	{
		int u=GetInt(),v=GetInt();
		int l=(u+x-1)%n+1,r=(v+x-1)%n+1;
		if(l>r)swap(l,r);
		printf("%d\n",x=Query(l,r));
		
	}
	return 0;
}