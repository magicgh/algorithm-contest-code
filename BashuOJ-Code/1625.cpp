#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<list>
using namespace std;
list<int>a[1005];
int N,P,Dgree[1005],father[1005],Min=0x7fffffff/2;
int f[305][305];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void AddEdge()
{
	int x,y,z;
	x=GetInt();
	y=GetInt();
	a[x].push_back(y);
	a[y].push_back(x);
	Dgree[x]++,Dgree[y]++;
	father[y]=x;
	return;
}
void TreeDP(int root,int prt)
{
	list<int>::iterator next;
	f[root][1]=Dgree[root];
	for(next=a[root].begin();next!=a[root].end();++next)
	{
		if(*next!=prt)
		{
			TreeDP(*next,root);
			for(int i=P;i>=1;i--)
			   for(int j=1;j<=i-1;j++)f[root][i]=min(f[root][i],f[root][i-j]+f[*next][j]-2);
		}
	}
}
int main(){
	int root=1;
	N=GetInt();
	P=GetInt();
	for(int i=1;i<N;i++)AddEdge();
	for(int i=1;i<=N;i++)if(father[i]==0){root=i;break;}
	for(int i=1;i<=N;i++)
	for(int j=1;j<=P;j++)f[i][j]=0x7fffffff/2;
	TreeDP(root,0);
	for(int i=1;i<=N;i++)Min=min(Min,f[i][P]);
	printf("%d",Min);
	return 0;
}