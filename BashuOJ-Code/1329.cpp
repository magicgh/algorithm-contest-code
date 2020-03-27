#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct node
{
	int x,y;
};
int N,M=0;
int ans[100005],c[100005];
node a[100005];
inline bool cmp(node x,node y)
{
	return (x.x<y.x)||(x.x==y.x&&x.y<y.y);
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
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main(){
	N=GetInt();
	int x,y;
	for(int i=1;i<=N;i++)
	{
		x=GetInt()+1;
		y=GetInt()+1;
		a[i]=(node){x,y};
		M=max(y,M);
	}
	sort(a+1,a+N+1,cmp);
	for(int i=1;i<=N;i++)
	{
		ans[Sum(a[i].y)]++;
		Modify(a[i].y,1);
	}
	for(int i=0;i<N;i++)printf("%d\n",ans[i]);
	return 0;
}
