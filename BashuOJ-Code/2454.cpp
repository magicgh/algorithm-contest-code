#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<vector>
using namespace std;
const int MAXN=80005;
const int INF=0x7fffffff;
struct heap{
	int to,val;
	bool operator <(heap t)
	const{return val>t.val;};
};
struct node{int x,y,c;};
struct path{int to,val;};
struct bus{int x,y,t,c;};
vector<path>a[MAXN];
vector<node>Edge;
vector<int>G[MAXN];
bool vst[MAXN];
int N,M,S,T,dist[MAXN];
bus b[MAXN];
inline int GetInt(){
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
inline void AddEdge(int x,int y,int c){
	Edge.push_back({x,y,c});
	Edge.push_back({y,x,0});
	G[x].push_back(Edge.size()-2);
	G[y].push_back(Edge.size()-1);
}
inline void Dijkstra(int v0){
	priority_queue<heap>q;
	for(int i=1;i<=N;i++)dist[i]=INF;
	dist[v0]=0;q.push((heap){v0,dist[v0]});
	while(!q.empty()){
		heap now=q.top();q.pop();
		if(vst[now.to])continue;
		vst[now.to]=1;
		vector<path>::iterator it;
		for(it=a[now.to].begin();it!=a[now.to].end();++it){
			if(!vst[it->to]&&dist[it->to]>dist[now.to]+it->val){
			   	dist[it->to]=dist[now.to]+it->val;
			   	q.push((heap){it->to,dist[it->to]});
			}
		}
	}
	return;
}
struct Dinic{
	int lev[MAXN];
	bool BFS(){
		memset(lev,0,sizeof(lev));
		queue<int>q;
		q.push(S);
		lev[S]=1;
		while(!q.empty()){
			int now=q.front();q.pop();
			if(now==T)return true;
			for(int i=0;i<G[now].size();i++){
				node& next=Edge[G[now][i]];
				if(!lev[next.y]&&next.c>0){
					q.push(next.y);
					lev[next.y]=lev[now]+1;
				}
			}
		}
	    return false;
	}
	int DFS(int now,int f){
		if(now==T)return f;
		int ret=0,delta;
		for(int i=0;i<G[now].size();i++){
			node& next=Edge[G[now][i]];
			if(next.c>0&&lev[next.y]==lev[next.x]+1){
				delta=DFS(next.y,min(f,next.c));
				Edge[G[now][i]].c-=delta;
				Edge[G[now][i]^1].c+=delta;
				ret+=delta;f-=delta;
				if(!f)return ret;
			}
		}
		return ret;
	}
	void main(){
		int Ans=0;
		while(BFS())Ans+=DFS(S,INF);
		printf("%d",Ans);
	}
};
Dinic DC;
int main(){
	N=GetInt();M=GetInt();
	S=1,T=N;
	for(int i=1;i<=M;i++){
		int x=GetInt(),y=GetInt(),t=GetInt(),c=GetInt();
		b[i]=((bus){x,y,t,c});
		a[x].push_back((path){y,t});a[y].push_back((path){x,t});
	}
	Dijkstra(1);
	printf("%d\n",dist[N]);
	for(int i=1;i<=M;i++){
		if(dist[b[i].x]+b[i].t==dist[b[i].y])AddEdge(b[i].x,b[i].y,b[i].c);
		if(dist[b[i].y]+b[i].t==dist[b[i].x])AddEdge(b[i].y,b[i].x,b[i].c);
	}
	DC.main();
	return 0;
}