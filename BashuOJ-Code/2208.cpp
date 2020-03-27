#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
long long m,t,u,f,d;
char c;
int main(){
	cin>>m>>t>>u>>f>>d;
	for(int i=1;i<=t;i++)
	{
		cin>>c;
		if(c=='u')m-=u+d;
		if(c=='f')m-=2*f;
		if(c=='d')m-=u+d;
		if(m<0)
		{
			cout<<i-1;
			break;
		}
	}
	return 0;
}
