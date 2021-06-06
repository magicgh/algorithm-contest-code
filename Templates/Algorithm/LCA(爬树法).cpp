#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<vector>
using namespace std;
const int MAXN=200005;
vector<int>a[MAXN];
int prt[MAXN],dep[MAXN],p[MAXN][50];
int M,N,root=1;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
void GetDeep(int x,int depth)
{
	dep[x]=depth;
	vector<int>::iterator it;
	for(it=a[x].begin();it!=a[x].end();++it)GetDeep(*it,depth+1);
}
void ST()
{
	memset(p,-1,sizeof(p));
	for(int i=1;i<=N;i++)p[i][0]=prt[i];
	for(int j=1;j<=int(log2(N));j++)
	for(int i=1;i<=N;i++)
		if(p[i][j-1]!=-1)p[i][j]=p[p[i][j-1]][j-1];
}
int LCA(int a,int b)
{
	if(dep[a]<dep[b])swap(a,b);
	int k=int(log2(dep[a]));
	for(int i=k;i>=0;i--)if(dep[a]-(1<<i)>=dep[b])a=p[a][i];
	if(a==b)return a;
	for(int i=k;i>=0;i--)if(p[a][i]!=-1&&p[a][i]!=p[b][i])a=p[a][i],b=p[b][i];
	return p[a][0];
}
int main(){
	N=GetInt();M=GetInt();
	for(int i=1;i<N;i++)
	{
		int x=GetInt(),y=GetInt();
		a[x].push_back(y);
		prt[y]=x;
	}
	while(prt[root]!=0)root=prt[root];
	GetDeep(root,1);
	ST();
	for(int i=1;i<=M;i++)printf("%d\n",LCA(GetInt(),GetInt()));
	return 0;
}
