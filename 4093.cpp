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
const int MAXN=50005;
struct node{int x,y,z,val,c;};
node a[100005];
int n,m,need,tmp,Ans;
int prt[MAXN];
inline bool cmp(const node &a,const node &b){return (a.val==b.val&&a.c<b.c)||(a.val<b.val);}
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	return prt[u]=getfa(prt[u]);
}
inline bool Kruskal(int delta)
{
	int tot=0,white=0;tmp=0;
	for(ri i=1;i<=m;i++)
	{
		if(!a[i].c)a[i].val=a[i].z+delta;
		else a[i].val=a[i].z;
	}
	sort(a+1,a+m+1,cmp);
	for(ri i=1;i<=n;i++)prt[i]=i;
	for(ri i=1;i<=m;i++)
	{
		int f1=getfa(a[i].x),f2=getfa(a[i].y);
		if(f1!=f2)
		{
			prt[f1]=f2;
			tmp+=a[i].val;
			if(!a[i].c)white++;
			if(++tot>=n-1)break;
		}
	}
	return white>=need;//合法情况 
}
void Binary()//通过二分控制白边的边权来控制白边数量 
{
	int l=-101,r=101;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(Kruskal(mid))l=mid+1,Ans=tmp-need*mid;
		else r=mid-1;
	}
}
int main()
{
	n=getint(),m=getint(),need=getint();
	for(ri i=1;i<=m;i++)
	{
		int s=getint()+1,t=getint()+1,c=getint(),col=getint();
		a[i]=(node){s,t,c,0,col};
	}
	Binary();
	printf("%d\n",Ans);
	return 0;
}


