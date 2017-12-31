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
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int n;
string a,word[6]={"one","puton","out","output","in","input"};
int len[6],f[201];
bool bj=0;
int main()
{
	n=getint();
	for(int i=0;i<6;i++)len[i]=word[i].length();
	for(int i=1;i<=n;i++)
	{
		getline(cin,a);
		int lenth=a.length();
		a=" "+a;
		memset(f,0,sizeof(f));
		for(int j=1;j<=lenth;j++)
		{
			for(int k=0;k<6;k++)if(len[k]<=j&&a.substr(j-len[k]+1,len[k])==word[k])f[j]=f[j-len[k]]+len[k];
		}
		printf(f[lenth]==lenth?"YES\n":"NO\n");
	}
	return 0;
}
