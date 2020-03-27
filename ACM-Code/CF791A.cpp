#include<bits/stdc++.h>
#define DEBUG
#define ri register int
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
template <typename T>inline void read(T &input)
{
	T num=0,bj=1;
    char c=getchar();
    while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
    while(isdigit(c))num=num*10+c-'0',c=getchar();
    input=num*bj;
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
	double a,b;
	cin>>a>>b;
	cout<<floor(log(b/a)/log((double)3/(double)2)+1);
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
