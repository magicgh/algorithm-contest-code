#include<bits/stdc++.h>
#define DEBUG
#define ri register int
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
int T;
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
        string a,b;
        cin>>a>>b;
        bool Flag=0;
        int lena=a.length(),lenb=b.length();
        char Mina=a[0];int pos1=0;
        for(ri i=1;i<lena;i++)
        {
            if(Mina>a[i])Mina=a[i],pos1=i;
        }
        if(Mina>b[0]){cout<<"N0\n";continue;}
        else if(Mina<b[0]){cout<<"YE5\n";continue;}
        else
        {
            bool bj=0;
            for(ri i=1;;i++)
                if(a[pos1+i]>b[i]){bj=1;break;}
            if(!bj)cout<<"YE5\n";
            else cout<<"N0\n";
        }
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}