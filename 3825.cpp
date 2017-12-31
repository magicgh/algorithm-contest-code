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
const int MAXN=100005;
const int Mod=99999997;	
struct node{int x,y;};
node a[MAXN],b[MAXN];
int n,Ans,c[MAXN],C[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int lowbit(int x){return x&(-x);}
inline void Add(int pos,int val)
{
    for(int i=pos;i<=n;i+=lowbit(i))C[i]+=val;
}
inline int Query(int pos)
{
    int Ans=0;
    for(ri i=pos;i>0;i-=lowbit(i))Ans+=C[i];
    return Ans;
}
inline bool cmp(const node &a,const node &b){return a.x<b.x;}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)a[i]=(node){getint(),i};
	for(ri i=1;i<=n;i++)b[i]=(node){getint(),i};
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	for(ri i=1;i<=n;i++)c[a[i].y]=b[i].y;
	for(ri i=1;i<=n;i++)
	{
		Add(c[i],1);
		Ans=(Ans+i-Query(c[i])+Mod)%Mod;
	}
	printf("%d\n",Ans);
	return 0;
}


