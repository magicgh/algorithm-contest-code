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
#define lowbit(x) x&(-x)
using namespace std;
const int MAXN=100005;
struct Tree{int l,r;};
struct Query{int id,l,r,Ans;};
Tree tr[MAXN<<2];
Query q[MAXN];
int n,m,cnt,now;
int Mid[MAXN],C[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const Query &a,const Query &b){return a.l<b.l;}
inline bool cmp_id(const Query &a,const Query &b){return a.id<b.id;}
inline void Build(int l,int r)
{
	tr[++cnt]=(Tree){l,r};
	if(l==r)return;
	int mid=Mid[++now];
	Build(l,mid);
	Build(mid+1,r);
}
inline void Add(int pos)
{
	for(ri i=pos;i<=n;i+=lowbit(i))C[i]++;
}
inline int Sum(int pos)
{
	int ret=0;
	for(ri i=pos;i>=1;i-=lowbit(i))ret+=C[i];
	return ret;
}
int main()
{
	//freopen("t.in","r",stdin);
	//freopen("t.out","w",stdout);
	n=GetInt(),m=GetInt();
	for(ri i=1;i<n;i++)Mid[i]=GetInt();
	Build(1,n);
	for(ri i=1;i<=m;i++)
	{
		int a=GetInt(),b=GetInt();
		q[i]=(Query){i,a,b,0};
	}
	sort(q+1,q+m+1,cmp);
	for(ri i=m,pos=cnt;i>=1;i--)
	{
		while(tr[pos].l>=q[i].l)
			Add(tr[pos].r),pos--;
		q[i].Ans=((q[i].r-q[i].l+1)<<1)-Sum(q[i].r);
	}
	sort(q+1,q+m+1,cmp_id);
	for(ri i=1;i<=m;i++)printf("%d\n",q[i].Ans);
	//fclose(stdin);
	//fclose(stdout);					
	return 0;
}
