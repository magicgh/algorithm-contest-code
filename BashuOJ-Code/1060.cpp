#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
char s1[30],s2[30],s3[30];
int n,order[30],num[30];
bool alpha[30],vst[30];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int todigit(char &c){return c-'A'+1;}
inline bool Check()//可行性剪枝 
{
	for(int i=n-1;i>=0;i--)
	{
		int t1=todigit(s1[i]),t2=todigit(s2[i]),t3=todigit(s3[i]);
		if(num[t1]!=-1&&num[t2]!=-1&&num[t3]!=-1)
		{
			if((num[t1]+num[t2])%n==num[t3]||(num[t1]+num[t2]+1)%n==num[t3])continue;//检验结果
			else return 0;
		}
		if(num[t1]!=-1&&num[t2]!=-1&&num[t3]==-1)//a+b
		{
			int n1=(num[t1]+num[t2])%n,n2=(num[t1]+num[t2]+1)%n;//判重 
			if(vst[n1]&&vst[n2])return 0;
			else continue;
		}
		if(num[t1]==-1&&num[t2]!=-1&&num[t3]!=-1)//c-b
		{
			int n1=(num[t3]-num[t2]+n)%n,n2=(num[t3]-num[t2]+n-1)%n;//判重
			if(vst[n1]&&vst[n2])return 0;
			else continue; 
		}
		if(num[t1]!=-1&&num[t2]==-1&&num[t3]!=-1)//c-a
		{
			int n1=(num[t3]-num[t1]+n)%n,n2=(num[t3]-num[t1]+n-1)%n;//判重
			if(vst[n1]&&vst[n2])return 0;
			else continue; 
		}
	}
	return 1;
}
inline bool Judge()
{
	int t=0;
	for(int i=n-1;i>=1;i--)
	{
		t+=num[todigit(s1[i])]+num[todigit(s2[i])];
		if(t%n!=num[todigit(s3[i])])return 0;
		t/=n;
	}
	t+=num[todigit(s1[0])]+num[todigit(s2[0])];
	if(t!=num[todigit(s3[0])])return 0;
	else return 1;	
}
void DFS(int k)
{	
	if(k==n+1)
	{
		if(Judge()){for(int i=1;i<=n;i++)printf("%d ",num[i]);exit(0);}
		else return;
	}
	if(!Check())return;	
	for(int i=n-1;i>=0;i--)
	{
		if(!vst[i])
		{
			vst[i]=1,num[order[k]]=i;
			DFS(k+1);
			vst[i]=0,num[order[k]]=-1;
		}
	}
}
int main()
{
	n=getint();
	memset(num,-1,sizeof(num));
	scanf("%s%s%s",s1,s2,s3);
	for(int i=n-1;i>=0;i--)
	{
		int t1=todigit(s1[i]),t2=todigit(s2[i]),t3=todigit(s3[i]);
		if(!alpha[t1])alpha[t1]=1,order[++order[0]]=t1;
		if(!alpha[t2])alpha[t2]=1,order[++order[0]]=t2;
		if(!alpha[t3])alpha[t3]=1,order[++order[0]]=t3;
	}
	DFS(1);
	return 0;
}
