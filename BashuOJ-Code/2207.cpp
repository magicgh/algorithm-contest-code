#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iomanip>
#include<algorithm>
using namespace std;
int main()
{
string str1,str2;
cin>>str1>>str2;
int a[105],b[105],i,j;
long long num=0;
memset(a,0,sizeof(a));
memset(b,0,sizeof(b));
a[0]=str1.length();
b[0]=str2.length();
for(i=1;i<=a[0];i++)a[i]=str1[a[0]-i]-'0';
for(i=1;i<=b[0];i++)b[i]=str2[b[0]-i]-'0';
for(i=1;i<=a[0];i++)
  for(j=1;j<=b[0];j++)
  {
  num+=a[i]*b[j];
  }
cout<<num;
return 0;
}
