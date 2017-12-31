#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
int t,m,n,a[105]={0},sum=0,maxn=-0x7fffffff;
bool bj=0,used[105];
void dfs(int k,int last,int len)
{
	int i,j;
	if(k==m)
	{
		bj=1;
		return;
	}
	if(len==0)
	{
		for(i=1;i<=n;i++)
		{
			if(used[i]==0)
			{
			used[i]=1;
			break;
		    }
		}
		dfs(k+1,i,t-a[i]);
	}
		for(i=last+1;i<=n;i++)
	{
	if(!used[i]&&a[i]<=len)
	{
		used[i]=1;
		dfs(k,i,len-a[i]);
		used[i]=0;
		j=i;
		while(i<n&&a[i]==a[j])i++;
		if(i==n)return;
	}
	}
	return;
}
bool cmp(int a,int b)
{
	return a>b;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=maxn;i<=sum;i++)
	{
		if(sum%i==0)
		{
		
		bj=0;
		t=i;
		m=sum/t; 
		memset(used,0,sizeof(used));
		used[1]=1;
		dfs(1,1,t-a[1]);
		if(bj)
		{
			cout<<i;
			break;
		}
	}
	}
	return 0;
}
