#include<iostream>
using namespace std;
int main(){
	int n,a[10][10],i,j,k,s[2]={0},v5,v,v1,v2,v4;
	int s1[9]={0};
	cin>>n;
	for(i=1;i<=n;i++)
	{
		v5=0;v4=0;
	   for(j=1;j<=9;j++)
	      for(k=1;k<=9;k++)cin>>a[j][k];
       for(j=1;j<=9;j++){
	      s[1]=0;s[2]=0;v=1;v2=1;
	      for(k=1;k<=9;k++){
	   	  s[1]=s[1]+a[j][k];
	   	  s[2]=s[2]+a[k][j];
	   	  v=v*a[j][k];
	   	  v2=v2*a[k][j];
	      }
	      if(s[1]==45&&s[2]==45&&v==362880&&v2==362880)v5++;
	   }for(j=1;j<=9;j++)s1[j]=0;
	   for(j=1;j<=9;j++)
	   for(k=1;k<=9;k++){
	   	   if(j>=1&&j<=3&&k>3&&k<7)s1[2]=s1[2]+a[j][k];
	   }
	   
	   if(s1[2]==45)v4=9;
	   if(v5==9&&v4==9)cout<<"Right"<<endl;
	   else cout<<"Wrong"<<endl;
    }
	return 0;
}