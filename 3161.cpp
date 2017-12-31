#include<iostream>
#include<cstdio>
#include<cstring>
#include<list>
#include<cmath>
using namespace std;
bool vst[500005]={0};
int N,cnt=0,M;//cnt DFS序列长度 
int cmd[500005]={0};//操作苹果的数量 
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct appear
{
	int first,second;
};
struct bit
{
	int C[500005];
	inline int Lowbit(int x){return x&(-x);}
	inline void Modify(int x,int d)
	{
	for(int i=x;i<=cnt;i+=Lowbit(i))C[i]+=d;
	}
	inline int Sum(int x)
	{
	int Ans=0;
	for(int i=x;i>0;i-=Lowbit(i))Ans+=C[i];
	return Ans;
	}
};
list<int>a[500005];
appear b[500005];
bit tr;
inline void DFS(int u)
{
	list<int>::iterator it; 
	vst[u]=1;
	b[u].first=++cnt;
	for(it=a[u].begin();it!=a[u].end();++it)
	if(!vst[*it])DFS(*it);
	b[u].second=++cnt;
}
int main(){
	int x,y;
	N=GetInt();
	for(int i=1;i<=N-1;i++)
	{
		x=GetInt();
		y=GetInt();
		a[x].push_back(y);
		a[y].push_back(x);
	}
	DFS(1);//建立DFS序列 
	for(int i=1;i<=N;i++){//初始化 
		tr.Modify(b[i].first,1);
		cmd[i]=-1; 
	}	
	M=GetInt();
	char ch;
	for(int i=1;i<=M;i++)
	{
		scanf("%s",&ch);
		x=GetInt();
		if(ch=='C')
		tr.Modify(b[x].first,cmd[x]),cmd[x]=-cmd[x];
		if(ch=='Q')printf("%d\n",tr.Sum(b[x].second)-tr.Sum(b[x].first-1));
	}
	return 0;
}