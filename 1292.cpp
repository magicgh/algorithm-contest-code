#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int n,cnt=0;
int bj[30]={0};
int main(){
	cin>>n;
	bj[1]=1;
	for(int i=1;i<=n;i++)
	{
		char a,b,c;
		cin>>a>>c>>b; 
		bj[a-'a'+1]=bj[b-'a'+1];
	}
	for(int i=1;i<=26;i++)if(bj[i]==1)cout<<char(i+96)<<' ',cnt++;
	if(!cnt)puts("none");
	return 0;
}
