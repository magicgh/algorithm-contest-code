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
struct flower{int s,c,m,cnt,ans;};
flower blo[100005];
int c[200005],ans[100005];
int n,k,m;
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
	for(int i=x;i<=k;i+=lowbit(i))c[i]+=val;
}
inline int query(int x)
{
	int ans=0; 
	for(int i=x;i>0;i-=lowbit(i))ans+=c[i];
	return ans;
}
inline bool cmps(const flower &a,const flower &b)
{
	return (a.s==b.s&&a.c==b.c&&a.m<b.m)||(a.s==b.s&&a.c<b.c)||(a.s<b.s);
}
inline bool cmpc(const flower &a,const flower &b)
{
	return (a.c==b.c&&a.m<b.m)||(a.c<b.c);
}
void CDQ(int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	CDQ(l,mid),CDQ(mid+1,r);
	sort(blo+l,blo+mid+1,cmpc);
	sort(blo+mid+1,blo+r+1,cmpc);
	int i=l,j=mid+1;
	while(j<=r)//双指针
	{
		while(i<=mid&&blo[i].c<=blo[j].c)
		{
			add(blo[i].m,blo[i].cnt);
			i++; 
		}
		blo[j].ans+=query(blo[j].m),j++;
	}
	for(ri p=l;p<i;p++)add(blo[p].m,-blo[p].cnt);//复原 
}
int main()
{
	n=getint(),k=getint();
	for(ri i=1;i<=n;i++)
	{
		int s=getint(),c=getint(),m=getint();
		blo[i]=(flower){s,c,m};
	}
	sort(blo+1,blo+n+1,cmps);
	for(ri i=1;i<=n;i++)
	{
		if(blo[i].s==blo[m].s&&blo[i].c==blo[m].c&&blo[i].m==blo[m].m)blo[m].cnt++;
		else blo[++m]=blo[i],blo[m].cnt++;
	}	
	CDQ(1,m);
	for(ri i=1;i<=m;i++)ans[blo[i].ans+blo[i].cnt-1]+=blo[i].cnt;
	for(ri i=0;i<n;i++)printf("%d\n",ans[i]);
	return 0;
}
