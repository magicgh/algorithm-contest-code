#include<bits/stdc++.h>
#define ri register int
#define mp make_pair
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
int n;
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    while(cin>>n)
    {
        string s;
        double Ans=0;
        for(ri i=1;i<=n;i++)
        { 
            cin>>s;
            int len=s.length();
            int x=s[len-1]-'0';
            if(x<=4)Ans-=x/1000.000;
            else Ans+=(10-x)/1000.000;
        }
        printf("%.3lf\n",Ans);
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}