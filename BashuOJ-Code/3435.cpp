#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
char s[10005],dict[105];
int main(){
	gets(s);
	int n=strlen(s);
	for(int i=1;i<=26;i++)cin>>dict[i];
	for(int i=0;i<=n;i++)
	{
	if(s[i]>='A'&&s[i]<='Z')cout<<dict[s[i]-'A'+1];
	else cout<<' ';
	}
	return 0;
}
