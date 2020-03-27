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
const int Mod=1000000007;
const int MAXN=205;
int n,a[MAXN]; 
ll Ans;
inline const int GetInt()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=GetInt();
	for(ri i=1;i<=n;i++)a[i]=GetInt();
	stable_sort(a+1,a+n+1,greater<int>()); 
	Ans=a[1];
	for(ri i=2;i<=n;i++)
		Ans=(Ans*a[i]%Mod+1)%Mod;
	printf("%lld\n",Ans%Mod);
	return 0;
}