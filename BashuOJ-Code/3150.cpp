#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int MAXN=505;
struct taxi{int ax,ay,bx,by,t;};
vector<int>Edge[MAXN];
taxi a[MAXN];
int vst[MAXN],belong[MAXN];
int N,M,cnt,ans;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
bool DFS(int x,int k)
{
	vector<int>::iterator it;
	for(it=Edge[x].begin();it!=Edge[x].end();++it)
	{
		if(vst[*it]==k)continue;
		vst[*it]=k;
		if(!belong[*it] or DFS(belong[*it],k))
		{
			belong[*it]=x;
			return 1;
		}
	}
	return 0;
}
int main(){
	N=GetInt();
	for(int i=1;i<=N;i++)
	{
		memset(belong,0,sizeof(belong));
		memset(vst,0,sizeof(vst));
		memset(a,0,sizeof(a));
		for(int j=1;j<=505;j++)Edge[j].clear();
		M=GetInt();cnt=0;ans=0;
		for(int j=1;j<=M;j++)
		{
		int hh,mm;
		scanf("%d:%d",&hh,&mm);
		a[j]=(taxi){GetInt(),GetInt(),GetInt(),GetInt(),hh*60+mm};	
		}
		for(int j=1;j<M;j++)
		for(int k=j+1;k<=M;k++)
		if(a[k].t>(a[j].t+abs(a[j].ax-a[j].bx)+abs(a[j].ay-a[j].by)+abs(a[k].ax-a[j].bx)+abs(a[k].ay-a[j].by)))Edge[j].push_back(k);
		for(int j=1;j<=M;j++)if(DFS(j,j))ans++;
			printf("%d\n",M-ans);
	}
	return 0;
}