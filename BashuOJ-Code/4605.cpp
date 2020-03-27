#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
const int MAXN=100005;
priority_queue<long long,vector<long long>,greater<long long> >q;
int n,k,D,point[2];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct K_DTree
{
	int p[2],Max[2],Min[2],ch[2];
};
K_DTree tr[MAXN];
inline int max(const int &x,const int &y){return x>y?x:y;}
inline int min(const int &x,const int &y){return x<y?x:y;}
inline bool cmp(const K_DTree &x,const K_DTree &y){return x.p[D]<y.p[D];}
inline long long sqr(const int &x){return (long long)x*x;}
inline void maintain(int u)
{
	int l=tr[u].ch[0],r=tr[u].ch[1];
	for(ri i=0;i<=1;i++)
	{
		if(l)tr[u].Max[i]=max(tr[u].Max[i],tr[l].Max[i]),tr[u].Min[i]=min(tr[u].Min[i],tr[l].Min[i]);
		if(r)tr[u].Max[i]=max(tr[u].Max[i],tr[r].Max[i]),tr[u].Min[i]=min(tr[u].Min[i],tr[r].Min[i]);
	}
}
inline void build(int& u,int l,int r,int d)
{
	int mid=(l+r)>>1;D=d,u=mid;
	nth_element(tr+l,tr+mid,tr+r+1,cmp);//在[l,r+1]中寻找(mid)th个元素
	for(ri i=0;i<=1;i++)tr[u].Max[i]=tr[u].Min[i]=tr[u].p[i];
	if(l<mid)build(tr[u].ch[0],l,mid-1,d^1);//取儿子的地址
	if(mid<r)build(tr[u].ch[1],mid+1,r,d^1);
	maintain(u);
}
inline long long estimate(int u)
{
	return u?max(sqr(tr[u].Min[0]-point[0]),sqr(tr[u].Max[0]-point[0]))+
		   max(sqr(tr[u].Min[1]-point[1]),sqr(tr[u].Max[1]-point[1])):0;
}
inline void query(int u)
{
	long long dist=sqr(tr[u].p[0]-point[0])+sqr(tr[u].p[1]-point[1]); 
	if(dist>q.top())q.pop(),q.push(dist);
	long long Estl=estimate(tr[u].ch[0]),Estr=estimate(tr[u].ch[1]);
	if(Estl>Estr)
	{
		if(Estl>q.top())query(tr[u].ch[0]);
		if(Estr>q.top())query(tr[u].ch[1]);
	}
	else
	{
		if(Estr>q.top())query(tr[u].ch[1]);
		if(Estl>q.top())query(tr[u].ch[0]);
	}
}
int main()
{
	int rt;
	n=getint(),k=getint();
	for(ri i=1;i<=n;i++)tr[i].p[0]=getint(),tr[i].p[1]=getint();
	build(rt,1,n,0);
	for(ri i=1;i<=2*k;i++)q.push(0);
	for(ri i=1;i<=n;i++)point[0]=tr[i].p[0],point[1]=tr[i].p[1],query(rt);
	printf("%lld\n",q.top());
	return 0;
}
