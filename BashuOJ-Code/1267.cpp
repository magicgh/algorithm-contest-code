/*
ID: baymax01
PROG: text
LANG: C++
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <cassert>
#include <cctype>
#include <queue>
using namespace std;
int k,cnt=0,temp[1005]={0},A[1005]={0};
string a;
void Check();
void init();
void Search()
{
	int i;
	for(i=1;i<=temp[0];i++)
	{
		temp[i]+=A[i]+A[A[0]-i+1];
		if(temp[i]>=k)
		{
			temp[i+1]+=temp[i]/k;
			temp[i]%=k;	
		}
	}
	while(temp[temp[0]+1]>0)temp[0]++;
	Check();
	return;
}
void Check()
{
	int i,bj=0;
	for(i=1;i<=temp[0]/2;i++)if(temp[i]!=temp[temp[0]-i+1]){bj=1;break;}
	cnt++;
	if(cnt>30){cout<<"Impossible";return;}
	if(bj==0){cout<<cnt;return;}
	if(bj==1)init();
	return;
}
void init()
{
	int i,str=temp[0];
	memset(A,0,sizeof(A));
	for(i=1;i<=str;i++)A[i]=temp[i];
	memset(temp,0,sizeof(temp));
	A[0]=temp[0]=str;
	Search();
}
int main()
{
	cin>>k>>a;
	int i,bj=0;
	A[0]=a.length();
	memset(temp,0,sizeof(temp));
	temp[0]=A[0];
	for(i=1;i<=A[0];i++)
	{
	if(a[A[0]-i]>='A'&&a[A[0]-i]<='Z')A[i]=a[A[0]-i]-'A'+10;
	else 
	 A[i]=a[A[0]-i]-'0';
	}
	Search();
	return 0;
}