#include<bits/stdc++.h>
#define ri register int
#define mp make_pair
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
ll a,b;
inline int GetInt()
{
    int num=0,bj=1;
    char c=getchar();
    while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
    while(isdigit(c))num=num*10+c-'0',c=getchar();
    return num*bj;
}
inline ll Calc(ll x,ll y)
{
    ll bitsx=log2(x)+1,bitsy=log2(y)+1,cnt=0,ans=0;
    ll bits=max(bitsx,bitsy);
    for(ll i=1; i<=bits;i++)
    {
        ll cnt1=0,cnt2=0;
        ll p1=(1<<i),p2=(1<<(i-1));
        cnt1+=(x/p1*p2);
        ll t1=(x%p1)-p2;
        cnt1+=(t1>0&&x%p1)?t1:0;
        cnt2+=(y/p1*p2);
        ll t2=(y%p1)-p2;
        cnt2+=(t2>0&&y%p1)?t2:0;
        ans+=(cnt2-cnt1+cnt)>>1;
        cnt=(cnt+cnt2-cnt1)>>1;
    }
    while(cnt)
    {
        cnt>>=1;
        ans+=cnt;
    }
    return ans;
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    while(~scanf("%lld %lld",&a,&b))
        printf("%lld\n",Calc(a,b+1));
    //fclose(stdout);
    return 0;
}