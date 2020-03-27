#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<climits>
const int INF=INT_MAX/2;
using namespace std;
int N,T,a[50005],f[50005],Min=INF,ans=INF;
struct Queue
{
	int head,tail,q[50005];
	Queue(){head=1,tail=0;q[0]=0;return;}
	inline void push(int x)
	{
		while(head<=tail&&f[q[tail]]>=f[x])tail--;
		q[++tail]=x;
		return;
	}
	inline void pop(){head++;}
	inline bool empty(){return head>tail||head<0||tail<0?1:0;}
	inline int top(){return q[head];}
};
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool DP(int x)
{
	Queue q;
	ans=INF;
	for(int i=1;i<=N;i++)f[i]=INF;
	for(int i=1;i<=N;i++)
	{
		if(f[i-1]<INF)q.push(i-1);
		if(!q.empty()&&i-1-q.top()>x)q.pop();
		 if(!q.empty())f[i]=min(f[i],f[q.top()]+a[i]);
	}
	for(int i=N-x;i<=N;i++)ans=min(ans,f[i]);
	return ans>T?0:1;
}
int Bisection()
{
	int l=0,r=N;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(DP(mid))r=mid-1,Min=min(mid,Min);
		else l=mid+1;
	}
	return Min;
}
int main(){
	N=GetInt();
	T=GetInt();
	for(int i=1;i<=N;i++)a[i]=GetInt();
	printf("%d",Bisection());
	return 0;
}
