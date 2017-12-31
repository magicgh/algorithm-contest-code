#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
bool Hash[305][305];
int ans=0;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int X,Y,L;
int main(){
	X=GetInt();
	Y=GetInt();
	L=GetInt();
	int ax,ay,bx,by;
	for(int i=1;i<=L;i++)
	{
		ax=GetInt();
		ay=GetInt();
		bx=GetInt();
		by=GetInt();
		for(int j=ax;j<=bx;j++)
		for(int k=ay;k<=by;k++)if(!Hash[j][k])Hash[j][k]=1,ans++;
	}
	printf("%d",ans);
	return 0;
}
