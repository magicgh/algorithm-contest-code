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
const int Mod=2009;
struct Matrix
{
	int num[15][15];
	Matrix()
	{
		memset(num,0,sizeof(num));
	}
};
Matrix a,tmp;
char strn[50005];
int p;
int n[50005],t[50005];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int Div(int *a,int b)
{
	int d=0;
	for(ri i=a[0];i>=1;i--)
	{
		d=d*10+a[i];
		a[i]=d/b;
		d%=b;
	}
	while(a[0]>0&&a[a[0]]==0)a[0]--;
}
void Input()
{
	scanf("%s",strn+1);p=getint();
	n[0]=strlen(strn+1);
	for(ri i=n[0];i>=1;i--)n[i]=strn[n[0]-i+1]-'0';
	while(n[0]){t[++t[0]]=n[1]%2;Div(n,2);}
}
inline Matrix Multi(Matrix a,Matrix b)
{
	Matrix ans;
	for(ri i=1;i<=3;i++)
		for(ri j=1;j<=3;j++)
			for(ri k=1;k<=3;k++)ans.num[i][j]=(ans.num[i][j]+a.num[i][k]*b.num[k][j])%Mod;
	return ans;
}
int main()
{
	Input();
	a.num[1][1]=1,a.num[1][2]=a.num[1][3]=0;
	a.num[2][1]=a.num[2][2]=p,a.num[2][3]=0;
	a.num[3][1]=a.num[3][2]=a.num[3][3]=p;
	for(ri i=1;i<=3;i++)
		for(ri j=1;j<=3;j++)tmp.num[i][j]=a.num[i][j];
	for(ri i=t[0]-1;i>=1;i--)
	{
		a=Multi(a,a);
		if(t[i])a=Multi(a,tmp);
	}
	printf("%d",a.num[3][1]%Mod);
	return 0;
}

