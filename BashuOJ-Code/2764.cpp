#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
struct node
{
	int num,val;
};
vector<node>a[100005];
int N,K,Ans=0;
int s[100005],dist[100005],dN=0,Core=0,CoreN=0;
bool vst[100005];
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
	int Max=0;
	vector<node>::iterator it;
	s[x]=1;
	for(it=a[x].begin();it!=a[x].end();++it)
	{
		if(it->num!=fa&&!vst[it->num])
		{
		GetCore(it->num,x,num);
		s[x]+=s[it->num];//统计x子树节点个数 
		Max=max(Max,s[it->num]);//x下节点最大的子树 
	}
	}
	Max=max(Max,num-s[x]);
	if(Core>Max)Core=Max,CoreN=x;//GetCore 
}
void GetDist(int x,int fa,int d) 
{
	dist[++dN]=d;
	vector<node>::iterator it;
	for(it=a[x].begin();it!=a[x].end();++it)
		if(it->num!=fa&&!vst[it->num])GetDist(it->num,x,d+it->val);
}
void Calc(int x,int len,int cmd) 
{
	dN=0;	
	GetDist(x,0,len);
	sort(dist+1,dist+dN+1);
	int l=1,r=dN;
	while(l<r) 
	{
		if(dist[l]+dist[r]<=K)Ans+=(r-l)*cmd,l++;
		else r--;
	}	
}
void DFS(int x,int num)
{
	Core=0x7fffffff/2;	
	GetCore(x,0,num);
	int C=CoreN;
	Calc(C,0,1);
	vst[C]=1;
	vector<node>::iterator it;
	for(it=a[C].begin();it!=a[C].end();++it)
	{
		if(!vst[it->num])	
		{
			Calc(it->num,it->val,-1);
			DFS(it->num,s[it->num]); 
		}
	}
}
int main(){
	N=GetInt();
	K=GetInt();
	for(int i=1;i<=N-1;i++)
	{
		int x=GetInt(),y=GetInt(),z=GetInt();
		a[x].push_back((node){y,z});
		a[y].push_back((node){x,z});
	}
	DFS(1,N);
	printf("%d",Ans);
	return 0;
}
