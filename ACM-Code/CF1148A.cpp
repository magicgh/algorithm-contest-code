#include<bits/stdc++.h>
#define ri register int
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
ll a,b,c,Ans=0;
inline ll GetInt()
{
    ll num=0,bj=1;
    char c=getchar();
    while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
    while(isdigit(c))num=num*10+c-'0',c=getchar();
    return num*bj;
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    a=GetInt(),b=GetInt(),c=GetInt();
    if(a==b)printf("%lld\n",a+b+c*2);
    else if(a>b)printf("%lld\n",c*2+b*2+1);
    else if(a<b)printf("%lld\n",c*2+a*2+1);
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}