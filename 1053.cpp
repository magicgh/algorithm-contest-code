#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<climits>
#include<cstdio>
using namespace std;
int n,l[50005],r[50005],a[50005],b[50005];
int t[50005],Max=INT_MIN;
inline int GetInt()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num;
}
void Compare(int x[])
{
	memset(t,0,sizeof(t));
	for(int i=1;i<=n;i++)t[(x[i]-i+n)%n]++;
	for(int i=1;i<=n;i++)Max=max(Max,t[i]);
}
int jiajia()
{
	n=GetInt();
	for(int i=1;i<=n;i++)l[i]=GetInt(),r[i]=GetInt();
	for(int i=1;i<=n;i++)if((l[l[i]]!=i&&r[l[i]]!=i)||(l[r[i]]!=i&&r[r[i]]!=i))return -1;
	a[1]=1,a[2]=l[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i-1]==l[a[i]])a[i+1]=r[a[i]];
		else a[i+1]=l[a[i]];
	}
	Compare(a);
	for(int i=1;i<=n;i++)b[i]=a[n-i+1];
	Compare(b);
	return n-Max;
}
int main(){
	printf("%d",jiajia());
	return 0;
}

