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
const int Mod=1000000009;
int n,m,c,Ans;
int f[15][35][35],g[15][35][35];
int C[905][905],a[15];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Init()
{
	for(ri i=1;i<=n*m;i++)
	{
		C[i][0]=C[i][i]=1;
		for(ri j=1;j<i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
	}
}
int main()
{
	//freopen("t.in","r",stdin);
	//freopen("t.out","w",stdout);
	n=getint(),m=getint(),c=getint();
	for(ri i=1;i<=c;i++)a[i]=getint();
	Init();
	for(ri k=1;k<=c;k++)
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=m;j++)
			{		
				if(i*j<a[k]||a[k]<max(i,j))continue;
				g[k][i][j]=C[i*j][a[k]];	
				for(ri x=1;x<=i;x++)
					for(ri y=1;y<=j;y++)
					{
						if(i==x&&j==y)continue;
						g[k][i][j]=(Mod+g[k][i][j]-((ll)g[k][x][y]*C[i][x]%Mod*C[j][y]%Mod))%Mod;
						//(i,j)恰好放k种颜色棋子的方案数 
					}
			}	
			
	f[0][0][0]=1;
	for(ri k=1;k<=c;k++)	
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=m;j++)
			{
				if(i*j<a[k])continue;
				for(ri x=0;x<i;x++)
					for(ri y=0;y<j;y++)
						f[k][i][j]=(f[k][i][j]+((ll)f[k-1][x][y]*g[k][i-x][j-y]%Mod*C[i][x]%Mod*C[j][y]%Mod))%Mod;
						//前k种颜色 
				}
					
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=m;j++)
				Ans=(Ans+((ll)f[c][i][j]*C[n][i]%Mod*C[m][j]%Mod))%Mod;
	printf("%d\n",Ans);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

