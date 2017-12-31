#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int n,t,x,s[200005],top=0;
int main(){
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
	scanf("%d",&t);
	if(t==0)
	{
		scanf("%d",&x);
	   if(top==0){top++;s[top]=x;}
	   else {top++;s[top]=max(x,s[top-1]);}
	}
	if(t==1)top--;
	if(t==2)
	{
		if(!top)puts("0");
		else printf("%d\n",s[top]);
	}
}
return 0;
}
