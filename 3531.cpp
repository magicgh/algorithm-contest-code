#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#define ri register int
#define ll long long
using namespace std;
const ll INF=0x7fffffff; 
const int MAXN=100005;
struct City{ll h,dist;};
inline bool cmp(const City &a,const City &b)
{
	return (a.dist==b.dist&&a.h<b.h)||(a.dist<b.dist);
}
map<ll,int>ID;
set<ll>s;
int n,m,X0,qid,Aid[MAXN],Bid[MAXN],ABpos[MAXN][18];
ll h[MAXN],Adist[MAXN],Bdist[MAXN],sA,sB;
ll Awalk[MAXN][18],Bwalk[MAXN][18];
double q1=1e300;
City nearest[5];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void find_next_city(int pos)
{
	s.insert(h[pos]);
 	nearest[1].h=*(--s.lower_bound(h[pos])),nearest[2].h=*s.upper_bound(h[pos]);//找到上界和下界 
    if(nearest[1].h!=-INF)nearest[3].h=*--s.lower_bound(nearest[1].h);else nearest[3].h=-INF;
	if(nearest[2].h!=INF)nearest[4].h=*s.upper_bound(nearest[2].h);else nearest[4].h=INF;//找到次上界和次下界
	for(ri i=1;i<=4;i++)nearest[i].dist=abs(h[pos]-nearest[i].h);
	sort(nearest+1,nearest+5,cmp);//选出最近点和次近点
	Adist[pos]=nearest[2].dist,Aid[pos]=ID[nearest[2].h]; 
	Bdist[pos]=nearest[1].dist,Bid[pos]=ID[nearest[1].h];//求出对于每个点A与B的目的地 
}
void ST()
{
	for(int i=n;i>=1;i--)//只能倒枚 
	{
		 if(Aid[i])Awalk[i][0]=Adist[i],ABpos[i][0]=Aid[i];//A往东走 
		 if(Bid[Aid[i]])Awalk[i][1]=Adist[i],Bwalk[i][1]=Bdist[Aid[i]],ABpos[i][1]=Bid[Aid[i]];//B往东走
	}
	int k=(int)(log2(n));
	for(int i=n;i>=1;i--)//只能倒枚 
		for(int j=2;j<=k;j++)//倍增法 
		{
	        if(!ABpos[ABpos[i][j-1]][j-1])break;
	        Awalk[i][j]=Awalk[i][j-1]+Awalk[ABpos[i][j-1]][j-1];
	        Bwalk[i][j]=Bwalk[i][j-1]+Bwalk[ABpos[i][j-1]][j-1];
	        ABpos[i][j]=ABpos[ABpos[i][j-1]][j-1];
	    }
}
inline void Query(int s,int Limit)
{
	sA=sB=0;
	int k=(int)(log2(n));
	for(ri i=k;i>=0;i--)//从2^k往下放 
	{
		if(ABpos[s][i]&&sA+sB+Awalk[s][i]+Bwalk[s][i]<=Limit)
		{
			sA+=Awalk[s][i],sB+=Bwalk[s][i];
			s=ABpos[s][i];//求出A与B走的距离 
		}
	}
}
int main()
{
	n=getint();
	s.insert(INF),s.insert(-INF);//插入两个哨兵 
	for(ri i=1;i<=n;i++)
	{
		h[i]=getint();
		ID[h[i]]=i;//建立高度到序号的映射 
	}
	for(ri i=n;i>=1;i--)find_next_city(i);//从n到s倒着插入 
	ST(),X0=getint();
	for(ri s=1;s<n;s++)
	{
		Query(s,X0);
		double t=(sB==0)?INF:(double)sA/(double)sB;
		if(t<q1||(q1==t&&s<qid))q1=t,qid=s;
	}
	printf("%d\n",qid);
	m=getint();
	for(ri i=1;i<=m;i++)
	{
		int s=getint(),x=getint();
		Query(s,x);
		printf("%lld %lld\n",sA,sB);
	}
	return 0;
}