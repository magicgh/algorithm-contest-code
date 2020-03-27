#include<bits/stdc++.h>
#define DEBUG
#define ri register int
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
int T;ll n,Mod;
int p[6000000];
bool vst[100000005];
inline int GetInt()
{
    int num=0,bj=1;
    char c=getchar();
    while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
    while(isdigit(c))num=num*10+c-'0',c=getchar();
    return num*bj;
}
inline ll GetLL()
{
    ll num=0,bj=1;
    char c=getchar();
    while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
    while(isdigit(c))num=num*10+c-'0',c=getchar();
    return num*bj;
}
inline void InP()
{
    int Limit=100000000;
    for(ri i=2;i<=Limit;i++)
    {
        if(!vst[i])p[++p[0]]=i;
        for(ri j=1;j<=p[0]&&i*p[j]<=Limit;j++)
        {
            vst[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}
inline void Init()
{
    ll ret=1,sum=0;
    for(ll i=2;i<=n;i++)
    {
        ret=(ret*i)%Mod;
        if(ret==0)break;
        if(!vst[i])sum=(sum+ret)%Mod;
    }
    printf("%lld\n",sum);
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    T=GetInt();
    InP();
    while(T--)
    {
        n=GetLL(),Mod=GetLL();
        Init();
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}   