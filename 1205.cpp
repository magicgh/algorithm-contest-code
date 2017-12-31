#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int s[10005]={0};
void Work_2(int a);
void Work_1(int a,int b)
{
	int i;
	for(i=1;i<=s[0];i++)s[i]*=a;
	for(i=1;i<=s[0];i++)s[i+1]+=s[i]/10,s[i]%=10;
	while(s[s[0]+1]>0)
{
	s[0]++;
	s[s[0]+1]+=s[s[0]]/10;
	s[s[0]]%=10; 
}
	Work_2(b);
    return;
}
void Work_2(int a)
{
	int i;
	s[1]+=a;
	if(s[1]>=0)
	{
		for(i=1;i<=s[0];i++)
		{
			if(s[i]<10)break;
			else s[i+1]+=s[i]/10,s[i]%=10;
		}
	while(s[s[0]+1]>0)
{
	s[0]++;
	s[s[0]+1]+=s[s[0]]/10;
	s[s[0]]%=10; 
}
	}
	if(s[1]<0)
	{
		for(i=1;i<=s[0];i++)
		{
			if(s[i]>=0)break;
			else s[i]+=10,s[i+1]--;
		}
	while(s[s[0]]==0&&s[0]>1)s[0]--;
	}
	return;
}
int main(){
	string a;
	cin>>a;
	memset(s,0,sizeof(s));
	s[0]=1,s[1]=0;
	int Max=-1,m,n=a.length();
	for(int i=0;i<n;i++)
	{
	Max=max(Max,a[i]-'A');
	if(a[i]>=65&&a[i]<75)a[i]=a[i]-'A'+'0';
	else a[i]=a[i]-10;
	}
	Max++;
	for(int i=0;i<n;i++)
    {
      Work_1(Max,a[i]-'0');
      if(a[i]>='A')Work_2('0'-'A'+10);
	  }
    for(int i=s[0];i>=1;i--)cout<<s[i];
	return 0;
}