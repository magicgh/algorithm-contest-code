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
#define ll long long
using namespace std;
const int MAXN=200005;
struct sLtree{int l,r,val,dist;};
sLtree tr[MAXN*50];
int m,n,cnt,root[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int newnode(int val)
{
	tr[++cnt]=(sLtree){0,0,val,0};
	return cnt;
}
inline int Merge(int a,int b)
{
	if(a*b==0)return a+b;
	if(tr[a].val<tr[b].val)swap(a,b);//大根堆
	int New=++cnt;tr[New]=tr[a];//新建版本
	tr[New].r=Merge(tr[New].r,b);//合并 
	if(tr[tr[New].l].dist<tr[tr[New].r].dist)swap(tr[New].l,tr[New].r);//维护左偏性质 
	if(!tr[New].r)tr[tr[New].r].dist=0;
	else tr[New].dist=tr[tr[New].r].dist+1;//维护距离 
	return New;
}
int main()
{
	m=getint();
	for(ri i=1;i<=m;i++)
	{
		int k=getint();
		if(k==1)
		{
			int x=getint();
			root[++n]=newnode(x);
		}
		if(k==2)
		{
			int x=getint()%n+1,y=getint()%n+1;
			root[++n]=Merge(root[x],root[y]);
		}
		if(k==3)
		{
			int x=getint()%n+1;
			printf("%d\n",tr[root[x]].val);
		} 
	}
	return 0;
}

