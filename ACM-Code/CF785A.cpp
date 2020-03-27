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
	int n,sum=0;
	string s;
	cin>>n;
	for(ri i=1;i<=n;i++)
	{
		cin>>s;
		if(s=="Tetrahedron")sum+=4;
		if(s=="Cube")sum+=6;
		if(s=="Octahedron")sum+=8;
		if(s=="Dodecahedron")sum+=12;
		if(s=="Icosahedron")sum+=20;
	}
	cout<<sum<<endl;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
