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
const int MAXN=2000005;
const int INF=0x7fffffff/2;
int n,N,cnt,a[MAXN],s[MAXN];
struct heap
{
	int id,val;
	bool operator <(const heap &rhs)
	const{return val>rhs.val;}
};
priority_queue<heap>q;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void ST1()
{
	for(ri i=1;i<=n;i++)
	{
		bool Flag=0;
		if(a[i]<0)continue;
		for(ri j=2;j<n;j++)
			if(s[i+j-1]-s[i-1]<0){Flag=1;break;}
		if(!Flag)cnt++;
	}
	printf("%d\n",cnt);
}
void ST2()
{
	for(ri i=2;i<=n+1;i++)q.push((heap){i,s[i]});
	s[0]=-INF;
	for(ri i=2;i<=n+1;i++)
	{
		int pos=0;
		while(!q.empty())
		{
			heap now=q.top();
			if(now.id>=i){pos=now.id;break;}
			q.pop();
		}
		if(s[pos]-s[i-1]>=0)cnt++;
		if(i<=n)q.push((heap){n+i,s[n+i]});
	}
	printf("%d\n",cnt);
}
int main()
{
	n=getint(),N=(n<<1);
	for(ri i=1;i<=n;i++)a[n+i]=a[i]=getint();
	for(ri i=1;i<=N;i++)s[i]=s[i-1]+a[i];
	if(s[n]<0){printf("0\n");return 0;}
	if(n<=1000)ST1();
	else ST2();
	return 0;
}


