#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
int Next[1000005],len,tmp,cnt=0;
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
	while(cin>>tmp,tmp!=0)
	{
		cin>>s;
		s=" "+s;
		len=s.length()-1;
		Find_next();
		printf("Test case #%d\n",++cnt);
		for(int i=1;i<=len;i++)
		{
			if(!Next[i])continue;
			int pos=i+1-Next[i+1];
			if(i%pos==0&&i/pos>1)printf("%d %d\n",i,i/pos);		
		}
		printf("\n");
	}
	return 0;
}