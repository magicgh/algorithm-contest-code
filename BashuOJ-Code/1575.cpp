#include<iostream>
using namespace std;
long long CP(long long n)
{
  if(n==1)return 0;
  else if(n==2)return 1;
  else
  return(n-1)*(CP(n-2)+CP(n-1));
}
int main(){
    long long n;
    cin>>n;
    cout<<CP(n);
    //system("pause");
    return 0;
}
