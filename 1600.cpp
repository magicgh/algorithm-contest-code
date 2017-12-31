#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
string a,b;
int k,f[2001][2001];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>a>>b>>k;
	int len1=a.length(),len2=b.length();
	a=" "+a,b=" "+b;
	for(ri i=1;i<=len1;i++)f[i][0]=f[i-1][0]+k;
	for(ri i=1;i<=len2;i++)f[0][i]=f[0][i-1]+k;
	for(ri i=1;i<=len1;i++)
	for(ri j=1;j<=len2;j++)f[i][j]=min(f[i-1][j]+k,min(f[i][j-1]+k,f[i-1][j-1]+abs(int(a[i])-int(b[j]))));
	cout<<f[len1][len2];
	return 0;
}

