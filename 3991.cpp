#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	int to,val;
};
vector<node>a[20005];
int N;
int CoreMin,Core,dn=0;
bool vst[20005];
int c[3],s[20005],dist[20005],Ans=0;
inline int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void GetCore(int x,int fa,int num)
{
	int Max=-0x7fffffff;
	vector<node>::iterator it;
	s[x]=1;
	for(it=a[x].begin();it!=a[x].end();++it)
	{
		if(it->to!=fa&&!vst[it->to])
		{
			GetCore(it->to,x,num);
			s[x]+=s[it->to];
			Max=max(s[it->to],Max);
		}
	}
	Max=max(Max,num-s[x]);
	if(CoreMin>Max)CoreMin=Max,Core=x;
}
void GetDist(int x,int fa)
{
	c[dist[x]]++;
	vector<node>::iterator it;
	for(it=a[x].begin();it!=a[x].end();++it)
		if(it->to!=fa&&!vst[it->to])
		{
			dist[it->to]=(dist[x]+it->val)%3;
			GetDist(it->to,x);
		}
	return;
}
void Calc(int x,int val,int cmd)
{
	c[0]=c[1]=c[2]=0;
	dist[x]=val;
	GetDist(x,0);
	Ans+=(c[0]*c[0]+c[1]*c[2]+c[2]*c[1])*cmd;
	return;
}
void DFS(int x,int num)
{
	CoreMin=0x7fffffff;Core=0;
	GetCore(x,0,num);
	int core=Core;
	vst[core]=1;
	Calc(core,0,1);
	vector<node>::iterator it;
	for(it=a[core].begin();it!=a[core].end();++it)
	{
		if(!vst[it->to])
		{
			Calc(it->to,it->val,-1);
			DFS(it->to,s[it->to]);
		}
	}
}
int main(){
	int x,y,z;
	int N=GetInt();
	int NN=N*N;
	for(int i=1;i<N;i++)
	{
		x=GetInt();
		y=GetInt();
		z=GetInt()%3;
		a[x].push_back((node){y,z});
		a[y].push_back((node){x,z});
	}
	DFS(1,N);
	int factor=gcd(NN,Ans);
	NN/=factor;Ans/=factor;
	printf("%d/%d",NN==Ans?1,1:Ans,NN);
	return 0;
}