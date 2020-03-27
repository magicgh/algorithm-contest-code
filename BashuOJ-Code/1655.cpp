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
using namespace std;
const int INF=0x7fffffff;
struct Meteorite{int l,r,a;}g[300005];
vector<int>Orbit[300005];
bool full[300005];
int n,m,k,P[300005],List[300005],ans[300005],tmp[300005],tcnt;
long long c[300005];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int lowbit(const int &x){return x&(-x);}
inline void add(int x,int val)
{
	for(int i=x;i<=m;i+=lowbit(i))c[i]+=val;
}
inline long long query(int x)
{
	long long ans=0;
	for(int i=x;i>0;i-=lowbit(i))ans+=c[i];
	return ans;
}
inline void addarea(int x,int val)
{
	if(g[x].l<=g[x].r)add(g[x].l,val*g[x].a),add(g[x].r+1,-val*g[x].a);
	else add(1,val*g[x].a),add(g[x].r+1,-val*g[x].a),add(g[x].l,val*g[x].a);
}
void CDQ(int l,int r,int al,int ar)
{
	if(l>r)return;
	if(al==ar)
	{
		for(ri i=l;i<=r;i++)ans[List[i]]=al;
		return;
	}
	int mid=(al+ar)>>1;
	while(tcnt<=mid)tcnt++,addarea(tcnt,1);
	while(tcnt>mid)addarea(tcnt,-1),tcnt--;
	int cnt=0;
	for(ri i=l;i<=r;i++)
	{
		int now=List[i];long long total=0;
		vector<int>::iterator it;
		for(it=Orbit[now].begin();it!=Orbit[now].end();++it)
		{
			total+=query(*it);
			if(total>=P[now]){full[now]=1,cnt++;break;}
		}
		if(total<P[now])full[now]=0;
	}
	int s=l,t=l+cnt;
	for(ri i=l;i<=r;i++)
		if(full[List[i]])tmp[s++]=List[i];
		else tmp[t++]=List[i];
	for(ri i=l;i<=r;i++)List[i]=tmp[i];
	CDQ(l,s-1,al,mid);
	CDQ(s,t-1,mid+1,ar);
}
int main()
{
	n=getint(),m=getint();
	for(int i=1;i<=m;i++)
	{
		int x=getint();
		Orbit[x].push_back(i);
	}
	for(ri i=1;i<=n;i++)P[i]=getint();
	k=getint()+1;
	for(ri i=1;i<k;i++)
	{
		int l=getint(),r=getint(),a=getint();
		g[i]=(Meteorite){l,r,a};
	}
	g[k]=(Meteorite){1,m,INF};
	for(ri i=1;i<=n;i++)List[i]=i;
	CDQ(1,n,1,k);
	for(ri i=1;i<=n;i++)
		if(ans[i]<k)printf("%d\n",ans[i]);
		else printf("NIE\n");
	return 0;
}