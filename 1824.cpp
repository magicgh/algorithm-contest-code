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
int n,Ans,Cnt[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int Div(int x)
{
	for(ri i=1;i<sqrt(x);i++)
		if(x%i==0)Cnt[i]++,Cnt[x/i]++;
	if((int)(sqrt(x))*(int)(sqrt(x))==x)Cnt[(int)sqrt(x)]++;
}
int main()
{
	n=getint();
	while(n--)
	{
		int op=getint(),x=getint();
		if(op==1)Div(x);
		if(op==2)Ans^=Cnt[x];
	}
	printf("%d\n",Ans);
	return 0;
}

