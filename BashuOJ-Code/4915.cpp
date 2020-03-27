#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int n,a,b,ans=0x7fffffff;
int main(){
	//freopen("pencil.in","r",stdin);
	//freopen("pencil.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=3;i++)
	{
		scanf("%d%d",&a,&b);
		if(n%a==0)ans=min(ans,(n/a)*b);
		if(n%a!=0)ans=min(ans,((n/a)+1)*b);
	}
	printf("%d",ans);
	return 0;
}
