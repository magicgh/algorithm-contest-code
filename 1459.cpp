#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct node
{
	int s,e,pos;
};
node a[100005];
int N,M=0;
int ans[100005],c[100005];
inline bool cmp(node x,node y)
{
	return (x.e>y.e)||(x.e==y.e&&x.s<y.s);
}
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int Lowbit(int x){return x&(-x);}
inline void Modify(int x,int d)
{
	for(int i=x;i<=M;i+=Lowbit(i))c[i]+=d;
}
inline int Sum(int x)
{
	int Ans=0;
	for(int i=x;i>0;i-=Lowbit(i))Ans+=c[i];
	return Ans;
}
int main(){
	while(scanf("%d",&N),N!=0)
	{
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		memset(ans,0,sizeof(ans));
		M=0;
		int s,e;
		for(int i=1;i<=N;i++)
		{
			s=GetInt()+1;
			e=GetInt()+1;
			a[i]=(node){s,e,i};
			M=max(M,a[i].s);
		}
		sort(a+1,a+N+1,cmp);
		Modify(a[1].s,1);
		for(int i=2;i<=N;i++)
		{
			if(a[i].s==a[i-1].s&&a[i].e==a[i-1].e)ans[a[i].pos]=ans[a[i-1].pos];
			else ans[a[i].pos]=Sum(a[i].s);
			Modify(a[i].s,1);
		}
		for(int i=1;i<N;i++)printf("%d ",ans[i]);
		printf("%d\n",ans[N]);
	}	
	return 0;
}
