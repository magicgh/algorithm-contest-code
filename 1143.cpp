#include<iostream>
#include<cstdio>
#define ri register int
using namespace std;
int a[55],b[55];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int n,int s,int h)
{
	for(ri i=s;i<=(n>>1);i++)
	{
		a[h]=i;
		b[h]=n-i;
		DFS(b[h],i,h+1);
		for(ri j=1;j<=h;j++)printf("%d+",a[j]);
		printf("%d\n",b[h]);
	}
}
int main()
{
	int n;
	n=getint();
	DFS(n,1,1);
	return 0;
}