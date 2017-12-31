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
const int MAXN=100005;
vector<int>a;
int b[MAXN];
int n,len,Ans[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void LIS() __attribute__((optimize("-Os")));
void LIS()
{
	for(ri i=0;i<n;i++)
	{
		if(a[i]>=b[len]){b[++len]=a[i];Ans[a[i]]=len;continue;}
		int pos=upper_bound(b+1,b+len+1,a[i])-b;
		b[pos]=a[i],Ans[a[i]]=pos;
	}
}
int main() __attribute__((optimize("-Os")));
int main()
{
	n=getint();
	for(int i=1;i<=n;i++)
	{
		int pos=getint();
		a.insert(a.begin()+pos,i);
	}
	LIS();
	for(ri i=1;i<=n;i++)Ans[i]=max(Ans[i],Ans[i-1]);
	for(ri i=1;i<=n;i++)printf("%d\n",Ans[i]); 
	return 0;
}

