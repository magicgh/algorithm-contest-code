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
const int MAXN=100005;
int n,a1;
double Ans;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	//freopen("t.in","r",stdin);
	//freopen("t.out","w",stdout);
	n=getint(),a1=getint(),Ans=n;
	for(ri i=2;i<=n;i++)
	{
		double x=getint();
		Ans=(Ans-a1/(a1+x));
	}
	printf("%.8lf",Ans);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}


