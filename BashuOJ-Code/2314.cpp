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
int ans=-0x7fffffff;
char a[55],b[55];
int f[55][55];
int main()
{
	scanf("%s%s",&a,&b);
	int lena=strlen(a),lenb=strlen(b);
	for(int i=0;i<lena;i++)f[i][lenb]=-1;
	for(int i=0;i<lenb;i++)f[lena][i]=-1;
	f[lena][lenb]=0;
	for(int i=lena-1;i>=0;i--)
	for(int j=lenb-1;j>=0;j--)
	{
		f[i][j]=f[i+1][j+1];
		if(a[i]==b[j])f[i][j]=f[i][j]+2;
		for(int k=i+1;k<=lena-1;k++)f[i][j]=max(f[k][j]-1,f[i][j]);
		for(int k=j+1;k<=lenb-1;k++)f[i][j]=max(f[i][k]-1,f[i][j]);
		ans=max(ans,f[i][j]);
	}
	printf("%d",ans);
	return 0;
}

