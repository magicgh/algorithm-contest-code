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
int T;
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
	T=getint();
	while(T--)
	{
		int n=getint(),Ans=0,cnt=0;
		for(ri i=1;i<=n;i++)
		{
			int x=getint();
			if(x>1)cnt++;
			Ans^=x;
		}
		if((Ans&&cnt)||(!Ans&&!cnt))printf("Cio\n");
		else printf("Nod\n");
	}
	return 0;
}


