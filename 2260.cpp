#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int Max=0,Min=0,t,l,n;
int main()
{ 
	scanf("%d%d",&l,&n);        
	for(int i=1;i<=n;i++)        
	{       
		scanf("%d",&t);       
		Max=max(Max,max(t,l-t+1));       
		Min=max(Min,min(t,l-t+1));        
	}        
		printf("%d %d",Min,Max); 
		return 0;
}