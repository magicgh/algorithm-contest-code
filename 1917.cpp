#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
int T,n,m,Ans;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int m,int n,int s)
{
	if(m<n)swap(n,m);
	if(m/n>1||m%n==0){Ans=s;return;}
	DFS(m-n,n,s^1); 
}
int main()
{
	T=getint();
	while(T--)
	{
		Ans=-1;
		m=getint(),n=getint();
		DFS(m,n,0);
		printf(Ans?"Ollie wins\n":"Stan wins\n");
	}
	return 0;
}


