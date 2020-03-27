#include<bits/stdc++.h>
#define ri register int
#define mp make_pair
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
int n,m,a[2005],b[2005];
bool t[2015];
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
    int n,m;
    while(cin>>n>>m)
    {
        fill(t+1,t+1006,0);
        int Max=-INF;
        for(ri i=1;i<=n;i++)cin>>a[i],t[a[i]]=1,Max=max(Max,a[i]);
        for(ri i=1;i<=m;i++)cin>>b[i];
        for(int j=1;j<=Max;j++)
        {
            bool bj=0;
             for(int i=1;i<=m;i++)
            {
                if(t[b[i]+j]){bj=1;break;}
            }
            if(!bj){printf("%d\n",j);return 0;}
        }
        
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}