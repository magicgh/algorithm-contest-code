#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<list>
using namespace std;
const int INF=-0x7ffffff/2;
struct node{int to,val;};
int N,M;
int Money[3005],Leaf[3005];
int f[3005][3005];
list<node>a[3005];
inline int GetInt()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num;
}
inline void DFS(int x)
{
	list<node>::iterator i;
	if(x>N-M){Leaf[x]=1,f[x][1]=Money[x];return;}
	for(i=a[x].begin();i!=a[x].end();++i)
	{
		DFS(i->to);
		Leaf[x]+=Leaf[i->to];
	}
	for(int i=1;i<=Leaf[x];i++)f[x][i]=INF;
}
inline void TreeDP(int x)
{
	list<node>::iterator i;
	for(i=a[x].begin();i!=a[x].end();++i)
	{
		TreeDP(i->to);
		for(int j=Leaf[x];j>=1;j--)
		{
			for(int k=0;k<=j;k++)
			f[x][j]=max(f[x][k]+f[i->to][j-k]-i->val,f[x][j]);
		}
	}
}
int main(){
	N=GetInt();
	M=GetInt();
	int K,X,Y;
	for(int i=1;i<=N-M;i++)
	{
		K=GetInt();
		for(int j=1;j<=K;j++)
		{
			X=GetInt();Y=GetInt();
			a[i].push_front((node){X,Y});
		}
	}
	for(int i=1;i<=N;i++)
	for(int j=1;j<=M;j++)f[i][j]=INF;
	for(int i=N-M+1;i<=N;i++)Money[i]=GetInt();
	DFS(1);
	TreeDP(1);
	int i,j;
	for(i=Leaf[1];i>=1;i--)
	 {
	   if(f[1][i]>=0)
	    { cout<<i<<endl;
	      break;
		}
	}

	return 0;
}