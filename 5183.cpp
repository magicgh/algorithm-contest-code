#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=15;
const int MAXS=215;
int n,len;
double R[MAXN];
char ch[MAXS];
stack<double>s1;
stack<char>s2;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
double Calc(double a,char c,double b)
{
	if(c=='-')return a+b;
	else return (a*b)/(a+b);
}
int main()
{
	n=GetInt();
	for(ri i=1;i<=n;i++)scanf("%lf",R+i);
	scanf("%s",ch+1);
	len=strlen(ch+1);
	for(ri i=1;i<=len;i++)
	{
		if(ch[i]=='('||ch[i]=='-'||ch[i]=='|')s2.push(ch[i]);
		else if(isdigit(ch[i]))s1.push(R[ch[i]-'0']);
		else if(ch[i]==')')
		{
			while(1)
			{
				if(s2.top()=='('){s2.pop();break;}
				double A=s1.top();s1.pop();
				double B=s1.top();s1.pop();
				char C=s2.top();s2.pop();
				s1.push(Calc(A,C,B));
			}
		}
	}
	printf("%.4lf\n",s1.top());
	return 0;
}
