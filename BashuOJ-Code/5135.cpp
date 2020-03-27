#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#define ri register int
#define ll long long
using namespace std;
stack<int>s;
const int MAXN=1000005;
int n,a[MAXN],Max[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void PutInt(int x)
{
     if(x<0)putchar('-'),x=-x;
     if(x>9)PutInt(x/10);
     putchar(x%10+'0');
}
int main()
{
	n=GetInt();
	for(ri i=1;i<=n;i++)a[i]=GetInt();
	for(ri i=n;i>=1;i--)Max[i]=max(Max[i+1],a[i]);
	for(ri i=1;i<=n;i++)
	{
		while(!s.empty()&&s.top()>Max[i])PutInt(s.top()),putchar(' '),s.pop();
		s.push(a[i]);
	}
	while(!s.empty())PutInt(s.top()),putchar(' '),s.pop();
	return 0;
}