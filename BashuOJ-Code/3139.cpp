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
struct stonehenge{int num,move;};
stonehenge a[MAXN];
int n,m,len,b[MAXN];
inline bool cmp(const stonehenge &a,const stonehenge &b)
{
	return (a.num==b.num&&a.move>b.move)||(a.num<b.num);//move范围大的靠前，方便调整 
}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void LIS()
{
	for(ri i=1;i<=m;i++)
	{
		if(a[i].move>=b[len]){b[++len]=a[i].move;continue;}//构造LIS
		int pos=upper_bound(b+1,b+len+1,a[i].move)-b;
		b[pos]=a[i].move;//二分查找插入 
	}
	printf("%d\n",len);
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		int x=getint();
		if(i-x<0)continue;
		a[++m]=(stonehenge){x,i-x};
	}
	sort(a+1,a+m+1,cmp);
	LIS();
	return 0;
}

