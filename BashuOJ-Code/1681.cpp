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
const int MAXN=605*605;
int n,m,len,ans=0x7fffffff;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct DLX
{
	int u[MAXN],d[MAXN],l[MAXN],r[MAXN],col[MAXN],h[MAXN],cnt[MAXN];
	void init()
	{
		for(ri i=0;i<=m;i++)
		{
			u[i]=d[i]=i;
			l[i]=i-1,r[i]=i+1;
		}
		l[0]=m,r[m]=0;len=m;
	}
	void link(int x,int y)
	{
		
		cnt[y]++,col[++len]=y;
		u[len]=u[y],d[len]=y;
		u[d[len]]=d[u[len]]=len;
		if(!h[x])h[x]=l[len]=r[len]=len;
		else l[len]=l[h[x]],r[len]=h[x],l[r[len]]=r[l[len]]=len;
		 
	}
	void del(int c)//列号
	{
		l[r[c]]=l[c],r[l[c]]=r[c];
		for(ri i=d[c];i!=c;i=d[i])//十字链表向下删
		{
			for(ri j=r[i];j!=i;j=r[j])//从左往右 
			{
				cnt[col[j]]--;
				u[d[j]]=u[j],d[u[j]]=d[j];
			}
		} 
	}
	void rollback(int c)
	{
		l[r[c]]=c,r[l[c]]=c;
		for(ri i=u[c];i!=c;i=u[i])
		{
			for(ri j=l[i];j!=i;j=l[j])
			{
				cnt[col[j]]++;
				u[d[j]]=j,d[u[j]]=j;
			}
		}
	}
	void dance(int val)
	{
		if(!r[0]){ans=min(ans,val);return;}//每行删完求最优 
		int t=r[0];
		for(ri i=r[0];i!=0;i=r[i])if(r[i]<r[t])t=i;//找元素最少的行
		del(t);
		for(ri i=d[t];i!=t;i=d[i])
		{
			for(ri j=r[i];j!=i;j=r[j])del(col[j]);
			dance(val+1);
			for(ri j=l[i];j!=i;j=l[j])rollback(col[j]);
		}
		rollback(t);
	}
};
DLX F;
int main()
{
	n=getint(),m=getint();
	F.init();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
		{
			int x=getint();
			if(x)F.link(i,j);
		}
	F.dance(0);
	printf("%d",ans==0x7fffffff?-1:ans);
	return 0;
}
