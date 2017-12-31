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
char s1[105],s2[105],s3[105];
int mapping[35],gnippam[35];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int todigit(const char &ch){return ch-'A'+1;}
int main()
{
	scanf("%s%s%s",s1,s2,s3);
	if(strlen(s1)<26||strlen(s2)<26){printf("Failed");return 0;}
	for(ri i=0;i<strlen(s1);i++)
	{
		if(!mapping[todigit(s1[i])])mapping[todigit(s1[i])]=todigit(s2[i]);
		else if(mapping[todigit(s1[i])]&&mapping[todigit(s1[i])]!=todigit(s2[i])){printf("Failed");return 0;}
		if(!gnippam[todigit(s2[i])])gnippam[todigit(s2[i])]=todigit(s1[i]);
		else if(gnippam[todigit(s2[i])]&&gnippam[todigit(s2[i])]!=todigit(s1[i])){printf("Failed");return 0;}
	}
	for(ri i=1;i<=26;i++)if((!mapping[i])&&(!gnippam[i])){printf("Failed");return 0;}
	for(ri i=0;i<strlen(s3);i++)
	{
		if(!mapping[todigit(s3[i])]){printf("Failed");return 0;}
		else printf("%c",mapping[todigit(s3[i])]-1+'A');
	}
	return 0;
}

