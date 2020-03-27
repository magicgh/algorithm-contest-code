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
const int MAXN=205;
const ll INF=1e18;
const int MAXM=10005;
int Case,cnt1,cnt2,N,M,A,B;
ll Ave,Ans,x[MAXM],g[MAXN],sum[MAXM],f[MAXN][MAXM];
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
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	Case=getint();
	while(Case--)
	{
		Ans=INF,cnt1=cnt2=Ave=0;
		M=getint(),N=getint(),A=getint(),B=getint();
		for(ri i=1;i<=M;i++)x[i]=getll(),Ave+=x[i];
		for(ri i=1;i<=N;i++)g[i]=getll();
		Ave/=(ll)M;
		for(ri i=1;i<=M;i++)
			sum[i]=sum[i-1]+(x[i]-Ave)*(x[i]-Ave);
		for(ri i=0;i<=N;i++)
			for(ri j=0;j<=M;j++)f[i][j]=INF;
		f[0][0]=0;
		deque<int>q;
		for(ri i=1;i<=N;i++)
		{
			q.clear();
			for(ri j=i*A;j<=i*B&&j<=M;j++)
			{
				while(!q.empty()&&q.front()<j-B)q.pop_front();
				while(!q.empty()&&f[i-1][q.back()]-sum[q.back()]*g[i]>f[i-1][j-A]-sum[j-A]*g[i])q.pop_back();
				q.push_back(j-A);
				f[i][j]=f[i-1][q.front()]+(sum[j]-sum[q.front()])*g[i];
			}
		}
		for(ri i=1;i<=N;i++)
			if(f[i][M]<Ans)
				Ans=f[i][M],cnt1=i;
		if(cnt1==1)cnt2=M;
		else for(ri i=M-B;i<=M-A;i++)
			if(f[cnt1-1][i]+(sum[M]-sum[i])*g[cnt1]==Ans)cnt2=M-i;
		printf("%lld %d %d\n",Ans,cnt1,cnt2);
	}
	return 0;
}


