#include<iostream>
using namespace std;
long long n,m=9,i;
int main()
{
cin>>n;
for(i=1;m<n;i++)
{
 if(i%2==0)m*=9;
 else m*=2;
}
if(i%2==0)cout<<"Susan"<<endl;
else cout<<"Nic"<<endl;
return 0;
}