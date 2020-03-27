#include<bits/stdc++.h>
#define DEBUG
#define ri register int
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
ll n;
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
    while(~scanf("%lld",&n))
    {
        if(n%3==1||n%3==2)printf("\"even\"\n");
        else printf("\"odd\"\n");
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}