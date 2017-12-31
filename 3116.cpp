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
const int MAXN=100005;
struct Island{int x,id;};
Island a[MAXN];
int n,m,Ans;
bool Hash[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const Island &a,const Island &b){return a.x<b.x;}
int main()
{
	//freopen("t.in","r",stdin);
	//freopen("t.out","w",stdout);
	n=getint(),Ans=1;
	for(ri i=1;i<=n;i++)
	{
		int x=getint();
		a[i]=(Island){x,i};
		Hash[i]=1;
	}
	sort(a+1,a+n+1,cmp);
	m=getint();
	for(ri i=1,j=1;i<=m;i++)
	{
		int t=getint();
		while(a[j].x<=t&&j<=n)
		{
			int pos=a[j].id,cnt=-1;
			if(pos>1&&Hash[pos-1])cnt++;
			if(pos<n&&Hash[pos+1])cnt++;
			Hash[pos]=0,Ans+=cnt,j++;
		}
		printf("%d\n",Ans);
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

