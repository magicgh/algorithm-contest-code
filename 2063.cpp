/*
ID: baymax01
PROG: namenum
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
char Mem[10][3]=
{
	{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','R','S'},{'T','U','V'},{'W','X','Y'}
};
string num,dict[25000],Output[25000];
bool t=0;
int main(){
    int m=0,i,j,p=0;
	//freopen("namenum.in","r",stdin);
	//freopen("namenum.out","w",stdout);
	//freopen("dict.txt","r",stdin);
	for(i=0;i<24829;i++)cin>>dict[i];
	cin>>num;
	for(i=0;i<24829;i++)
	{
		if(num.length()!=dict[i].length())continue;
		bool bj=0;
		for(j=0;j<dict[i].length();j++)
		{
			if(!(dict[i][j]==Mem[num[j]-'0'-2][0]||dict[i][j]==Mem[num[j]-'0'-2][1]||dict[i][j]==Mem[num[j]-'0'-2][2])){bj=1;break;}
		}
		if(bj==0){Output[++p]=dict[i];t=1;}
	}
	sort(Output+1,Output+p+1);
	for(i=1;i<=p;i++)cout<<Output[i]<<endl;
	if(t==0)cout<<"NONE"<<endl;
	return 0;
}