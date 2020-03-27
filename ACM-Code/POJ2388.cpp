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
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
int a[10005];
template <typename T>inline void read(T &input)
{
	T num=0,bj=1;
    char c=getchar();
    while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
    while(isdigit(c))num=num*10+c-'0',c=getchar();
    input=num*bj;
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
	int n;
	cin>>n;
	for(ri i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	cout<<a[n/2+1];
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}