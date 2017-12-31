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
int n,Max,f[250][250];
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
	n=getint();
	for(ri i=1;i<=n;i++)f[i][i]=getint();
	for(ri len=2;len<=n;len++)
	{
		for(ri s=1;s+len-1<=n;s++)
		{
			int t=s+len-1;
			for(ri k=s;k<t;k++)
			{
				if(f[s][k]==f[k+1][t])
					f[s][t]=max(f[s][t],f[s][k]+1);
			}
			Max=max(Max,f[s][t]);
		}
	}
	printf("%d\n",Max);
	return 0;
}


