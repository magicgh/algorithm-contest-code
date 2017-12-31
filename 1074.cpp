#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int Mod=1e4+7;
int n,Hash[Mod],Ans;
string a,b,a1[15],b1[15];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int RK_Hash(string s)
{
	int key=0;
	for(ri i=0;i<s.length();i++)key=(key*301+s[i])%Mod;
	return key;
}
bool DFS(string s,int k)
{
	if(s==b)return 1;
	if(k>Ans)return 0;
	for(ri i=1;i<=n;i++)
		for(ri j=0;j<s.length();j++)
		{
			int pos=s.find(a1[i],j);
			if(pos==string::npos)break;
			string s1=s;
			j=pos;
			s1.replace(pos,a1[i].length(),b1[i]);
			int key=RK_Hash(s1);
			if(Hash[key])continue;
			Hash[key]=1;
			if(DFS(s1,k+1))return 1;
		}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>a>>b;
	while(cin>>a1[++n])cin>>b1[n];
	for(Ans=1;Ans<=10;Ans++)
	{
		memset(Hash,0,sizeof(Hash));
		if(DFS(a,1))break;
	}
	if(Ans<=10)cout<<Ans<<endl;
	else cout<<"NO ANSWER!\n";
	return 0;
}
