#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int N; 
int x,h1,m1,s1,h2,m2,s2,d;
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&x);
		if(x==0)
		{
		h1=GetInt();
		m1=GetInt();
		s1=GetInt();
		h2=GetInt();
		m2=GetInt();
		s2=GetInt();
		if(h1>=h2)h2+=24;
		if(m1>=m2)h2--,m2+=60;
		if(s1>=s2)m2--,s2+=60;
		int ans=(h2-h1)*3600+(m2-m1)*60+(s2-s1);
		while(ans>=86400)ans-=86400;
		printf("%d\n",ans);		
	}
		if(x==1)
		{
		h1=GetInt();
		m1=GetInt();
		s1=GetInt();
		d=GetInt();
		s1+=d;
		while(s1>=60)s1-=60,m1++;
		while(m1>=60)m1-=60,h1++;
		while(h1>=24)h1-=24;
		if(h1<10)printf("0%d:",h1);
		else printf("%d:",h1);
		if(m1<10)printf("0%d:",m1);
		else printf("%d:",m1);
		if(s1<10)printf("0%d\n",s1);
		else printf("%d\n",s1);
		}
}
	return 0;
}