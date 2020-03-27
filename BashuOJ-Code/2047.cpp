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
const int MAXN=10005;
const int INF=0x7fffffff/2;
int n,m,len,Maxlen,List[MAXN],Array[MAXN],f[MAXN];
inline bool cmp(const int &a,const int &b){return a>b;}
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
	List[0]=INF;
	for(ri i=n;i>=1;i--)
	{
		int pos=lower_bound(List+1,List+(n-i+1)+1,Array[i],cmp)-List;
		f[i]=pos;
		List[pos]=Array[i];
		Maxlen=max(Maxlen,pos);
	 }
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
		Array[i]=getint();
	LIS();
	m=getint();
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),value=0;
		if(x>Maxlen){printf("Impossible\n");continue;}
		for(ri j=1;j<=n;j++)
			if(x&&f[j]>=x&&Array[j]>value)
			{
				printf("%d ",Array[j]);
				x--,value=Array[j];
			}
			printf("\n");
	}
	return 0;
}

