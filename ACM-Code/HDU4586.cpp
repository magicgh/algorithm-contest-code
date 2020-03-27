#include<bits/stdc++.h>
#define ri register int
#define mp make_pair
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
const int MAXN=205;
int n,m;
int a[MAXN];
inline int GetInt()
{
    int num=0,bj=1;
    char c=getchar();
    while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
    while(isdigit(c))num=num*10+c-'0',c=getchar();
    return num*bj;
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    while(~scanf("%d",&n))
    {
        int sum=0;
        for(ri i=1;i<=n;i++)a[i]=GetInt(),sum+=a[i];
        m=GetInt();
        for(ri i=1;i<=m;i++)int x=GetInt();
        if(sum==0)printf("0.00\n");
        else if(n==m)printf("inf\n");
        else printf("%.2lf\n",(double)sum/(double)(n-m));
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}