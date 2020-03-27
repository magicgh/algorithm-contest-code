#include<iostream>
#include<cstdio>
#include<cmath>
#define ri register int
#define uint long long
using namespace std;
uint n,c1,c2,c3,h=1,t=1,s[1000005],q[1000005],f[1000005];
inline uint getint()
{
	uint num=0;int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline double slope(const int &j,const int &k){return double(f[k]-f[j]+c1*s[k]*s[k]-c2*s[k]+c2*s[j]-c1*s[j]*s[j])/double(s[k]-s[j]);}
int main()
{
	n=getint(),c1=getint(),c2=getint(),c3=getint();
	for(ri i=1;i<=n;i++)s[i]=s[i-1]+getint();
	for(ri i=1;i<=n;i++)
	{	
		while(h<t&&slope(q[h],q[h+1])>2*c1*s[i])h++;
		f[i]=f[q[h]]+c1*(s[i]-s[q[h]])*(s[i]-s[q[h]])+c2*(s[i]-s[q[h]])+c3;
		while(h<t&&slope(q[t-1],q[t])<slope(q[t],i))t--;
		q[++t]=i;
	}
	printf("%lld",f[n]);
	return 0;
}

