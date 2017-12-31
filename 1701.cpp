#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int map[210][210],f1[210][210],f2[210][210],Max=-0x7ffffff;
char t;
int n;
int main(){
	memset(map,0,sizeof(map));
	memset(f1,0,sizeof(f1));
	memset(f2,0,sizeof(f2));
	cin>>n;
	for(int i=1;i<=n;i++)
	   for(int j=i;j<=2*n-i;j++)
	   {
	   	cin>>t;
	   	if(t=='-')map[i][j]=1,f1[i][j]=1,f2[i][j]=1;
	   }
	   for(int i=1;i<=n;i++)
        for(int j=i;j<=2*n-i;j++)
        {
		if(map[i][j]==1)
		{
		f1[i][j]=min(min(f1[i-1][j-1],f1[i-1][j]),f1[i-1][j+1])+1;
		Max=max(Max,f1[i][j]); 
	}
	}
	for(int i=n;i>=1;i--)
        for(int j=i;j<=2*n-i;j++)
        {
		if(map[i][j]==1)
		{
		f2[i][j]=min(min(f2[i+1][j-1],f2[i+1][j]),f2[i+1][j+1])+1;
		Max=max(Max,f2[i][j]); 
	}
	}
	cout<<Max*Max;
	return 0;
}
