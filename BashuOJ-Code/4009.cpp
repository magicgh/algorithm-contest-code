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
int q[1000005],n,l=1,r=0;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	char ch; 
	n=getint();
	while(n--)
	{
		while(ch=getchar())if(ch=='n'||ch=='q'||ch=='l')break;
		if(ch=='n')q[++r]=getint();
		if(ch=='l')l++;
		if(ch=='q')
		{
			int Max=-0x7fffffff;
			for(ri i=l;i<=r;i++)Max=max(Max,q[i]);
			printf("%d\n",Max);
		}
	}	
	return 0;
}
