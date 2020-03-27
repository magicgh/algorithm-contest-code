#include<bits/stdc++.h>
#define ri register int
#define mp make_pair
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
    int x=GetInt(),y=GetInt();
    int a=(x+y)/2,b=(x-y)/2;
    printf("%d\n",a*b);
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}