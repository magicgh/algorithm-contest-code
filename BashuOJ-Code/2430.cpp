#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
long long N,L;
long long s[500005],f[500005],q[500005];
inline double Slope(int i,int j)
{
	return (double(f[j]-f[i]+(s[j]+j)*(s[j]+j)-(s[i]+i)*(s[i]+i)))/double((s[j]+j-s[i]-i)<<1);
}
inline long long GetInt()
{
	long long num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DP()
{
		f[0]=0;q[1]=0;
		int l=1,r=1;
		for(int i=1;i<=N;++i){
        while(l<r&&Slope(q[l],q[l+1])<=(s[i]+i-L-1))l++;
        f[i]=f[q[l]]+(s[i]-s[q[l]]+i-q[l]-L-1)*(s[i]-s[q[l]]+i-q[l]-L-1);
        while(l<r&&Slope(q[r],i)<=Slope(q[r-1],q[r]))r--;
        q[++r]=i;
    }
		printf("%lld\n",f[N]);
}
int main(){
		N=GetInt();
		L=GetInt();
		long long x;
	for(int i=1;i<=N;i++)
	{
		x=GetInt();
		s[i]=s[i-1]+x;
	}
	DP();
	return 0;
}