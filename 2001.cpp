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
using namespace std;
int p1,p2,p3;
char input[105],tmp,output;
string t;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool check(int i)
{
	return input[i-1]<input[i+1]&&((isalpha(input[i-1])&&
	isalpha(input[i+1]))||(isdigit(input[i-1])&&isdigit(input[i+1])));
}
int main()
{
	p1=getint(),p2=getint(),p3=getint();
	scanf("%s",input);
	for(ri i=0;i<strlen(input);i++)
	{
		if(input[i]!='-')printf("%c",input[i]);
		else if(input[i]=='-'&&check(i))
		{
				t.clear();
				for(int k=1;k<=int(input[i+1]-input[i-1]-1);k++)
				{
					output=char(input[i-1]+k);
					if(isalpha(output))
					{
						if(p1==1)tmp=tolower(output);
						else if(p1==2)tmp=toupper(output);
						else if(p1==3)tmp='*';
					}
					if(isdigit(output))
					{
						if(p1==3)tmp='*';
						else tmp=output;
					}
					for(ri j=1;j<=p2;j++)
					{
						if(p3==1)t.insert(t.end(),tmp);
						else if(p3==2)t.insert(t.begin(),tmp);
					}
				}
			string::iterator it;
			for(it=t.begin();it!=t.end();++it)printf("%c",*it);
		}
		else printf("%c",input[i]);
	}
	return 0;
}
