#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
struct Node
{
	int lb;
	int rb;
	int lr;
	int rr;
}Num[1005];
int main(){
	int n,i;
	cin>>n;
	char Pearl[1005],Temp[1005];
	cin>>Pearl;
	strcpy(Temp,Pearl);
	strcat(Pearl,Temp);
	Num[0].lr=Num[0].lb=0;
	for(i=1;i<=2*n;i++)
	{
		if(Pearl[i-1]=='r')Num[i].lr=Num[i-1].lr+1,Num[i].lb=0;
		else if(Pearl[i-1]=='b')Num[i].lb=Num[i-1].lb+1,Num[i].lr=0;
		else 
		{
		
		 Num[i].lr=Num[i-1].lr+1;
			Num[i].lb=Num[i-1].lb+1;
		}
	}
	Num[2*n].rr=Num[2*n].rb=0;
	for(i=2*n-1;i>=0;i--)
	{
		if(Pearl[i]=='r')Num[i].rr=Num[i+1].rr+1,Num[i].rb=0;
		else if(Pearl[i]=='b')Num[i].rb=Num[i+1].rb+1,Num[i].rr=0;
		else 
		{
			Num[i].rr=Num[i+1].rr+1;
			Num[i].rb=Num[i+1].rb+1;
		}
	}
	int m=-0x7fffffff;
	for(i=0;i<2*n;i++)m=max(m,max(Num[i].lb,Num[i].lr)+max(Num[i].rb,Num[i].rr));
	if(m>n)m=n;
	 cout<<m;
	return 0;
}
