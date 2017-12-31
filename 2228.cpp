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
const int MAXN=150005;
struct node{int t1,t2;};
node a[MAXN];
int n,T,cnt;
priority_queue<int>q; 
inline bool cmp(const node &a,const node &b){return a.t2<b.t2;}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		int t1=getint(),t2=getint();
		a[i]=(node){t1,t2};
	}
	sort(a+1,a+n+1,cmp);
	for(ri i=1;i<=n;i++)
	{
		if(T+a[i].t1<=a[i].t2)
		{
			T+=a[i].t1,cnt++;
			q.push(a[i].t1);
		}
		else
		{
			if(!q.empty())
			{
				int x=q.top();
				if(a[i].t1<x&&a[i].t1+T-x<=a[i].t2)
				{
					q.pop();
					T=T-x+a[i].t1;
					q.push(a[i].t1);
				}	
			}
		}
	}
	printf("%d",cnt);
	return 0;
}

