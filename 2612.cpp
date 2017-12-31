#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=1000005;
int n,t,Next,phi[MAXN],p[MAXN];
ll sphi[MAXN];
bool vst[MAXN];
ll Ans;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Init()
{
	int Limit=1000000;
	phi[1]=1;
	for(int i=2;i<=Limit;i++)
	{
		if(!vst[i])p[++p[0]]=i,phi[i]=i-1;
		for(int j=1;j<=p[0]&&i*p[j]<=Limit;j++)
		{
			vst[i*p[j]]=1;
			if(i%p[j]==0){phi[i*p[j]]=phi[i]*p[j];break;}
			phi[i*p[j]]=phi[i]*phi[p[j]];
		}
	}
	for(int i=1;i<=Limit;i++)sphi[i]=sphi[i-1]+phi[i];
}
int main()
{
	Init();
	t=getint();
	while(t--)
	{
		n=getint();Ans=0;
		for(int i=1;i<=n;i=Next+1)
		{
			Next=n/(n/i);
			Ans+=(sphi[Next]-sphi[i-1])*(ll)(n/i)*(ll)(n/i);
		}		
		Ans-=(ll)(1+n)*(ll)(n)/2,Ans/=2;	
		printf("%lld\n",Ans);
	}
	return 0;
}

