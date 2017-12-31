#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const int INF=0x7fffffff;
const int MAXN=505;
struct limit{int u,d;};
struct node{int x,y,c,u,d;};
vector<node>Edge;
vector<int>G[MAXN];
limit map[MAXN][MAXN];
char cache[2];
int Deg[MAXN],Print[MAXN][MAXN];
int N,M,K,C,s,t,S,T,Sum;
inline void Init()
{
	Sum=0;Edge.clear();
	memset(Deg,0,sizeof(Deg));
	for(int i=0;i<=405;i++)G[i].clear();
}
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
inline void AddEdge(int x,int y,int u,int d)
{
	Edge.push_back({x,y,u-d,u,d});
	Edge.push_back({y,x,0,u,d});
	G[x].push_back(Edge.size()-2);
	G[y].push_back(Edge.size()-1);
}
void Output()
{
	for(int i=1;i<=M;i++)
	{
		for(int j=0;j<G[i].size();j++)
		{
			node& next=Edge[G[i][j]];
			if(next.y<=M+N)Print[next.x][next.y-M]=next.u-next.c;
		}
	}
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=N;j++)printf("%d ",Print[i][j]);
		printf("\n");	
	}
}
struct SAP
{
	int gap[MAXN],lev[MAXN];
	void Init()
	{
		memset(gap,0,sizeof(gap));
		memset(lev,0,sizeof(lev));
	}
	int DFS(int now,int f)
	{
		if(now==T)return f;
		int ret=0,delta;
		for(int i=0;i<G[now].size();i++)
		{
			node& next=Edge[G[now][i]];
			if(next.c>0&&lev[next.x]==lev[next.y]+1)
			{
				delta=DFS(next.y,min(next.c,f));
				ret+=delta;f-=delta;
				Edge[G[now][i]].c-=delta;Edge[G[now][i]^1].c+=delta;
				if(!f||lev[S]==T)return ret;
			}
		}
		if(!(--gap[lev[now]]))lev[S]=T;
		gap[++lev[now]]++;
		return ret;
	}
	int main()
	{
		Init();
		int Ans=0;
		gap[0]=T;
		while(lev[S]<T-1)Ans+=DFS(S,INF);
		return Ans;
	}
};
SAP MaxFlow;
int main(){
	K=GetInt();
	while(K--)
	{
		Init();
		M=GetInt();N=GetInt();
		s=M+N+1,t=M+N+2;
		for(int i=1;i<=M;i++)
		{
			int sum=GetInt();
			AddEdge(s,i,sum,sum);
			Deg[s]-=sum;Deg[i]+=sum;
		}
		for(int i=1;i<=N;i++)
		{
			int sum=GetInt();
			AddEdge(i+M,t,sum,sum);
			Deg[i+M]-=sum;Deg[t]+=sum;
		}
		for(int i=1;i<=M;i++)
			for(int j=1;j<=N;j++)map[i][j]=((limit){INF,0});
		C=GetInt();
		int ax,ay,bx,by,up,down;
		for(int i=1;i<=C;i++)
		{
			int x=GetInt(),y=GetInt();
			scanf("%s",cache);
			int z=GetInt();
			if(cache[0]=='=')up=down=z;
			else if(cache[0]=='<')down=0,up=z-1;
			else down=z+1,up=INF;
			if(x==0)ax=1,ay=M;else ax=ay=x;
			if(y==0)bx=1,by=N;else bx=by=y;
			for(int ii=ax;ii<=ay;ii++)
			for(int jj=bx;jj<=by;jj++)
			{
				map[ii][jj].d=max(map[ii][jj].d,down);
				map[ii][jj].u=min(map[ii][jj].u,up);
			}
		}
		bool Check=0;
		for(int i=1;i<=M;i++)
		{
			if(Check)break;
			for(int j=1;j<=N;j++)
			{
				if(map[i][j].d>map[i][j].u){Check=1;break;}
				else
				{
				AddEdge(i,j+M,map[i][j].u,map[i][j].d);
				Deg[i]-=map[i][j].d;Deg[j+M]+=map[i][j].d;
				}	
			}
		}
		if(Check)printf("IMPOSSIBLE\n");
		else 
		{
			S=t+1,T=S+1;
			AddEdge(t,s,INF,0);
			for(int i=1;i<=M+N;i++)
			{
				if(Deg[i]>0)AddEdge(S,i,Deg[i],0),Sum+=Deg[i];
				else if(Deg[i]<0)AddEdge(i,T,-Deg[i],0);
			}
			if(MaxFlow.main()!=Sum)printf("IMPOSSIBLE\n");	
			else Output();
		}	
		printf("\n");
	}
	return 0;
}