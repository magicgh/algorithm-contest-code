#include<iostream>
using namespace std;
int s=0;
int B(int n)
{
  int i;
  s++;
  for(i=1;i<=n/2;i++)B(i); 
}
int main()
{
    int n;
    cin>>n;
    B(n);
    cout<<s;
   // system("pause");
    return 0;
}
