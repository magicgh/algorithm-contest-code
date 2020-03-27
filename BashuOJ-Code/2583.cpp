#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<deque>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=2000005;
int n,m,s[MAXN],f[MAXN];
struct node{int f,s;};
deque<node>q;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)s[i]=s[i-1]+getint();
	q.push_back((node){m,m});
	for(ri i=1;i<=n;i++)
	{
		while(!q.empty()&&q.front().f<i*100)q.pop_front();
		f[i]=max(f[i],q.front().s-i*100+s[i]);
		while(!q.empty()&&q.back().s<f[i]-s[i])q.pop_back();
		q.push_back((node){f[i],f[i]-s[i]});
	}
	cout<<f[n]<<endl;
	return 0;
}
