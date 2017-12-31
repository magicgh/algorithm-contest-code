#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
int Next[1000005],len,cnt=0,alen=0;
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
void DFS(int k)//BC写法 
{
	if(Next[k]==1)return;
	DFS(Next[k]);
	printf("%d ",Next[k]-1);//i是从Next[i]开始配对，前面已经与Next[i]-1个已匹配
}
int main(){
	ios::sync_with_stdio(false);
	while(cin>>s)
	{
		alen=0;
		s=" "+s;
		len=s.length()-1;
		Find_next();
		DFS(len+1);
		printf("%d\n",len);//自己是自己的子串 
	}
	return 0;
}