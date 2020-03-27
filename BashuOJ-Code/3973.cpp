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
const int MAXN=2005;
int n,SG[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void GetSG(int x)
{
	if(SG[x]!=-1)return;
	bool used[MAXN];
	memset(used,0,sizeof(used));
	for(ri i=1;i<=x;i++)
	{
		GetSG(i-3),GetSG(x-i-2);
		used[SG[i-3]^SG[x-i-2]]=1;
	}
	for(ri i=0;;i++)
		if(!used[i]){SG[x]=i;break;}
}
int main()
{
	n=getint();
	memset(SG,-1,sizeof(SG));
	GetSG(n);
	printf("%d\n",SG[n]?1:2);
	return 0;
}


