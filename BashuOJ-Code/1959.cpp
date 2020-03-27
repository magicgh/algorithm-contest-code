#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=10000005;
int n,A,B,C,a[MAXN];
double Ans;
inline int max(const int &a,const int &b){return a>b?a:b;}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Input()
{
	n=getint(),A=getint(),B=getint(),C=getint(),a[1]=getint();
	for(int i=2;i<=n;i++) 
	a[i]=((ll)a[i-1]*A+B)%100000001;
	for(int i=1;i<=n;i++)a[i]=a[i]%C+1; 
}
int main()
{
	Input();
	for(ri i=1;i<n;i++)
		Ans+=(1.0/(double)max(a[i],a[i+1]));
	Ans+=(1.0/(double)max(a[1],a[n]));
	printf("%.3lf",Ans);
	return 0;
}
