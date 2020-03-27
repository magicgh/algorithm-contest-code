#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int Mod=1e9+7;
string s;
int n,len,a[1005],f[1005];
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
	while(true)
	{
		getline(cin,s);
		if(s[0]=='{')len++,n++;
		else if(s[0]=='}')n--;
		else a[len]++;
		if(!n)break;
	}
	reverse(a+1,a+len+1);
	for(ri i=1;i<=len;i++)f[i]=((f[i-1]*2)%Mod+a[i]%Mod)%Mod;
	printf("%d",f[len]);
	return 0;
}

