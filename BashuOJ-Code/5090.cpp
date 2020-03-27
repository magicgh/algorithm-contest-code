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
const int MAXM=205;
struct Query{int l,r;};
Query q[MAXM];
int N,M,K,H,Ans,MaxH,Count;
int sum[MAXN],f[MAXM][MAXM];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const Query &a,const Query &b){return (a.l==b.l&&a.r<b.r)||(a.l<b.l);}
int main()
{
	N=GetInt(),M=GetInt(),H=GetInt(),K=GetInt();
	for(ri i=1;i<=N;i++)
	{
		int Apple=GetInt();
		if(Apple<H)continue;
		Count=(Apple==H)?Count+1:Count;
		sum[Apple-H]++;
		MaxH=max(MaxH,Apple-H);
	}
	for(ri i=1;i<=M;i++)
	{
		int l=GetInt(),r=GetInt();
		q[i]=(Query){l,r};
		MaxH=max(MaxH,r);
	}
	for(ri i=1;i<=MaxH;i++)
		sum[i]+=sum[i-1];
	sort(q+1,q+M+1,cmp);
	for(ri i=1;i<=K;i++)
		for(ri j=1;j<=M;j++)
			for(ri k=i-1;k<j;k++)
			{
				int Seq=sum[q[j].r]-max((q[j].l?sum[q[j].l-1]:0),sum[q[k].r]);
				f[i][j]=max(f[i][j],f[i-1][k]+Seq);
				if(i==K)Ans=max(Ans,f[i][j]);
			}
	printf("%d\n",Ans+Count);
	return 0;
}

