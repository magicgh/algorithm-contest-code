#include<bits/stdc++.h>
#define DEBUG
#define ri register int
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
int T,m,n;
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
    T=GetInt();
    while(T--)
    {
        n=GetInt(),m=GetInt();
        string a,b;cin>>a>>b;
        if(a[0]=='0'&&b[m-1]=='1'&&a[n-1]=='1'&&b[0]=='0')cout<<"Happy\n";
        else if(a[0]=='1'&&b[m-1]=='0'&&a[n-1]=='0'&&b[0]=='1')cout<<"Happy\n";
        else cout<<"Sad\n";
        
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}