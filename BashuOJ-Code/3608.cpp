#include<iostream>
using namespace std;
int main(){
    long long m,n,i,y,z=1; 
    while(cin>>m>>n)
    {
    
    for(i=1;i<=m&&i<=n;i++)
{
    if(m%i==0&&n%i==0)
    z=i;
}
    m=m/z;
    y=m*n;
    cout<<y<<endl;
}    
	    return 0;
}