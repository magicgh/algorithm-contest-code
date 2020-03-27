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
const int MAXN=100005;
int n,q,x[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
	n=GetInt();
	for(ri i=1;i<=n;i++)x[i]=GetInt();
	sort(x+1,x+n+1);
	q=GetInt();
	for(ri i=1;i<=q;i++)
	{
		int y=GetInt();
		cout<<lower_bound(x+1,x+n+1,y+1)-(x+1)<<endl;
	}
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
