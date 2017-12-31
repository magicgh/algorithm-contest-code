#include<iostream>
using namespace std;
int main()
{
int i,j,n,a[55]={0},b[55]={0};
char t;
cin>>n;
for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
   {
   	cin>>t;
   	if(t=='W')a[i]+=3;
   	if(t=='L')a[j]+=3;
   	if(t=='D'){a[i]++;a[j]++;}
   }
   for(i=1;i<=n;i++)b[i]=i;
   for(i=1;i<n;i++)
      for(j=i+1;j<=n;j++)if(a[i]<a[j]){swap(a[i],a[j]);swap(b[i],b[j]);}
     for(i=1;i<=n;i++)
     {
  if(a[i]==a[1])cout<<b[i]<<' ';
     else break;
	 }
return 0;
}
