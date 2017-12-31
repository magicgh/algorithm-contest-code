#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<deque>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=300005;
const int INF=0x7fffffff/2;
struct node{int to,val;};
vector<node>a[5000005];
string Event,T0,T1;
char t0[MAXN],t1[MAXN];
int n,m,s,cnt;
int dist[5000005];
bool ext[5000005];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void AddEdge(int x,int y,int z){a[x].push_back((node){y,z});}
inline void SPFA(int v0)
{
	deque<int>q;
	for(ri i=1;i<=n+cnt+cnt;i++)dist[i]=INF,ext[i]=0;
	dist[v0]=0,q.push_back(v0),ext[v0]=1;
	while(!q.empty())
	{
		int now=q.front();q.pop_front();ext[now]=0;
		vector<node>::iterator it;
		for(it=a[now].begin();it!=a[now].end();++it)
		{
			if(dist[now]+it->val<dist[it->to])
			{
				dist[it->to]=dist[now]+it->val;
				if(!ext[it->to])
				{
					if(!q.empty()&&dist[it->to]<dist[q.front()])q.push_front(it->to);
					else q.push_back(it->to);
					ext[it->to]=1;
				}
			}
		}
	}
}
struct Trie
{
	int ch[30],bj;
	Trie()
	{
		bj=0;
		memset(ch,0,sizeof(ch));
	}
};
Trie tr[MAXN];
inline void Insert(string str,int id)//建立Trie树 
{
	int now=0,alpha=0;
	for(unsigned ri i=0;i<str.length();i++)
	{
		alpha=str[i]-'a';
		if(!tr[now].ch[alpha])
		{
			tr[now].ch[alpha]=++cnt;
			now=cnt;
		}
		else now=tr[now].ch[alpha];
	}
	tr[now].bj=id;
}
inline int Find(string str)
{
	int now=0,alpha=0;
	for(unsigned ri i=0;i<str.length();i++)
	{
		alpha=str[i]-'a';
		if(!tr[now].ch[alpha])return 0;
		else now=tr[now].ch[alpha];
	}
	return now;
}
inline void BuildGraph()
{
	for(ri i=1;i<=cnt;i++)
		for(ri j=0;j<26;j++)
		{
			if(tr[i].ch[j])
			{
				AddEdge(n+i,n+tr[i].ch[j],0); 
				AddEdge(n+cnt+tr[i].ch[j],n+cnt+i,0);//把单词串起来 
			}
			if(tr[i].bj)
			{
				AddEdge(n+i,tr[i].bj,0);
				AddEdge(tr[i].bj,n+cnt+i,0);//把单词结尾和标号串起来 
			}
		}
	for(ri i=1;i<=m;i++)
	{
		scanf("%s%s",t0,t1);
		int w=getint();
		T0=t0,T1=t1;
		reverse(T0.begin(),T0.end());
		reverse(T1.begin(),T1.end());
		int x=Find(T0),y=Find(T1);
		if(x&&y)AddEdge(n+cnt+x,n+y,w);//连后缀 
	}
}
int main()
{
	n=getint(),m=getint(),s=getint();
	for(ri i=1;i<=n;i++)
	{
		scanf("%s",t0);
		Event=t0;
		reverse(Event.begin(),Event.end());
		Insert(Event,i);
	}
	BuildGraph();
	SPFA(s);
	for(ri i=1;i<=n;i++)
	{
		if(dist[i]==INF)printf("Irrelevant\n");
		else printf("%d\n",dist[i]);
	}
	return 0;
}

