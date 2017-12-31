#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int N,Ans;
bool vst[10001];
int prt[10001];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
inline int Getfa(int x)
{
	if(prt[x]==x)return x;
	return prt[x]=Getfa(prt[x]);
}
int main(){
	N=GetInt();
	for(int i=1;i<=10001;i++)prt[i]=i;
	for(int i=1;i<=N;i++)
	{
		int f1=Getfa(GetInt()),f2=Getfa(GetInt());
		if(f1!=f2){if(f1>f2)swap(f1,f2);prt[f1]=f2;}
		vst[f1]=1;
	}
	for(int i=1;i<=10001;i++)
	if(!vst[i]){printf("%d",i-1);break;}
	return 0;
}
