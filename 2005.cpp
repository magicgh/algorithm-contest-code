#include<iostream>
#include<algorithm>
using namespace std;
long long a[30005]={0},n,m,i;
int main()
{
	cin>>m>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
 int j=1,k=n,s=0;
	while(j<k)
	{
	 if(a[j]+a[k]<=m){j++;k--;} else k--;
	 s++;
}
  if(j==k)s++;
	cout<<s<<endl;
return 0;
}
