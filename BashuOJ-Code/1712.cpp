#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<list>
#include<queue>
#include<climits>
using namespace std;
struct node
{
	int to,val;
};
list<node>a[550];
int n,m,ans=0;
int dist[550],prt[550],Max[550][550];
bool vst[550];
inline int GetInt()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num;
}
inline bool Prim(int v0)
{
	for(int i=1;i<=n;i++)dist[i]=INT_MAX;
	dist[v0]=0;prt[v0]=0;
	for(int i=1;i<=n;i++)
	{
		int Min=0x7fffffff,MinNO=0;
		for(int j=1;j<=n;j++)if(!vst[j]&&Min>dist[j])Min=dist[j],MinNO=j;
		for(int j=1;j<=n;j++)
		if(vst[j])Max[MinNO][j]=Max[j][MinNO]=max(Max[j][prt[MinNO]],Min);
		vst[MinNO]=1;
		ans+=Min;
		if(Min==INT_MAX)return 0;
		list<node>::iterator k;
		for(k=a[MinNO].begin();k!=a[MinNO].end();++k)
		{
			if(!vst[k->to]&&dist[k->to]>k->val)
			{
				dist[k->to]=k->val;
				prt[k->to]=MinNO;
			}
		}
	}
	return 1;
	
}
int main(){
	n=GetInt();
	m=GetInt();
	int x,y,z;
	memset(vst,0,sizeof(vst));
	memset(dist,0,sizeof(dist));
	memset(Max,0,sizeof(Max));
	memset(prt,0,sizeof(prt));
	for(int i=1;i<=m;i++)
	{
		x=GetInt();
		y=GetInt();
		z=GetInt();
		a[x].push_back((node){y,z});
		a[y].push_back((node){x,z});
	}
	if(!Prim(1))
	{
	printf("Cost: -1\nCost: -1\n");
	return 0;
    }
	else printf("Cost: %d\n",ans);
	list<node>::iterator j;
	int Min=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		for(j=a[i].begin();j!=a[i].end();++j)
		{
			if(prt[i]!=j->to&&prt[j->to]!=i)Min=Min>(ans+j->val-Max[i][j->to])?(ans+j->val-Max[i][j->to]):Min;
		}
	}
	if(Min==INT_MAX)printf("Cost: -1\n");
	else printf("Cost: %d\n",Min);
	return 0;
}