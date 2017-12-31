#include<iostream>
using namespace std;
int main()
{
 	long long  i,n,m,k,t=0;
 	cin>>n>>m>>k;
 	for(i=1;i<=100;i++)
		if(i<=m&&2*i<=n&&i*3+k<=n+m)t=i;
    cout<<t<<endl;
    //system("pause");
    return 0;
}
