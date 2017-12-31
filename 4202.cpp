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
struct flower{int s,c,m,ans;};
flower blo[40005];
int c[40005],b[40005];
int n,m,ans;
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
	for(int i=x;i<=n;i+=lowbit(i))c[i]=max(c[i],val);
}
inline void rollback(int x)
{
	for(int i=x;i<=n;i+=lowbit(i))c[i]=0;
}
inline int query(int x)
{
	int ans=0; 
	for(int i=x;i>0;i-=lowbit(i))ans=max(ans,c[i]);
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
	CDQ(l,mid);
	sort(blo+l,blo+mid+1,cmpc);
	sort(blo+mid+1,blo+r+1,cmpc);
	int i=l,j=mid+1;
	while(j<=r)//双指针
	{
		while(i<=mid&&blo[i].c<blo[j].c)//上升序列 
		{
			add(blo[i].m,blo[i].ans);
			i++; 
		}
		blo[j].ans=max(blo[j].ans,query(blo[j].m)+1),j++;//最长上升子序列(DP) 
	}        
	for(ri p=l;p<i;p++)rollback(blo[p].m);//清零 
	sort(blo+mid+1,blo+r+1,cmps);//滚回之前状态 
	CDQ(mid+1,r);
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		int s=getint(),c=getint(),m=getint();
		blo[i]=(flower){s,c,m};
		b[i]=blo[i].m;//提取第三维 
	}
	sort(blo+1,blo+n+1,cmps);
	sort(b+1,b+n+1);
	for(ri i=1;i<=n;i++)blo[i].m=lower_bound(b+1,b+n+1,blo[i].m)-b;//查找第三维的pos 
	CDQ(1,n);
	for(ri i=1;i<=n;i++)ans=max(ans,blo[i].ans);
	printf("%d",ans);
	return 0;
}