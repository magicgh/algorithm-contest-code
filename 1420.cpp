#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
string s,word[1005];
long long len[1005],f[1005],Len,n,t;
int main(){
	memset(len,0,sizeof(len));
	memset(f,0,sizeof(f));
	cin>>s>>n;
	Len=s.length();
	s=' '+s;
	for(int i=1;i<=n;i++)
	{
		cin>>word[i];
		len[i]=word[i].length();
	}
	for(int i=1;i<=Len;i++)f[i]=0x7fffffff;
	f[0]=0;
	for(int i=1;i<=Len;i++)
	   for(int j=1;j<=n;j++)
	   {
	   if(len[j]<=i&&s.substr(i-len[j]+1,len[j])==word[j])f[i]=min(f[i],f[i-len[j]]+1);
	   }
    cout<<f[Len];
	return 0;
}
