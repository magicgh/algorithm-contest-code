#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<map>
#define ll long long
#define ri register int
const int MAXN=50005;
const int INF=0x7fffffff/2;
using namespace std;
struct node
{
	int nat,pos;
	bool operator <(const node &rhs)
	const {return pos<rhs.pos;}
};
node a[MAXN];
int n,npos,Ans;
map<int,int>P;
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
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		int nat=getint(),pos=getint();
		a[i]=(node){nat,pos};
	}
	sort(a+1,a+n+1);
	for(ri i=1;i<=n;i++)
	{
		npos+=(a[i].nat)?1:-1;
		if(!P.count(npos))P[npos]=a[i+1].pos;
		else if(P.count(npos))Ans=max(Ans,a[i].pos-P[npos]);
	}
	printf("%d\n",Ans);
	return 0;
}

