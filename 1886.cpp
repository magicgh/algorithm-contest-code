#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#define MAXN 0x7fffffff
using namespace std;
int m,n,Ans=MAXN;
int MinVol(int k)
{
	return k*(k+1)*k*(k+1)*0.25;
}
void dfs(int k,int r,int h,int s,int v)
{
	int sum=0;
	if(k==0&&v==0){Ans=min(Ans,s);return;}
	for(int i=1;i<=k;i++)sum+=(r-i)*(r-i)*(h-i);
	if(s+2*(v/r)>=Ans||v<MinVol(k)||sum<v)return;
	for(int i=r-1;i>=k;i--)
	  for(int j=h-1;j>=k;j--)dfs(k-1,i,j,s+2*i*j,v-i*i*j);
	return;
}
int main(){
	int Rad,Squ,Vol,H8t;
	cin>>n>>m;
	for(Rad=m;Rad<=sqrt(n);Rad++)
	   for(H8t=n/(Rad*Rad);H8t>=m;H8t--)
     {
	   Squ=Rad*Rad+2*Rad*H8t;
	   Vol=n-Rad*Rad*H8t;
	   dfs(m-1,Rad,H8t,Squ,Vol);
	 }	
	 cout<<Ans;
	return 0;
}
