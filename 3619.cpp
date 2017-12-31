#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
	int a,b,c,d,e=0;
	while(cin>>a>>b>>c>>d&&a!=-1&&b!=-1&&c!=-1&&d!=-1)
	{
		for(int j=d+1;;j++)
		{
			if((j-a)%23==0&&(j-b)%28==0&&(j-c)%33==0)
			{printf("Case %d: the next triple peak occurs in %d days.\n",++e,j-d);break;}
		}
	}
	return 0;
}
