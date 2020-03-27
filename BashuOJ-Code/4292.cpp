#include<iostream>
using namespace std;
int n,i,j,k,x,y,f,c,s=0;
int main(){
	cin>>n>>i>>j;
  x=i;
  y=j;
  c=n;
  if(x>n/2)x=n-x+1;
  if(y>n/2)y=n-y+1;
  if(x>y)x=y;
  for(k=1;k<x;k++)
  {
  	s=s+(c-1)*4;
  	c-=2;
  }
  y=s;
  if(x==i)s=y+j-x+1;
  if(x==n-j+1)s=y+c+i-x;
  if(x==n-i+1)s=y+(c-1)*2+n-j+1-x+1;
  if(x==j&&i!=x)s=y+(c-1)*3+n-i+1-x+1;
  cout<<s;
	return 0;
}
