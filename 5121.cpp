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
int Lmax[MAXN],Rmax[MAXN],Lmin[MAXN],Rmin[MAXN],Cnt[MAXN],a[MAXN];
int n;
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll Calc(int l,int r,int mid)
{
	ll cnt=0;
	Lmax[mid]=Lmin[mid]=a[mid];
	Rmax[mid+1]=Rmin[mid+1]=a[mid+1];
	for(ri i=mid-1;i>=l;i--)
	{
		Lmax[i]=max(Lmax[i+1],a[i]);
		Lmin[i]=min(Lmin[i+1],a[i]);
	}
	for(ri i=mid+2;i<=r;i++)
	{
		Rmax[i]=max(Rmax[i-1],a[i]);
		Rmin[i]=min(Rmin[i-1],a[i]);
	}
	for(ri i=l;i<=mid;i++)//最值同在左侧的情况，直接计算右端点位置，统计合法方案数 
	{
		int j=i+Lmax[i]-Lmin[i];//右端点位置
		if(j>mid&&Rmax[j]<Lmax[i]&&Rmin[j]>Lmin[i])cnt++;//合法的情况，最值必须在左侧，且右端点过中线 
	}
	//最值异侧的合法区间满足 Rmax[j]-Lmin[i]=j-i,Rmax[j]-j=Lmin[i]-i
	//这里考虑最小值在左侧，最大值在右侧的情况 
	int p=mid+1,q=mid+1;
	while(q<=r&&Rmin[q]>Lmin[l])
		Cnt[Rmax[q]-q]++,q++;
	while(p<=r&&Rmax[p]<Lmax[l])
		Cnt[Rmax[p]-p]--,p++;
	p--,q--;
	for(int i=l;i<=mid;i++)
	{
		while(p>=mid+1&&Rmax[p]>Lmax[i])
			Cnt[Rmax[p]-p]++,p--;
		while(q>=mid+1&&Rmin[q]<Lmin[i])
			Cnt[Rmax[q]-q]--,q--;
		cnt+=max(Cnt[Lmin[i]-i],0) ;
	}
	for(int i=mid+1;i<=r;i++)Cnt[Rmax[i]-i]=0 ;
	return cnt;
}
inline ll Solve(int l,int r)
{
	if(l==r)return 1ll;
	int mid=(l+r)>>1;
	ll ret=Solve(l,mid)+Solve(mid+1,r); 
	ret+=Calc(l,r,mid);
	reverse(a+l,a+r+1);
	if ((r-l+1)&1)mid--;
    ret+=Calc(l,r,mid);
    reverse(a+l,a+r+1);
    return ret;
}
int main()
{
	n=GetInt();
	for(ri i=1;i<=n;i++)
	{
		int x=GetInt(),y=GetInt();
		a[x]=y;
	}
	printf("%lld\n",Solve(1,n));
	return 0;
}