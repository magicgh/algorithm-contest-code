#include<bits/stdc++.h>
#define ri register int
#define mp make_pair
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
int n,cnt1=0,cnt2=0,cnt3=0,cnt4=0;
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
    while(cin>>n)
    {
        string s;
        cin>>s;
        cnt1=cnt2=cnt3=cnt4=0;
        for(ri i=0;i<s.length();i++)
        {
            if(s[i]=='a')cnt1++;
            if(s[i]=='v')cnt2++;
            if(s[i]=='i')cnt3++;
            if(s[i]=='n')cnt4++;
        }
        int up=cnt1*cnt2*cnt3*cnt4,down=n*n*n*n;
        if(!up)cout<<"0/1"<<endl;
        else
        {   
            int Gcd=__gcd(up,down);
            up/=Gcd,down/=Gcd;
            cout<<up<<'/'<<down<<endl;
        }
   }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}