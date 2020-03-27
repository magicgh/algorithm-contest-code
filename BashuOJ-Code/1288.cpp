#include<iostream>
#include<cstring>
using namespace std;
char a[105];
int main()
{
cin.getline(a, '.');
int n,str,j,k;
cin>>n;
char t1,t2,t3;
str=strlen(a);
for(int i=1;i<=n;i++)
{
	cin>>t1;
	if(t1=='D'||t1=='d')
	{
		cin>>t2;
		for(j=0;j<str;j++)
		{
			if(a[j]==t2)
			{
				str--;
			for(k=j;k<str;k++)a[k]=a[k+1];
			break;
			}
		}
	}
	if(t1=='I'||t1=='i')
	{
		cin>>t2>>t3;
		for(j=str-1;j>=0;j--)
		{
			if(a[j]==t2)
			{
				str++;
			for(k=str-1;k>=j;k--)
			a[k+1]=a[k];//cout<<k+1<<' '<<a[k+1]<<endl;}
			a[j]=t3;
			break;
		}
	}
}
	if(t1=='R'||t1=='r')
	{
		cin>>t2>>t3;
		for(int j=0;j<str;j++)
		{
			if(a[j]==t2)a[j]=t3;
		}
	}
	for(int i=0;i<str;i++)cout<<a[i];
}
//cout<<a[str]<<endl;
//for(int i=0;i<str;i++)cout<<a[i];
return 0;
}