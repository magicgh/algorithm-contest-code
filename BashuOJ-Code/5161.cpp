#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#define ri register int
#define ll long long
#define pii pair<int,int>
#define mp make_pair
using namespace std;
const int MAXN=100005;
struct stu{int h,id,Ans;};
stu a[MAXN];
int n,m,h[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const stu &a,const stu &b){return a.h<b.h;}
inline bool cmp_id(const stu &a,const stu &b){return a.id<b.id;}
int main()
{
	n=GetInt(),m=GetInt();
	for(ri i=1;i<=n;i++)
	{
		int height=GetInt();
		a[i]=(stu){height,i,0};
	}
	for(ri i=1;i<=m;i++)h[i]=GetInt();
	sort(a+1,a+n+1,cmp);
	sort(h+1,h+m+1);
	for(ri i=1,j=0,last=0;i<=n;i++)
	{
		while(j<m&&a[i].h>=h[j+1])j++;
		a[i].Ans=j-last;
		last=j;
	}
	sort(a+1,a+n+1,cmp_id);
	for(ri i=1;i<=n;i++)printf("%d\n",a[i].Ans);
	return 0;
}
