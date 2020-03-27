#include<iostream>
#include<cmath>
using namespace std;
long long a[25]= {0},f=0,t=0;
int quickmi(long long i,long long j)
{
	int ans=1,temp=i;
	while(j!=0)
    {
        if(j&1)
            ans*=temp;
        temp*=temp;
        j>>=1;
    }
    return ans;
}
bool Try(long long i,long long j)
{
	
	if(i==21&&j==1)return false;
	if(j==21) {
		++i;
		j=i+1;
	}
	if(a[i]==a[j]) {
		bool flag=true;
		for(int k=1; k<=j-i; k++) {
			if(a[i+k]!=a[j+k]) {
				flag=false;
				break;
			}
		}
		if(flag==true) {
			f=i;t=j-1;
			if(f>t)swap(f,t);
			return true;
		}
	}
	Try(i,j+1);
}
int gcd(long long z,long long m)
{
	if(z%m==0)return m;
	else gcd(m,z%m);
}
int main()
{
	long long i,j,ans=0,ans1=0;
	cin>>a[1]>>a[2];
	for(i=3; i<=20; i++)a[i]=(a[i-1]+a[i-2])%4;
	if(Try(1,2)==true) {
		for(i=1; i<=t; i++){ans+=a[i]*quickmi(10,t-i);}
		if(f==1) for(i=1; i<=t+1; i++)ans1+=9*pow(10,double(t-i));
		else {
			long long t1=0;
			for(i=1; i<=f-1; i++)t1+=a[i]*quickmi(10,f-i-1);
			ans-=t1;
			ans1+=quickmi(10,f-1);
			for(i=t-1; i>=f; i--)ans1+=9*quickmi(10,i);
			ans1+=8*quickmi(10,f-1);
		}
	}
	long long snum=gcd(ans1,ans);
	cout<<ans/snum<<'/'<<ans1/snum;
	return 0;
}