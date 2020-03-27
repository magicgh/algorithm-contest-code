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
string str;
int t,n;
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
	cin>>t;
	while(t--)
	{
		cin>>n>>str;
		while(1)
		{
			int pos=str.find("1001");
			if(pos==string::npos)
			{
				cout<<(str=="0"?"YES\n":"NO\n");
				break;
			}
			str.replace(pos,4,"0");
		}
	}
	return 0;
}

