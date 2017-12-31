#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
inline int GetInt()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num;
}
int k,n,t[505],p[505],f[100005],sum=0;
int main(){
	k=GetInt();
	n=GetInt();
	for(int i=1;i<=n;i++)t[i]=GetInt(),p[i]=GetInt(),sum+=p[i];
	for(int i=1;i<=n;i++)
	for(int j=k;j>=t[i];j--)
		f[j]=max(f[j],f[j-t[i]]+p[i]);
	printf("%d",sum-f[k]);
	return 0;
}
