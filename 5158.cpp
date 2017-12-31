#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#define ri register int
#define ll long long
//#define Debug1
using namespace std;
const int MAXN=100005;
const ll INF=1e18;
ll N,tot,Size[MAXN],Max[MAXN];
ll Mod,cnt,K,X,w[MAXN];
ll kpow[MAXN]={1},kinv[MAXN],df[MAXN],dt[MAXN],target[MAXN];
ll dep[MAXN],List[MAXN],in[MAXN],out[MAXN];
bool vst[MAXN];
vector<ll>Path[MAXN];
vector<ll>a[MAXN];
inline ll GetLL()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll Pow(ll a,ll b)
{
	ll ret=1,base=a;
	while(b)
	{
		if(b&1)ret=ret*base%Mod;
		base=base*base%Mod;
		b>>=1;
	}
	return ret;
}
map<ll,ll>from,to;
map<ll,ll>::iterator m_it;
inline void add(map<ll,ll>&h,ll pos,ll val)
{
	m_it=h.find(pos);
	if(m_it==h.end())h[pos]=val;
	else m_it->second+=val;
}
inline ll count(map<ll,ll>&h,ll pos)
{
	m_it=h.find(pos);
	if(m_it==h.end())return 0;
	else return m_it->second;
}
void FindCore(ll u,ll fa)
{
	Size[u]=1,Max[u]=0,List[++tot]=u;
	vector<ll>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa||vst[*it])continue;
		FindCore(*it,u);
		Size[u]+=Size[*it];
		Max[u]=max(Max[u],Size[*it]);
	}
}
inline ll GetCore(ll x)
{
	tot=0,FindCore(x,0);
	ll Min=INF,Core=-1;
	for(ri i=1;i<=tot;i++)
	{
		ll u=List[i];
		Max[u]=max(Max[u],Size[x]-Size[u]);
		if(Min>Max[u])
			Min=Max[u],Core=u;
	}
	return Core;
}
void NewPath(ll u,ll fa,ll c)
{
	Path[c].push_back(u);
	vector<ll>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa||vst[*it])continue;
		NewPath(*it,u,c);
	}
} 
void GetDist(ll u,ll fa)
{
	vector<ll>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(vst[*it]||*it==fa)continue;
		dep[*it]=dep[u]+1;
		dt[*it]=(dt[u]+w[*it]*kpow[dep[*it]])%Mod;
		df[*it]=(df[u]*K+w[*it])%Mod;
		GetDist(*it,u);
	}
}
void Solve()
{
	from.clear(),to.clear();
	for(ri i=1;i<=tot;i++)
	{
		ll u=List[i];
		vector<ll>::iterator p;
		for(p=Path[u].begin();p!=Path[u].end();++p)
			add(to,dt[*p],1);
	}
	for(ri i=1;i<=tot;i++)
	{
		ll u=List[i];
		vector<ll>::iterator p;
		for(p=Path[u].begin();p!=Path[u].end();++p)
			add(to,dt[*p],-1);
		for(p=Path[u].begin();p!=Path[u].end();++p)
		{
			in[*p]+=count(from,dt[*p]);
			out[*p]+=count(to,target[*p]); 
		}
		for(p=Path[u].begin();p!=Path[u].end();++p)
			add(from,target[*p],1); 
	}
}
void Divide(ll x)
{
	x=GetCore(x);
	df[x]=dt[x]=w[x],vst[x]=1,dep[x]=0;
	GetDist(x,0);
	for(ri i=1;i<=tot;i++)
	{
		if(List[i]==x&&dt[List[i]]==X)in[x]++,out[x]++;
		else
		{
			if(dt[List[i]]==X)in[List[i]]++,out[x]++;
		    if(df[List[i]]==X)in[x]++,out[List[i]]++;
		}
	}
	#ifdef Debug1
	 cout<<x<<endl<<endl;
    for (ll i = 1; i <= N; ++i) 
    {
    	cout<<in[i]<<' '<<out[i]<<endl;
	}
	cout<<endl<<endl;
	#endif
	#ifdef Debug1
	printf("Count %d\n",x);
	#endif
	tot=0;
	vector<ll>::iterator it;
	for(it=a[x].begin();it!=a[x].end();++it)
	{
		if(vst[*it])continue;
		Path[*it].clear(),List[++tot]=*it;
		NewPath(*it,0,*it);
		vector<ll>::iterator p;
		for(p=Path[*it].begin();p!=Path[*it].end();++p)
			target[*p]=((X-df[*p]+Mod)*kinv[dep[*p]]+w[x])%Mod;
	}
	#ifdef Debug1
	printf("GetNewPath %d\n",x);
	#endif
	Solve();//左进右出
	#ifdef Debug1
	printf("SolveFrom-L-in-to-R-out %d\n",x);
	#endif
	reverse(List+1,List+tot+1);
	Solve();//左出右进 
	#ifdef Debug1
	printf("SolveFrom-L-out-to-R-in %d\n",x);
	#endif
	for(it=a[x].begin();it!=a[x].end();++it)
	{
		//printf("iterate the graph: %d->%d\n",x,*it);
		if(vst[*it])continue;
		Divide(*it);
	}
}
int main()
{
	N=GetLL(),Mod=GetLL(),K=GetLL(),X=GetLL()%Mod;
	for(ri i=1;i<=N;i++)w[i]=GetLL()%Mod;
	for(ri i=1;i<N;i++)
	{
		ll u=GetLL(),v=GetLL();
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(ri i=1;i<=N;i++)reverse(a[i].begin(),a[i].end());
	for(ri i=1;i<=N;i++)
	{
		kpow[i]=kpow[i-1]*K%Mod;
		kinv[i]=Pow(kpow[i],Mod-2);
	}
	Divide(1);
	for(ri i=1;i<=N;i++)
		cnt+=in[i]*(N-out[i])+out[i]*(N-in[i])+2*(in[i]*(N-in[i])+out[i]*(N-out[i]));
	printf("%lld\n",N*N*N-cnt/2);
	return 0;
}