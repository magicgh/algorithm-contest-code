#include<iostream>
#include<cstdio>
using namespace std;
long long L[100005],R[100005];
int main(){
long long i,m,n,a,b,t=0;
char c;
scanf("%lld %lld",&n,&m);
for(i=0;i<=n;i++)
{
L[i]=i-1;
R[i]=i+1;
}
for(i=0;i<m;i++)
{
	scanf("\n%c %lld %lld",&c,&a,&b);
	if(c=='A')
	{
		R[L[a]]=R[a];
		L[R[a]]=L[a];
		R[a]=b;
		L[a]=L[b];
		R[L[b]]=a;
		L[b]=a;
	}
	if(c=='B')
	{
		R[L[a]]=R[a];
		L[R[a]]=L[a];
		R[a]=R[b];
		L[a]=b;
		L[R[b]]=a;
		R[b]=a;
	}
}
for(i=1;i<=n;i++)
{
	printf("%lld\n",R[t]);
	t=R[t];
}
	return 0;
}