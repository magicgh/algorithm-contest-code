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
#include<map>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=1005;
const int Size=1000000;
const int Limit=1000;
int Ans[MAXN]={1,1};
int n,cnt,tot,d[MAXN];
int p[MAXN],s[MAXN],Cnt[MAXN];
bool vst[MAXN];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Init()
{
	for(ri i=2;i<=Limit;i++)
	{
		if(!vst[i])p[++p[0]]=i;
		for(ri j=1;j<=p[0]&&i*p[j]<=Limit;j++)
		{
			vst[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}
inline void Solve(int x,int add)
{
	for(ri i=2;i<=x;i++)
	{
		int num=i;
		for(ri j=1;j<=p[0];j++)
			while(num%p[j]==0)Cnt[j]+=add,num/=p[j];
	}
}
inline void Multi(int x)
{
	for(ri i=1;i<=Ans[0];i++)Ans[i]*=x;
	for(ri i=1;i<=Ans[0];i++)
		Ans[i+1]+=Ans[i]/Size,Ans[i]%=Size;
	while(Ans[Ans[0]+1]>0)
		Ans[0]++,Ans[Ans[0]+1]+=Ans[Ans[0]]/Size,Ans[Ans[0]]%=Size;
}
inline void Print()
{
	if(Ans[0]>=1)printf("%d",Ans[Ans[0]]);
	for(ri i=Ans[0]-1;i>=1;i--)printf("%06d",Ans[i]);
}
int main()
{	
	Init();
	n=GetInt();
	for(ri i=1;i<=n;i++)d[i]=GetInt();
	if(n==1)return printf((!d[1])?"1\n":"0\n"),0;
	for(ri i=1;i<=n;i++)
	{
		if(!d[i])return printf("0\n"),0;
		if(d[i]==-1)cnt++;
		else tot+=(--d[i]);
	}
	if(tot>n-2)return printf("0\n"),0;
	Solve(n-2,1),Solve(n-2-tot,-1);
	for(ri i=1;i<=n;i++)
		if(d[i])Solve(d[i],-1);
	for(ri i=1;i<=p[0];i++)
		while(Cnt[i]--)Multi(p[i]);
	for(ri i=1;i<=n-2-tot;i++)Multi(cnt);
	Print();
	return 0;
}