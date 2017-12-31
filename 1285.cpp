#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int n,m=1,h=1,a[105][105]={{0},{0,1}};
int main(){
	cin>>n;
	m=1<<n;
	while(h<=m)
{
    for(int i=1;i<=h;i++)
    {
    	for(int j=1;j<=h;j++)
    	{
    		a[i][j+h]=a[i][j]+h;
    		a[i+h][j+h]=a[i][j];
    	    a[i+h][j]=a[i][j+h];
		}
	}	
	h*=2;
}
	for(int i=2;i<=m;i++)
	{
	
	  for(int j=1;j<=m;j++)
	  if(a[i][j]>j)
	  cout<<j<<'-'<<a[i][j]<<' ';
	  cout<<endl;
	  }
	return 0;
}
