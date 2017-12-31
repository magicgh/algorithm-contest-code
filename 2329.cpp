#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
int l1,l2,l3,c1,c2,c3,n,s,t;
int dist[105],f[105];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int Judge(int x,int y)
{
	int d=abs(dist[x]-dist[y]);
	if(d<=l1)return c1;
	if(d<=l2)return c2;
	if(d<=l3)return c3;
}
int main()
{
	l1=getint(),l2=getint(),l3=getint();
	c1=getint(),c2=getint(),c3=getint(),n=getint();
	s=getint(),t=getint();
	if(s>t)swap(s,t);
	memset(f,0x3f,sizeof(f));
	f[s]=0;
	for(ri i=2;i<=n;i++)dist[i]=getint();
	for(ri i=s+1;i<t+1;i++)    
        for(ri j=s;j<i;j++)if(dist[i]-dist[j]<=l3)f[i]=min(f[i],f[j]+Judge(i,j));
	printf("%d",f[t]);
	return 0;
}

