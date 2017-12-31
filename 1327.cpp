#include<iostream>
using namespace std;
long long used[100]={0},n,a[100]={0},c[100]={0},i;
string s;
void PL(int k)
{
     int i;
   if(k>n)
   {for(i=1;i<k;i++)cout<<a[i]<<" ";cout<<endl;return;}
      for(i=1;i<=n;i++)
      {
      if(used[i]==0)
      {
      a[k]=c[i];
      used[i]=1;
      PL(k+1);
      used[i]=a[k]=0;
      }
      }
      }
int main()
{   cin>>s;
    n=s.length();
    for(i=1;i<=n;i++)c[i]=s[i-1]-'0';
    PL(1);
return 0;
}