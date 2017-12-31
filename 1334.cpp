#include<iostream>
using namespace std;
int main(){
	int m,n,i,j,k=0,a[105],b[105]={0};
	while(cin>>n>>m)
{
	for(i=1;i<n;i++)a[i]=i+1;
	a[n]=1;
        for(i=1;i<=n;i++)cin>>b[i];
	j=n;
	for(i=0;i<n;i++){
		for(k=1;k<m;k++) j=a[j];
		cout<<a[j]<<' ';
                  m=b[a[j]];
		a[j]=a[a[j]];
		
	}cout<<endl;
}
	return 0;
}
