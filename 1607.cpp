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
const int MAXN=50005;
int N,L,Ans,f[MAXN],Last[1000005],a[MAXN];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	N=GetInt(),L=GetInt();
	for(ri i=1;i<=N;i++)a[i]=GetInt();
	for(ri i=1;i<=N;i++)
	{
		for(ri j=1;j<=sqrt(a[i]);j++)
		{
			if(a[i]%j)continue;
			if(j>=L)f[i]=max(f[i],f[Last[j]]+1);
			if(a[i]/j>=L)f[i]=max(f[i],f[Last[a[i]/j]]+1);
			Last[j]=Last[a[i]/j]=i;
		}
		Ans=max(Ans,f[i]);
	}
	printf("%d\n",Ans);
	return 0;
}


