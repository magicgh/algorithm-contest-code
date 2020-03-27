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
    string a,b;
    while(cin>>a>>b)
    {
        int lena=a.length(),lenb=b.length(),pos=-1;
        for(ri i=1;;i++)
        {
            if(i>lenb||lena-i<0)break;
            if(a.substr(lena-i,i)==b.substr(0,i))pos=i;
        }
        if(pos==-1)cout<<"\"NULL!\""<<endl;
        else cout<<b.substr(0,pos)<<endl;
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}