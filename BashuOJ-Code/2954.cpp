#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
int Next[1000005],len;
string s;
void Find_next()
{
	int i=1,j=0;
	Next[1]=0;
	while(i<=len)
	{
		if(j==0||s[i]==s[j])i++,j++,Next[i]=j;
		else j=Next[j];
	}
}
int main(){
	ios::sync_with_stdio(false);
	while(cin>>s,s!=".")
	{
		s=" "+s;
		len=s.length()-1;
		Find_next();
		int pos=len+1-Next[len+1];
		if(len%pos==0)printf("%d\n",len/pos);
		else puts("1");
	}
	return 0;
}