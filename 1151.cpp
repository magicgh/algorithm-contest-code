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
const int MAXN=500005;
int N,A,B,x[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool Check(int Limit)
{
	int sum=0;
	for(ri i=1;i<=N;i++)
	{
		if(x[i]>Limit*A)
			sum+=ceil((x[i]-Limit*A)/(double)B);
	}
	return sum<=Limit;
}
inline int Binary()
{
	int l=0,r=N;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(Check(mid))r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main()
{
	//freopen("t.in","r",stdin);
	//freopen("t.out","w",stdout);
	N=getint(),A=getint(),B=getint();
	for(ri i=1;i<=N;i++)
		x[i]=getint();
	printf("%d\n",Binary());
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}


