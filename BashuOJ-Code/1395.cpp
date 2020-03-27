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
const int MAXN=500005;
const int INF=0x7fffffff;
int n,t,m,K,D,rt;//K维度,D当前层维度(用于排序)
inline int max(const int &x,const int &y){return x>y?x:y;}
inline int min(const int &x,const int &y){return x<y?x:y;}
inline int sqr(const int &x){return x*x;}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{ 
		if(c==EOF)return EOF;
		bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	} 
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct heap
{
	int pos,dist;
	bool operator <(const heap &rhs)
		const{return dist<rhs.dist;};	
};
priority_queue<heap>q;
struct Point
{
	int dim[5],Max[5],Min[5],ch[2];
	int& operator[] (int x){return dim[x];}//二维数组返回维度 
	bool operator <(const Point &rhs)
		const{return dim[D]<rhs.dim[D];}
};
Point point,ans[15];
inline int getdist(const Point &a,const Point &b)
{
	int ans=0;
	for(ri i=0;i<K;i++)ans+=sqr(a.dim[i]-b.dim[i]);
	return ans;
}
struct K_D
{
	Point p[MAXN];
	inline void clean(){memset(p,0,sizeof(p));}
	inline void maintain(int &u)
	{
		int l=p[u].ch[0],r=p[u].ch[1];
		for(ri i=0;i<K;i++)
		{
			if(l)p[u].Max[i]=max(p[u].Max[i],p[l].Max[i]),p[u].Min[i]=min(p[u].Min[i],p[l].Min[i]);
			if(r)p[u].Max[i]=max(p[u].Max[i],p[r].Max[i]),p[u].Min[i]=min(p[u].Min[i],p[r].Min[i]);
		}
	}
	inline void build(int &u,int l,int r,int d)
	{
		int mid=(l+r)>>1;u=mid,D=d;Point &now=p[u];
		nth_element(p+l,p+mid,p+r+1);//有序化
		for(ri i=0;i<K;i++)p[u].Max[i]=now.Min[i]=now.dim[i];//初始化Max,Min
		if(l<mid)build(now.ch[0],l,mid-1,(d+1)%K);
		if(mid<r)build(now.ch[1],mid+1,r,(d+1)%K);
		maintain(u);
	}
	inline int estimate(int &u)
	{
		if(!u)return 0;
		int ans=0;
		for(ri i=0;i<K;i++)
		{
			if(point[i]<p[u].Min[i])ans+=sqr(point[i]-p[u].Min[i]);//左边界的左边 
			if(point[i]>p[u].Max[i])ans+=sqr(point[i]-p[u].Max[i]);//右边界的右边 
		}
		return ans;
	}
	inline void query(int u)
	{
		if(!u)return;
		int dist=getdist(p[u],point);
		if(dist<q.top().dist)q.pop(),q.push((heap){u,dist});//令top为最小值 
		int estl=estimate(p[u].ch[0]),estr=estimate(p[u].ch[1]);//左右估界 
		if(estl<estr) 
		{
			if(estl<q.top().dist)query(p[u].ch[0]);
			if(estr<q.top().dist)query(p[u].ch[1]);
		}
		else
		{
			if(estr<q.top().dist)query(p[u].ch[1]);
			if(estl<q.top().dist)query(p[u].ch[0]);
		}
	}
};
K_D tr;
int main()
{
	while(~(n=getint()))
	{
		K=getint();tr.clean();
		for(ri i=1;i<=n;i++)
			for(ri j=0;j<K;j++)tr.p[i][j]=getint();																																						
		tr.build(rt,1,n,0);//构造K-D树
		t=getint();
		for(ri i=1;i<=t;i++)
		{
			for(ri j=0;j<K;j++)point[j]=getint();
			m=getint();while(!q.empty())q.pop();
			for(ri j=1;j<=m;j++)q.push((heap){n+1,INF});//初始化队列,保证只有m个元素,求第m大 
			tr.query(rt);
			printf("the closest %d points are:\n",m);
			for(ri j=1;j<=m;j++)
			{
				int pos=q.top().pos;q.pop();
				for(ri k=0;k<K;k++)ans[j][k]=tr.p[pos][k];
			}
			for(ri j=m;j>=1;j--)
			{
				for(ri k=0;k<K-1;k++)		
					printf("%d ",ans[j][k]);
				printf("%d\n",ans[j][K-1]);
			}
		}
	}	
	return 0;
}