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
const int MAXN=5005;
const int Mod=100000000;
string A=" ",B=" ";
int f[MAXN][MAXN],g[MAXN][MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	char ch=getchar();
	while(!isalpha(ch))ch=getchar();
	while(isalpha(ch))A+=ch,ch=getchar();
	while(!isalpha(ch))ch=getchar();
	while(isalpha(ch))B+=ch,ch=getchar();
	for(unsigned ri i=0;i<A.size();i++)g[i][0]=1;
	for(unsigned ri i=0;i<B.size();i++)g[0][i]=1;
	for(unsigned ri i=1;i<A.size();i++)
		for(unsigned ri j=1;j<B.size();j++)
		{
			if(A[i]==B[j])
			{
				f[i][j]=f[i-1][j-1]+1;
				g[i][j]=g[i-1][j-1];
				if(f[i][j]==f[i-1][j])
					g[i][j]=(g[i][j]+g[i-1][j])%Mod;	
				if(f[i][j]==f[i][j-1])
					g[i][j]=(g[i][j]+g[i][j-1])%Mod;
			}
			else
			{
				f[i][j]=max(f[i-1][j],f[i][j-1]);
				g[i][j]=0;
				if(f[i][j]==f[i-1][j])
					g[i][j]=(g[i][j]+g[i-1][j])%Mod;
				if(f[i][j]==f[i][j-1])
					g[i][j]=(g[i][j]+g[i][j-1])%Mod;
				if(f[i][j]==f[i-1][j-1])
					g[i][j]=(g[i][j]-g[i-1][j-1])%Mod;
			}
				
		}
	printf("%d\n%d\n",f[A.size()-1][B.size()-1],(g[A.size()-1][B.size()-1]+Mod)%Mod);
	
	return 0;
}


