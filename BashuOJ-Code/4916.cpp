#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
char a[10],b[10];
int tianshu[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool runnian(int y)
{
	if(y%4==0&&y%100!=0)return 1;
	if(y%400==0)return 1;
	else return 0;
}
void update(int y,int m,int d)
{
	int a1=y/1000,a2=y/100%10,a3=y/10%10,a4=y%10;
	int b1=m/10,b2=m%10;
	int c1=d/10,c2=d%10;
	a[0]=a1+'0';a[1]=a2+'0';
	a[2]=a3+'0';a[3]=a4+'0';
	a[4]=b1+'0';a[5]=b2+'0';
	a[6]=c1+'0';a[7]=c2+'0';
	return;
}
int main(){
	//freopen("date.in","r",stdin);
	//freopen("date.out","w",stdout);
	scanf("%s%s",&a,&b);
	int cnt=0;
	if(strcmp(a,b)==0)
	{
		bool bj=0;
		for(int i=0;i<=3;i++)if(a[i]!=a[7-i]){bj=1;break;}
		if(bj==0)printf("1");
		else printf("0");
	}
	else
	{
		int y=1000*(a[0]-'0')+100*(a[1]-'0')+10*(a[2]-'0')+(a[3]-'0'),m=10*(a[4]-'0')+(a[5]-'0'),d=(a[6]-'0')*10+(a[7]-'0');
		while(1)
		{
		bool bj=0;
		for(int i=0;i<=3;i++)if(a[i]!=a[7-i]){bj=1;break;}
		if(bj==0)cnt++;
		if(strcmp(a,b)==0)break;
		if(m==1&&d==tianshu[1])
		{
			m++,d=1;
			if(runnian(y))tianshu[2]=29;
			else tianshu[2]=28;
		}
		else if(m==12&&d==tianshu[m])y++,m=1,d=1;
		else if(d==tianshu[m])m++,d=1;
		else d++;
		update(y,m,d);
		}
		printf("%d",cnt);
	}
	return 0;
}
