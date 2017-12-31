#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<deque>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=1005;
struct Squ{int pos,val;};
deque<Squ>Qmax,Qmin;
int map[MAXN][MAXN],Min1[MAXN][MAXN],Max1[MAXN][MAXN],Min2[MAXN][MAXN],Max2[MAXN][MAXN];
int A,B,N,Ans=0x7fffffff/2;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void CalcA(int i)
{
	Qmin.clear(),Qmax.clear();
	for(ri j=1;j<=B;j++)
	{
		while(!Qmin.empty()&&Qmin.front().pos<=j-N)Qmin.pop_front();
		while(!Qmax.empty()&&Qmax.front().pos<=j-N)Qmax.pop_front();
		while(!Qmin.empty()&&Qmin.back().val>=map[i][j])Qmin.pop_back();
		while(!Qmax.empty()&&Qmax.back().val<=map[i][j])Qmax.pop_back();
		Qmin.push_back((Squ){j,map[i][j]});
		Qmax.push_back((Squ){j,map[i][j]});
		if(j>=N)
		{
			Min1[i][j]=Qmin.front().val;
			Max1[i][j]=Qmax.front().val;
		}
	}
}
inline void CalcB(int j)
{
	Qmin.clear(),Qmax.clear();
	for(ri i=1;i<=A;i++)
	{
		while(!Qmin.empty()&&Qmin.front().pos<=i-N)Qmin.pop_front();
		while(!Qmax.empty()&&Qmax.front().pos<=i-N)Qmax.pop_front();
		while(!Qmin.empty()&&Qmin.back().val>=Min1[i][j])Qmin.pop_back();
		while(!Qmax.empty()&&Qmax.back().val<=Max1[i][j])Qmax.pop_back();
		Qmin.push_back((Squ){i,Min1[i][j]});
		Qmax.push_back((Squ){i,Max1[i][j]});
		if(i>=N)
		{
			Min2[i][j]=Qmin.front().val;
			Max2[i][j]=Qmax.front().val;
		}
	}
}
int main()
{
	A=getint(),B=getint(),N=getint();
	for(ri i=1;i<=A;i++)
		for(ri j=1;j<=B;j++)
			map[i][j]=getint();	
	for(ri i=1;i<=A;i++)CalcA(i);
	for(ri i=1;i<=B;i++)CalcB(i);
	for(ri i=N;i<=A;i++)	
		for(ri j=N;j<=B;j++)Ans=min(Ans,Max2[i][j]-Min2[i][j]);
	printf("%d\n",Ans);
	return 0;
}

