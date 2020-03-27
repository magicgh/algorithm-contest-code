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
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int n;
int f[1005],a[1005];
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
	while(cin>>n)
	{
		if(n==0)break;
		int ret=0;
		memset(f,0,sizeof(f));
		for(ri i=1;i<=n;i++)cin>>a[i];
		for(ri i=1;i<=n;i++)
		{
			f[i]=a[i];
			for(ri j=1;j<=i;j++)
				if(a[j]<a[i]&&f[j]+a[i]>f[i])f[i]=f[j]+a[i];
		}
		for(ri i=1;i<=n;i++)
			ret=max(ret,f[i]);
		printf("%d\n",ret); 
	}
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
