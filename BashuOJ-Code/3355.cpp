#include<iostream>
#include<cstring>
using namespace std;
long long n;
int a[1000005];
void Binary()
{
	 int i=0,j;
    while(n!=0)
      { 
         a[i]=n%2;
         i++;
         n=n/2;
     }
       for(j=i-2;j>=0;j--)
       {
       	if(a[j]==0)cout<<4;
       	else cout<<7; 
}
return;
}
int main()
{
memset(a,0,sizeof(a));
cin>>n;
n++;
Binary();
return 0;
}
