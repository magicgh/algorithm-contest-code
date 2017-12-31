#include<iostream>
using namespace std;
string a;
int flag=0,i,n;
int main(){
  getline(cin,a);
  n=a.length();
  for(i=0;i<=n;i++)
  {  if((a[i]>=65&&a[i]<=90)||(a[i]>=97&&a[i]<=122))continue;
       else flag++;
  }
  cout<<flag-1;
    return 0;
}
