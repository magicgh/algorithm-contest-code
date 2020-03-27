#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
int n,m,t,k,C[2005][2005],S[2005][2005];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Init()
{
	C[0][0]=1;
	for(ri i=1;i<=2000;i++)
	{
		C[i][0]=C[i][i]=1;
		for(ri j=1;j<i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%k;
	}
	for(ri i=1;i<=2000;i++)
		for(ri j=1;j<=2000;j++)
		{
			S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1];
			if(C[i][j]==0&&j<=i)S[i][j]++;
		}

}
int main()
{
	t=getint(),k=getint();
	Init();
	for(ri i=1;i<=t;i++)
	{
		n=getint(),m=getint();
		printf("%d\n",S[n][m]);
	}
	return 0;
}
