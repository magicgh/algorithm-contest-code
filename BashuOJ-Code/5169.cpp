#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=10000005;
const int MAXP=670000;
const int Limit=10000000;
int p[MAXP],s[MAXN];
bool vst[MAXN],Correct[MAXN];
int L,R,Q;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Init()
{
	for(int i=2;i<=Limit;i++)
	{
		if(!vst[i])p[++p[0]]=i;
		for(ri j=1;i*p[j]<=Limit&&j<=p[0];j++)
		{
			vst[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
	for(ri i=1;i<=p[0];i++)
	{
		Correct[p[i]]=1;
		if((ll)p[i]*(ll)p[i]<=(ll)Limit)Correct[p[i]*p[i]]=1;
	}
	for(ri i=1;i<p[0];i++)
		for(ri j=i+1;j<=p[0];j++)
		{
			if((ll)p[i]*(ll)p[j]>(ll)Limit)break;
			Correct[p[i]*p[j]]=1;
		}
	for(ri i=1;i<=Limit;i++)
		s[i]=s[i-1]+Correct[i];
}
int main()
{
	Init();
	Q=GetInt();
	for(ri i=1;i<=Q;i++)
	{
		L=GetInt(),R=GetInt();
		printf("%d\n",s[R]-s[L-1]);
	}
	return 0;
}