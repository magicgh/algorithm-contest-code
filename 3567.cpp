#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int s1[105]={0},s2[6]={0},s3[105]={0},n;
char t[35];
int main(){
	cin>>n;
	int t1=n,t2=0,t3=0;
	for(int i=1;i<=t1;i++)s1[t1-i+1]=i;
	for(int i=1;i<=n;i++)cin>>t[i];
	for(int i=1;i<=n;i++)
	{
		if(t[i]=='A')s3[++t3]=s1[t1--];
		if(t[i]=='B')
		{
				if(t2<5)s2[++t2]=s1[t1--];
			else 
			{
				cout<<"No";return 0;
			}
		}
		if(t[i]=='C')
		{
			if(t2<=0)
			{
				cout<<"No";return 0;
			}
			else 
			{
				s3[++t3]=s2[t2--];
			}
		}
	}
	cout<<"Yes"<<endl;
	for(int i=1;i<=t3;i++)cout<<s3[i]<<endl;
	return 0;
}