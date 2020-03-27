#include<bits/stdc++.h>
#define DEBUG
#define ri register int
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
int a[15],b[15],c[15],T;
string que;
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
    while(cin>>T)
    {
        cin>>que;
        while(T--)
        {
            string s;
            cin>>s;
            memset(a,0,sizeof(a));
            memset(b,0,sizeof(b));
            memset(c,0,sizeof(c));
            if(s.find(que)!=-1){cout<<"No\n";continue;}
            for(ri i=0;i<s.length();i+=2)
            {
                if(s[i+1]=='T')a[s[i]-'0']++;
                if(s[i+1]=='S')b[s[i]-'0']++;
                if(s[i+1]=='W')c[s[i]-'0']++;
            }
            int cnt=0,cnt1=0;
            for(ri i=1;i<=9;i++)
            {
                if(a[i]==2)cnt++;
                if(b[i]==2)cnt++;
                if(c[i]==2)cnt++;
                if(a[i]==3)cnt1++;
                if(b[i]==3)cnt1++;
                if(c[i]==3)cnt1++;
            }
            if(cnt==7){cout<<"Yes\n";continue;}
            if(cnt1==4&&cnt==1){cout<<"Yes\n";continue;}
            else {cout<<"No\n";continue;}

        }
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}