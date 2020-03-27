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
using namespace std;
int n,scale[105][5],prt[105];
inline int gcd(const int &a,const int &b){return !b?a:gcd(b,a%b);}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int DFS(int x)
{
	if(x==0)return 1;
	int l=DFS(scale[x][3]),r=DFS(scale[x][4]);
	int base=gcd(l*scale[x][1],r*scale[x][2]);
	return l*scale[x][1]/base*r+r*scale[x][2]/base*l;
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		scale[i][1]=getint(),scale[i][2]=getint(),scale[i][3]=getint(),scale[i][4]=getint();
		prt[scale[i][3]]=i,prt[scale[i][4]]=i;
	}
	int root=1;
	while(prt[root])root=prt[root];
	printf("%d",DFS(root));
	return 0;
}
