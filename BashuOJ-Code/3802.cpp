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
#define Pi M_PI
using namespace std;
const int MAXN=105;
struct Point{double x,y;};
struct Query{int type;double theta,x,y;int t;};
Query q[1005];
Point p[MAXN];
int n,m,Begin[1005],End[1005];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct Matrix
{
	static const int SIZE=5;
	int n,m;
	double a[SIZE][SIZE];
	double *operator[](int x){return a[x];}
	Matrix(int n,int m)
	{
		this->n=n,this->m=m;
		memset(a,0,sizeof(a));
	}
	inline void Unit(){for(ri i=1;i<=n;i++)a[i][i]=1;}
	Matrix operator *(Matrix &b)
	const
	{
		Matrix c(n,b.m);
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=b.m;j++)
				for(ri k=1;k<=m;k++)c[i][j]=(c[i][j]+a[i][k]*b[k][j]);
		return c;
	}
	void operator *=(Matrix &b){*this=*this*b;}
	Matrix operator ^(int &b)
	const
	{
		Matrix ret(n,m),base=*this;ret.Unit();
		while(b)
		{
			if(b&1)ret*=base;
			base*=base;
			b>>=1;
		}
		return ret;
	}
};
Matrix Ans(3,3);
void Solve(int l,int r)
{
	Matrix ret(3,3);
	ret.Unit();
	for(ri i=l;i<=r;i++)
	{
		Matrix delta(3,3);
		if(q[i].type==1)
		{
			delta.Unit();
			delta[3][1]=q[i].x,delta[3][2]=q[i].y;
			ret*=delta;
		}
		if(q[i].type==2)
		{
			delta.Unit();
			delta[1][1]=q[i].x,delta[2][2]=q[i].y;
			ret*=delta;
		}
		if(q[i].type==3)
		{
			double angle=(360-q[i].theta)/180*Pi;
			delta[1][1]=cos(angle),delta[2][1]=-sin(angle),delta[3][1]=-cos(angle)*q[i].x+sin(angle)*q[i].y+q[i].x;
			delta[1][2]=sin(angle),delta[2][2]=cos(angle),delta[3][2]=-sin(angle)*q[i].x-cos(angle)*q[i].y+q[i].y;
			delta[3][3]=1;
			ret*=delta;
			
		}
		if(q[i].type==4)
		{
			Solve(i+1,End[i]-1);
			Ans=Ans^q[i].t;
			ret*=Ans;
			i=End[i];
		}
	}
	for(ri i=1;i<=Ans.n;i++)
		for(ri j=1;j<=Ans.m;j++)
			Ans[i][j]=ret[i][j];
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		double x,y;
		scanf("%lf%lf",&x,&y);
		p[i]=(Point){x,y};
	}
	char ch;
	while((ch=getchar()))
	{
		while(!isupper(ch)&&ch!=EOF)ch=getchar();
		if(ch==EOF)break;
		if(ch=='T')
		{
			
			while(ch!='(')ch=getchar();
			double a,b;
			scanf("%lf,%lf)",&a,&b);
			q[++m]=(Query){1,0,a,b,0};
		}
		if(ch=='S')
		{
			while(ch!='(')ch=getchar();
			double a,b;
			scanf("%lf,%lf)",&a,&b);
			q[++m]=(Query){2,0,a,b,0};
		}
		if(ch=='R')
		{
			while(ch!='(')ch=getchar();
			double a,b,c;
			scanf("%lf,%lf,%lf)",&a,&b,&c);
			q[++m]=(Query){3,a,b,c,0};
		}
		if(ch=='L')
		{
			while(ch!='(')ch=getchar();
			int T=getint();
			q[++m]=(Query){4,0,0,0,T};
		}
		if(ch=='E')
			q[++m]=(Query){5,0,0,0,0};
			
	}
	int top=0;
	for(ri i=1;i<=m;i++)
	{
		if(q[i].type==4)Begin[++top]=i;
		if(q[i].type==5)End[Begin[top--]]=i;
	}
	Solve(1,m);
	for(ri i=1;i<=n;i++)
	{
		Matrix P(3,3);
		P[1][1]=p[i].x,P[1][2]=p[i].y,P[1][3]=1;
		P*=Ans;
		printf("%.4lf %.4lf\n",P[1][1],P[1][2]);
	}
	return 0;
}