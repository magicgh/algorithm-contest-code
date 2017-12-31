#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int f,t,len,dir=0,cnt=0;
string s;
int main(){
	cin>>f>>t>>len>>s;
	while(1)
	{
	dir=-1;
	for(int i=len-1;i>=0;i--)
	{
		if((int(s[i])-96)<t+i-len+1){dir=i;break;}
	}
	if(dir==-1||cnt==5)break;
	else
	{
		s[dir]=int(s[dir])+1;
		for(int i=dir+1;i<=len-1;i++)s[i]=int(s[i-1])+1;
	}
	for(int i=0;i<=len-1;i++)cout<<s[i];
	cout<<endl;
	++cnt;	
}
	return 0;
}
