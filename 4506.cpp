#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=105;
int m,n,len,List[MAXN][MAXN],tmp[MAXN][MAXN];
char ch[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void CKTurn()
{
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
			tmp[j][n-i+1]=List[i][j];
	memcpy(List,tmp,sizeof(tmp));
	swap(n,m);
}
inline void ACKTurn()
{
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
			tmp[m-j+1][i]=List[i][j];
	memcpy(List,tmp,sizeof(tmp));
	swap(n,m);
}
inline void LRTurn()
{
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=(m>>1);j++)
			swap(List[i][j],List[i][m-j+1]);
}
inline void UDTurn()
{
	for(ri i=1;i<=(n>>1);i++)
		swap(List[i],List[n-i+1]);
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
			List[i][j]=getint();
	scanf("%s",ch+1);
	len=strlen(ch+1);
	for(ri i=1;i<=len;i++)
	{
		if(ch[i]=='A')CKTurn();
		if(ch[i]=='B')ACKTurn();
		if(ch[i]=='C')LRTurn();
		if(ch[i]=='D')UDTurn();
	}
	for(ri i=1;i<=n;i++)
	{
		for(ri j=1;j<=m;j++)
			printf("%d ",List[i][j]);
		putchar('\n');
	}
	return 0;
}


