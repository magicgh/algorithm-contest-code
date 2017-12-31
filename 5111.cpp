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
const int MAXN=1000005;
int T,cnt,Len;
char ch[MAXN<<1];
ll Ans,List[MAXN<<1],sum[MAXN<<1];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll Solve()
{
	for(ri i=1;i<=Len;i++)ch[i+Len]=ch[i];
	for(ri i=1;i<=2*Len;i++)
	{
		sum[i]=sum[i-1]+(ch[i]=='B');
		if(ch[i]=='R')List[++cnt]=sum[i];
	}
	if(!cnt)return 0;
	for(ri i=1;i<=cnt;i++)sum[i]=sum[i-1]+List[i];
	cnt>>=1;
	for(ri i=1;i<=cnt;i++)
	{
		int mid=(i+i+cnt-1)>>1;
		Ans=min(Ans,List[mid]*(mid-i)-(sum[mid-1]-sum[i-1])+sum[i+cnt-1]-sum[mid]-List[mid]*(i+cnt-1-mid));
	}
	return Ans;
}
int main()
{
	T=GetInt();
	while(T--)
	{
		cnt=0,Ans=1e18;
		scanf("%s",ch+1);
		Len=strlen(ch+1);
		printf("%lld\n",Solve());
	}
	return 0;
}


