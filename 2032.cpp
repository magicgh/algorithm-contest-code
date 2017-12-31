#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
	int np,mark=0,n1,n2,money[25],mt=0;
	bool flag=0;
	cin>>np;
	memset(money,0,sizeof(money));
	string name[25],temp,t[25],a1,a2;
	for(int i=1;i<=np;i++)cin>>name[i];
	for(int i=1;i<=np;i++)
	{
		flag=0;
		cin>>a1;
		cin>>n1>>n2;
		if(n1==0)continue;
		mt=n1/n2;
		for(int k=1;k<=n2;k++)
		{
			cin>>a2;
			for(int m=1;m<=np;m++)
			{
			if(a1==name[m]&&flag==0){flag=1;money[m]=money[m]-n1+(n1-(mt*n2));}
			if(a2==name[m])money[m]+=mt;
			}
		}
	}
	for(int i=1;i<=np;i++)cout<<name[i]<<' '<<money[i]<<endl;
	return 0;
}
