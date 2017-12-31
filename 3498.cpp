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
const int INF=0x7fffffff/2;
int n,m;
int pos[5005],w[100005],f[5005];
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
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)pos[i]=getint();
	sort(pos+1,pos+n+1);
	for(ri i=1;i<=m;i++)w[i]=getint();
	for(ri i=m-1;i>=1;i--)w[i]=min(w[i],w[i+1]);//长度更长的伞更便宜
	for(ri i=1;i<=n;i++)f[i]=INF;
	for(ri i=1;i<=n;i++)
		for(ri j=0;j<i;j++)
			f[i]=min(f[i],f[j]+w[pos[i]-pos[j+1]+1]);
	printf("%d\n",f[n]);
	return 0;
}


