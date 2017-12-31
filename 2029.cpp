#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
	string a;
	bool bbj=0;
	cin>>a;
	int len=a.length();
	for(int i=0;i<len;i++)
	{ 
		if(len%(i+1)==0&&a[0]==a[i+1])
		{
			bool bj=0;
			for(int j=0;j+i+1<len;j++)if(a[j]!=a[j+1+i]){bj=1;break;}
			if(bj==0){bbj=1;cout<<i+1<<endl;break;}
		}
	}
	if(bbj==0)cout<<len;
	return 0;
}
