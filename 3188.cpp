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
const int Mod=10007;
char str[100005];
stack<char>s;
int n,num[100005][2];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Calc(int a,char op,int b)
{
	int a0=num[a][0],a1=num[a][1],b0=num[b][0],b1=num[b][1];
	if(op=='+')
	{	
		num[a][0]=(a0%Mod*b0%Mod)%Mod;
		num[a][1]=(a0%Mod*b1%Mod+a1%Mod*b0%Mod+a1%Mod*b1%Mod)%Mod;
	}
	if(op=='*')
	{
		num[a][1]=(a1%Mod*b1%Mod)%Mod;
		num[a][0]=(a0%Mod*b0%Mod+a0%Mod*b1%Mod+a1%Mod*b0%Mod)%Mod;
	}
}
int main()
{
	n=getint();scanf("%s",str+1);
	str[n+1]=')',s.push('(');
	num[1][0]=num[1][1]=1;
	for(ri i=1,p=1;i<=n+1;i++)
	{
		if(str[i]=='(')s.push('(');
		else if(str[i]==')')
		{
			for(;s.top()!='(';p--,s.pop())Calc(p-1,s.top(),p);
			s.pop();//左括号 
		}
		else
		{
			for(;s.top()<=str[i]&&s.top()!='(';p--,s.pop())//当前符号比栈顶运算级低(*<+)
				Calc(p-1,s.top(),p);
			s.push(str[i]);//运算级低的入栈 
			num[++p][0]=num[p][1]=1;
		}
	}
	printf("%d",num[1][0]);
	return 0;
}
