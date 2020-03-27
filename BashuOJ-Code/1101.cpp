#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int a[15]={0},total=0,t;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
int main(){
	for(int i=1;i<=6;i++)a[i]=getint();
	total=a[6]+a[5]+a[4];
	a[1]-=11*a[5],a[2]-=a[4]*5;
	if(a[2]<0)a[1]+=a[2]*4,a[2]=0;
	total+=a[3]/4,a[3]%=4;
	if(a[3]==3){total++;if(a[2]!=0){a[2]--;a[1]-=5;}else a[1]-=9;}
	if(a[3]==2)total++,t=min(a[2],3),a[2]-=t,a[1]-=18-t*4;
	if(a[3]==1)total++,t=min(a[2],5),a[2]-=t,a[1]-=27-t*4;
	if(a[2]>0)total+=a[2]/9,a[2]%=9;
	if(a[2]>0)total++,a[1]-=36-a[2]*4;
	if(a[1]>0)total+=a[1]/36+1;	
	printf("%d",total);
	return 0;
}