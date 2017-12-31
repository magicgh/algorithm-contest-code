#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
int K,C,M,N,MM,mid;
const int INF=0x7fffffff/2;
vector<int>a[235];
int belong[235][235],cnt[235];
bool vst[235];
int dist[235][235];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
void Floyed()
{
	for(int k=1;k<=N;k++)
	for(int i=1;i<=N;i++)
	for(int j=1;j<=N;j++)
	if(dist[i][k]!=INF)dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}
inline bool DFS(int x)
{
	vector<int>::iterator it;
	for(it=a[x].begin();it!=a[x].end();++it)
	{
		if(vst[*it])continue;
		vst[*it]=1;
		if(cnt[*it]<M){belong[*it][++cnt[*it]]=x;return 1;}
		for(int i=1;i<=cnt[*it];i++)
			if(DFS(belong[*it][i])){belong[*it][i]=x;return 1;}
	}
	return 0;
}	
inline void Build(int limit)
{
	for(int i=K+1;i<=N;i++)a[i].clear();
	for(int i=K+1;i<=N;i++)
	for(int j=1;j<=K;j++)if(dist[i][j]<=limit)a[i].push_back(j);
}
inline bool Hungary()
{
	memset(cnt,0,sizeof(cnt));
	for(int i=K+1;i<=N;i++)
	{
		memset(vst,0,sizeof(vst));
		if(!DFS(i))return 0;
	}
	return 1;
}
int BinSch()
{
	int l=0,r=MM;
	while(l<=r)
	{
		mid=(l+r)>>1;
		Build(mid);
		if(Hungary())r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main(){
	K=GetInt();C=GetInt();M=GetInt();N=K+C;MM=200*N;
	for(int i=1;i<=N;i++)
	for(int j=1;j<=N;j++)
	{
	dist[i][j]=GetInt();
	if(!dist[i][j])dist[i][j]=INF;
}
	Floyed();
	printf("%d",BinSch());
	return 0;
}