#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int a[20005]={0},n;
bool vst[20005]={0};
int main(){
	while(scanf("%d",&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		memset(vst,0,sizeof(vst));
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int len=0,cir=0;
		int Max=-0x7fffffff;
	    for(int i=1;i<=n;i++)
	    	if(!vst[i])
	    	{
	    		vst[i]=1;cir++;len=1;int j=a[i];
				while(!vst[j])vst[j]=1,len++,j=a[j];
				Max=max(Max,len);
			}
		printf("%d ",n-cir);
		if(Max==1)printf("%d\n",0);
		if(Max==2)printf("%d\n",1);
		if(Max>2)printf("%d\n",2);
	}
	return 0;
}
