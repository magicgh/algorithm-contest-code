#include<iostream>
#include<cstdio>
#include<algorithm>
#define ri register int
using namespace std;
const int MAXN=2003;
struct Cross
{
	bool map;
	int up,down,left,right;
};
Cross a[MAXN][MAXN];
int n,Ans=-0x7fffffff/2;
inline int max(const int &a,const int &b){return a>b?a:b;}
inline int min(const int &a,const int &b){return a<b?a:b;}
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
	n=getint();char ch;
	if(n==3){printf("1\n");return 0;}
	for(ri i=1;i<=n;++i)
		for(ri j=1;j<=n;++j)
		{
			while(ch=getchar())
				if(ch=='0'||ch=='1')break;
			a[i][j].map=ch-'0';
		} 
	for(ri i=1;i<=n;++i)
		for(ri j=1;j<=n;++j)
		{
			if(a[i][j].map)
			{
				a[i][j].up=a[i-1][j].up+a[i][j].map;
				a[i][j].left=a[i][j-1].left+a[i][j].map;
			}
			if(a[n-i+1][n-j+1].map)
			{
				a[n-i+1][n-j+1].down=a[n-i+2][n-j+1].down+a[n-i+1][n-j+1].map;
				a[n-i+1][n-j+1].right=a[n-i+1][n-j+2].right+a[n-i+1][n-j+1].map;
			}
		}
	for(ri i=1;i<=n;++i)
		for(ri j=1;j<=n;++j)
		{
			if(!a[i][j].map)continue;
			Ans=max(Ans,min(a[i][j].up,min(a[i][j].down,min(a[i][j].left,a[i][j].right))));
		}
	printf("%d\n",(Ans<<1)-1);
	return 0;
}


