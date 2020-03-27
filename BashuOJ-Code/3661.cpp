#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<vector>
#include<cstdio>
using namespace std;
const int MAXN=805;
const int INF=0x7fffffff;
const double eps=1e-8;
struct node{int x,y,c;};
int N,M,S,T,cnt=0;
double tmp=0;
node net[MAXN];
bool vst[MAXN],used[MAXN];
vector<node>Edge;
vector<int>G[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
inline void AddEdge(int x,int y,int c){
	Edge.push_back((node){x,y,c});
	Edge.push_back((node){y,x,0});
	G[x].push_back(Edge.size()-2);
	G[y].push_back(Edge.size()-1);
}
struct SAP
{
	int lev[MAXN],gap[MAXN];
	void Init()
	{
		Edge.clear();
		for(int i=0;i<=M*2;i++)G[i].clear();
		memset(used,0,sizeof(used));
		memset(lev,0,sizeof(lev));
		memset(gap,0,sizeof(gap));
	}
	int DFS(int now,int f){
		if(now==T)return f;
		int delta,ret=0;
		for(int i=0;i<G[now].size();i++){
			node& next=Edge[G[now][i]];
			if(next.c>0&&lev[next.x]==lev[next.y]+1){
			delta=DFS(next.y,min(next.c,f));
			Edge[G[now][i]].c-=delta;
			Edge[G[now][i]^1].c+=delta;
			ret+=delta;f-=delta;
			if(!f||lev[S]==T)return ret;
			}
		}
		if(!(--gap[lev[now]]))lev[S]=T;
		gap[++lev[now]]++;
		return ret;
	}
	int main()
	{
		int Ans=0;
		S=1,T=N;gap[0]=T;
		while(lev[S]<T)Ans+=DFS(S,INF);
		return Ans+tmp;
	}
};
SAP st;
inline void BuildGraph(double k)
{
	//以c/k作为平均值,利用最小割的思想,大于c/k的为正边,否则为负边 
	st.Init();
	tmp=0.0;
	for(int i=1;i<=M;i++)
	{
		if(net[i].c<=k)tmp+=net[i].c-k,used[i]=1;//没选和选也算不同的集合
		else AddEdge(net[i].x,net[i].y,net[i].c-k),AddEdge(net[i].y,net[i].x,net[i].c-k);
	}	
}
void DFS(int x)
{
	vst[x]=1;
	for(int i=0;i<G[x].size();i++)
	{
		node& next=Edge[G[x][i]];
		if(!vst[next.y]&&next.c)DFS(next.y);
	}
}
int main(){
	N=GetInt();
	M=GetInt();
	for(int i=1;i<=M;i++)net[i]=(node){GetInt(),GetInt(),GetInt()};
	double l=0,r=1e9;//10^7/10^-2 
	while(r-l>eps)
	{
		double mid=(l+r)/2.0;
		BuildGraph(mid);
		if(st.main()<=0)r=mid;
		else l=mid;
	}
	DFS(S);
	for(int i=1;i<=M;i++)if(vst[net[i].x]!=vst[net[i].y])used[i]=1;
	for(int i=1;i<=M;i++)if(used[i])cnt++;
	printf("%d\n",cnt);
	for(int i=1;i<=M;i++)if(used[i])printf("%d ",i);
	return 0;
}