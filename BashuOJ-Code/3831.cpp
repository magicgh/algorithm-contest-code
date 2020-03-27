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
const int MAXN=5000005;
stack<int>a;
stack<char>b;
int len,i=1,bj;
char ch[MAXN];	
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int Compare(char x,char y)
{
	if(x=='('&&y==')')return 0;
	if(x=='('||y=='(')return 1;
	if(x=='*'||x=='/'||y=='+'||y=='-'||y==')')return -1;
	return 1;
}
inline int Calc(int x,char op,int y)
{
	if(op=='+')return (x+y)%10000;
	if(op=='-')return (x-y)%10000;
	if(op=='*')return (x*y)%10000;
	if(op=='/')return (x/y)%10000;
}
int main()
{
	scanf("%s",ch+1);
	b.push('(');len=strlen(ch+1);ch[++len]=')';
	while(i<=len)
	{
		int num=0;bool flag=0;
		while(isdigit(ch[i]))
		{
			num=num*10+ch[i]-'0';
			i++,flag=1;
		}
		if(flag)a.push(num%10000);
		bj=Compare(b.top(),ch[i]);
		if(bj==-1)
		{
			int x2=a.top()%10000;a.pop();
			int x1=a.top()%10000;a.pop();
			a.push(Calc(x1,b.top(),x2));b.pop();
		}
		if(bj==1)b.push(ch[i]),i++;
		if(bj==0)b.pop(),i++;
	}
	printf("%lld",a.top()%10000);
	return 0;
}
