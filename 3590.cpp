#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#define ri register int
#define ll long long
using namespace std;
char ch[15],s1[15],s2[15];
map<string,string>m;
string t;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{	
	while(true)
	{
		gets(ch);
		if(ch[0]=='\0')break;
		sscanf(ch,"%s %s",&s2,&s1);
		m[s1]=s2;
	}
	while(gets(ch))
	{
		if(!m.count(ch))printf("eh\n");
		else t=m[ch],printf("%s\n",t.c_str());
	}
	return 0;
}
