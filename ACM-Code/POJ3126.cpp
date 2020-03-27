#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<vector>
#define DEBUG
#define ri register int
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int INF=0x7fffffff;
int T,p[1200],id[10005],cnt,dist[1200];
bool vst[10005],ext[1200];
vector<int>G[1200];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void SPFA(int v0)
{
	deque<int>q;
	for(ri i=1;i<=1200;i++)dist[i]=INF,ext[i]=0;
	dist[v0]=0,ext[v0]=1;q.push_back(v0);
	while(!q.empty())
	{
		int Now=q.front();q.pop_front();
		ext[Now]=0;
		vector<int>::iterator Next;
		for(Next=G[Now].begin();Next!=G[Now].end();++Next)
		{
			if(dist[*Next]>dist[Now]+1)
			{
				dist[*Next]=dist[Now]+1;
				if(!ext[*Next])
				{
					if(!q.empty()&&dist[q.front()]>dist[*Next])q.push_front(*Next);
					else q.push_back(*Next);
					ext[*Next]=0;
				}
			}
		}

	}
}
int tmp[15];
inline void Produce(int x)
{
	int t=x;tmp[0]=0;
	while(t)
	{
		tmp[++tmp[0]]=t%10;
		t/=10;
	}
	for(ri i=0;i<=9;i++)
	{
		if(i==tmp[1])continue;
		int num=i+tmp[2]*10+tmp[3]*100+tmp[4]*1000;
		if(!vst[num])
			G[id[x]].push_back(id[num]);
	}
	for(ri i=0;i<=9;i++)
	{
		if(i==tmp[2])continue;
		int num=tmp[1]+i*10+tmp[3]*100+tmp[4]*1000;
		if(!vst[num])
			G[id[x]].push_back(id[num]);
	}
	for(ri i=0;i<=9;i++)
	{
		if(i==tmp[3])continue;
		int num=tmp[1]+tmp[2]*10+i*100+tmp[4]*1000;
		if(!vst[num])
			G[id[x]].push_back(id[num]);
	}
	for(ri i=0;i<=9;i++)
	{
		if(i==tmp[4])continue;
		int num=tmp[1]+tmp[2]*10+tmp[3]*100+i*1000;
		if(!vst[num])
			G[id[x]].push_back(id[num]);
	}
}
void Init()
{
	int Limit=10000;vst[1]=1;
	for(ri i=2;i<=Limit;i++)
	{
		if(!vst[i])p[++p[0]]=i;
		for(ri j=1;j<=p[0]&&i*p[j]<=Limit;j++)
		{
			vst[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
	for(int i=1;i<=p[0];i++)
		if(3<(int)(log10(p[i])+1))id[p[i]]=++cnt;
	for(int i=1;i<=p[0];i++)
		if(3<(int)(log10(p[i])+1))Produce(p[i]);
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
	Init(); 
	T=GetInt();
	while(T--)
	{
		int x=id[GetInt()],y=id[GetInt()];
		SPFA(x);
		if(dist[y]==INF)printf("Impossible\n");
		else printf("%d\n",dist[y]);
	}
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
