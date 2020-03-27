#include<iostream>
using namespace std;
const int N=30;
long long a[N][N]={0},js=0,n,s=0;
char dir='d';
int main(){
	cin>>n;
	int x=1,y=n;
	while(js<n*n)
	{
		a[x][y]=++js;
		if(x==n-s&&y==n-s)dir='l';
		if(x==n-s&&y==s+1)dir='u';
		if(x==s+1&&y==s+1){dir='r';++s;}
		if(x==s&&y==n-s)dir='d';
		if(dir=='d')++x;
		if(dir=='u')--x;
		if(dir=='l')--y;
		if(dir=='r')++y;
	}
	for(int i=1;i<=n;i++)
	{
	 for(int j=1;j<=n;j++)
	 {
	 cout<<a[i][j]<<' ';
	 }
	 cout<<endl;
	 }
	return 0;
}