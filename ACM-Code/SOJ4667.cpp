#include<bits/stdc++.h>
#define DEBUG
#define ri register int
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
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
    int T=GetInt();
    while(T--)
    {
        int n=GetInt();
        if(n<3)cout<<0<<endl;
        else if(n<29)cout<<1<<endl;
        else if(n<11789)cout<<2<<endl;
        else cout<<3<<endl;
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}