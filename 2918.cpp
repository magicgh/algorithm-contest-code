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
char ch[2005];
int m,len,ans,base[2005];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	scanf("%s",ch),m=getint(),len=strlen(ch);
	base[len-1]=1;
	for(ri i=len-1;i>=0;i--)ans=(ans+(((ch[i]-'A')%m)*(base[i]%m))%m)%m,base[i-1]=(base[i]*26)%m;
	if(ans==0){printf("0 0\n");return 0;}
	for(ri i=0;i<len-1;i++)
		for(ri j=i+1;j<len;j++)
		{
			int tmp=(ans-((ch[i]-'A')*base[i])%m-((ch[j]-'A')*base[j])%m+m)%m;
			tmp=(tmp+((ch[i]-'A')*base[j])%m+((ch[j]-'A')*base[i])%m)%m;
			if(tmp==0)
			{
				printf("%d %d\n",i+1,j+1);
				return 0;
			}
		}
	printf("-1 -1\n");
	return 0;
}

