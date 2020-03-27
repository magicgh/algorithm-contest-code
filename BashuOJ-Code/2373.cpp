#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
int x,y,n;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline double DFS(double x,double y,int k)
{
	if(x<y)swap(x,y);
	if(k==1)return x/y;
	double Ans=1e300;
	for(int i=1;i<k;i++)
	{
		double cut_x=max(DFS(x*i/k,y,i),DFS(x*(k-i)/k,y,k-i));
		double cut_y=max(DFS(x,y*i/k,i),DFS(x,y*(k-i)/k,k-i));
		Ans=min(Ans,min(cut_x,cut_y));
	}
	return Ans;
}
int main()
{
	x=getint(),y=getint(),n=getint();
	printf("%.6lf",DFS(x,y,n));
	return 0;
}

