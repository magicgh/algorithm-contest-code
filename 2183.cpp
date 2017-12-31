#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<list>
#include<queue>
using namespace std;
const int INF=0x7fffffff;
struct node
{
	int to,val;
};
list<node>a[1005];
int N;
int dist[1005],used[1005]={0};
int r[30]={0},num[30]={0};
bool ext[1005]={0};
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-')||(bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
bool SPFA(int v0)
{
	queue<int>q;
	list<node>::iterator i;
	for(int i=0;i<=24;i++)dist[i]=INF,used[i]=0,ext[i]=0;	
	dist[v0]=0;q.push(v0);ext[v0]=1;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		ext[now]=0;
		for(i=a[now].begin();i!=a[now].end();++i)
		{
			if(dist[i->to]>dist[now]+i->val)
			{
				if(used[i->to]>=240)return 0;
				dist[i->to]=dist[now]+i->val;
				if(!ext[i->to])q.push(i->to),used[i->to]++,ext[i->to]=1;
			}
		}
	}
	return 1;
}
inline void AddEdge(int s24)
{
	 for(int i=0;i<=25;i++)a[i].clear();
	 for(int i=0;i<=24;i++)
	 {
    	a[i].push_back({i+1,num[i]});
    	a[i+1].push_back({i,0});
	 }
	 for(int i=8;i<=24;i++)
		a[i+1].push_back({i-7,-r[i]});
	 for(int i=0;i<=7;i++)
		a[i+1].push_back({i+17,s24-r[i]});
	 a[1].push_back({25,s24});
	 /*list<node>::iterator j;
	 for(int i=0;i<=24;i++)
	    for(j=a[i].begin();j!=a[i].end();++j)cout<<i<<"->"<<j->to<<":"<<j->val<<endl;	*/	
}
int main(){
	for(int i=0;i<=23;i++)r[i]=GetInt();
	N=GetInt();
	int t;
	for(int i=1;i<=N;i++)
	{
    t=GetInt(); 	
	num[t]++;//统计工作开始时刻为t[i]的出纳员个数为num[t[i]] 
    }
    for(int i=0;i<=N;i++)//枚举s[24]的值 
	{
		AddEdge(i);//建边 
		if(SPFA(0))
		{
		printf("%d",i);
		return 0;
	    }
	}		
	printf("No Solution!");
	return 0;
}