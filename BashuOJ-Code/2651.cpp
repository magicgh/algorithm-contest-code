#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int N,C,P,cnt=0;
struct node
{
	int x,y,z;
}data[1000005];	
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main(){
	int x,y,z;
	C=GetInt();
	N=GetInt();
	for(int i=1;i<=N;i++)
	{
	x=GetInt();
	y=GetInt();
	z=GetInt();
	data[i]=(node){x,y,z};
	}
	P=GetInt();
	for(int i=1;i<=N;i++)
		if(P>=data[i].x&&P+1<=data[i].y)cnt++;
	printf("%d",cnt); 
	return 0;
}