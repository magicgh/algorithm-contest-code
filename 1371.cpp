#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
using namespace std;
int N;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	N=GetInt();
	if(N==6)printf("6"); 
	else if(N==7)printf("3"); 
	else if(N==8)printf("4"); 
	else if(N==9)printf("3");
	else if(N%5==0)printf("%d",N/5);
	else if(N%5==1)printf("%d",N/5+1);
	else if(N%5==2)printf("%d",N/5+2);
	else if(N%5==3)printf("%d",N/5+1);
	else if(N%5==4)printf("%d",N/5+2);
 return 0;
}
