#include<iostream>
using namespace std;
long long n;
int main()
{
   int n;
   for(cin>>n;n!=0;cin>>n)
   {
   	if(n*n%2==0)cout<<"Alice"<<endl;
   	else cout<<"Bob"<<endl;
   }
return 0;
}
