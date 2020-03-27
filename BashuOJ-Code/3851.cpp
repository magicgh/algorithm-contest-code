#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
long n,l,i,a[1000005]={0},num,j=1;
int main()
{
	scanf("%ld%ld",&n,&l);
	int k=l-1;
    long double AC=0,SUM=0;
  for(i=1;i<=n;i++){scanf("%d",&num);a[num]++;}
  while(k>j)
	{
		SUM+=a[j];
		AC+=a[k]*SUM;
		k--;
		j++;
	}
  cout<<fixed<<setprecision(2)<<(AC+SUM*(SUM-1)/2)/(n*(n-1)/2)<<endl;
return 0;
}
