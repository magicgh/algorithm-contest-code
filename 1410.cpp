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
const int MAXN=500005;
struct node{int id;ll val;};
struct heap
{
	int id;ll val;
	bool operator <(const heap &rhs)
	const {return val>rhs.val;}
};
int n,used,cnt,tot,Max;
node List[MAXN];
priority_queue<heap>q;
int Ans[55];
bool Hash[MAXN];
namespace FastIO
{
    const ll L=1<<15;
    char buffer[L],*S,*T;
    inline char getchar()
	{
        if(S==T){T=(S=buffer)+fread(buffer,1,L,stdin);if(S==T)return EOF;}
		return *S++;
    }
    inline const int getint()
	{
		ri num=0,bj=1;
		register char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
	inline const ll getll()
	{
		ll num=0,bj=1;
		char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
};
using namespace FastIO;
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		ll x=getll();
		List[i]=(node){i,x};
	}
	for(ri i=2;i<n;i++)
	{
		if(List[i+1].val%List[i].val==0||List[i-1].val%List[i].val==0)
			q.push((heap){List[i].id,List[i].val});
	}
	while(!q.empty())
	{
		heap now=q.top();q.pop();
		if(Hash[now.id])continue;
		Hash[now.id]=1;
		int L=now.id-1,R=now.id+1;
		used++;
		while(L>=1&&List[L].val%now.val==0)Hash[L--]=1,used++;
		while(R<=n&&List[R].val%now.val==0)Hash[R++]=1,used++;
		L++,R--;
		if(R-L>Max)
			Max=R-L,Ans[cnt=1]=L;
		else if(R-L==Max)
			Ans[++cnt]=L;
		if(used>=n)break;
	}
	cnt=unique(Ans+1,Ans+cnt+1)-(Ans+1);
	printf("%d %d\n",cnt,Max);
	sort(Ans+1,Ans+cnt+1);
	for(ri i=1;i<=cnt;i++)
		printf("%d ",Ans[i]);
	return 0;
}