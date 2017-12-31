#include<iostream>
#include<cmath>
using namespace std;
const int MAXN=1000005;
long long ans;
int n,now,l[MAXN],r[MAXN],q[MAXN],totsize[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
struct Ltree
{
	int cnt,v[MAXN],ch[MAXN][2],dist[MAXN],size[MAXN];
	inline int newnode(int x)
	{
		v[++cnt]=x;
		size[cnt]=1;
		ch[cnt][0]=ch[cnt][1]=dist[cnt]=0;
		return cnt;
	}
	inline int merge(int x,int y)
	{
		if(x*y==0)return x+y;
		if(v[x]<v[y])swap(x,y);
		ch[x][1]=merge(ch[x][1],y);
		size[x]=size[ch[x][0]]+size[ch[x][1]]+1;
		if(dist[ch[x][1]]>dist[ch[x][0]])swap(ch[x][0],ch[x][1]);
		dist[x]=dist[ch[x][1]]+1;
		return x;
	}
	inline void del(int &x){x=merge(ch[x][0],ch[x][1]);}
};
Ltree tr;
int main()
{
	n=getint();
	for(int i=1;i<=n;i++)
	{
		q[++now]=tr.newnode(getint());
		l[now]=r[now]=i,totsize[now]=1;
		while(now>1&&tr.v[q[now]]<tr.v[q[now-1]])
		{
			now--;
			q[now]=tr.merge(q[now],q[now+1]);
			totsize[now]+=totsize[now+1];r[now]=r[now+1];
			while(totsize[now]+1<tr.size[q[now]]*2)tr.del(q[now]);
		}
	}
	for(int i=1;i<=now;i++)
		for(int j=l[i];j<=r[i];j++)ans+=abs(tr.v[j]-tr.v[q[i]]);
	printf("%lld",ans);
	return 0;
}