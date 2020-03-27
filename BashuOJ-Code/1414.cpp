#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int n,a[100005]={0},cnt=0;
int main(){
	scanf("%d",&n);
    for(int i=1;;i++)
    {
    	if(cnt==n)break;
    	if(i%7==0)
    	{
    		a[++cnt]=i;
    		continue;
		}
		if(i%10==7)a[++cnt]=i;
	}
	for(int i=1;i<=cnt;i++)printf("%d\n",a[i]);
	return 0;
}
