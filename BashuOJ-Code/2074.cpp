/*
ID: baymax01
PROG: sprime
LANG: C++11              
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
int n,Ans[1005]={0},cnt=0;
bool PrimeNum(int m);
void Find(int m,int k)
{
    if(k>n)return;
    if(k==n)
    {
    	Ans[++cnt]=m;
    	return;
	}
	for(int i=0;i<=9;i++)if(PrimeNum(10*m+i))Find(10*m+i,k+1);
	
}
bool PrimeNum(int m)
{
	if(m==0||m==1)return 0;
	if(m==2)return 1;
	for(int i=2;i<=sqrt(m);i++)if(m%i==0)return false;
	return true;
	
}
int main(){
	//freopen("sprime.in","r",stdin);
	//freopen("sprime.out","w",stdout);
	cin>>n;
	for(int i=0;i<=9;i++)if(PrimeNum(i))Find(i,1);
	for(int i=1;i<=cnt;i++)cout<<Ans[i]<<endl;
	return 0;
}
