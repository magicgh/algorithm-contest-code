#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define DEBUG
#define ri register int
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
int T,n,a[1005];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int DG(int x)
{
	if(x==1)return a[1];
	if(x==2)return a[2];
	if(x==3)return a[1]+a[2]+a[3];
	else return min(a[x-1]+2*a[1]+a[x],a[1]+a[x]+2*a[2])+DG(x-2);
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
	T=GetInt();
	while(T--)
	{
		n=GetInt();
		for(ri i=1;i<=n;i++)a[i]=GetInt();
		printf("%d\n",DG(n));
	}
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
