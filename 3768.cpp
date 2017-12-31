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
const int MAXP=500005;
const int MAXN=100005;
struct heap
{
	int id,t;
	bool operator <(const heap &rhs)
	const {return t<rhs.t;}
};
priority_queue<heap>q;
int n,k,p,cnt,Ans;	
int a[MAXP],Next[MAXP],Last[MAXN];
bool ext[MAXN];
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
	n=getint(),k=getint(),p=getint();
	for(ri i=1;i<=p;i++)a[i]=getint();
	for(ri i=1;i<=n;i++)Last[i]=p+1;
	for(ri i=p;i>=1;i--)
	{
		Next[i]=Last[a[i]];
		Last[a[i]]=i;
	}
	for(ri i=1;i<=p;i++)
	{
		if(ext[a[i]])
		{
			q.push((heap){a[i],Next[i]});
			continue;
		}
		if(cnt==k)
		{
			ext[q.top().id]=0;
			q.pop(),cnt--;
		}
		cnt++,Ans++;
		ext[a[i]]=1;
		q.push((heap){a[i],Next[i]});
	}
	printf("%d",Ans);
	return 0;
}

