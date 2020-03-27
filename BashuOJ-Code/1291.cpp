#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#define MAXN 0x7fffffff
using namespace std;
int A,B,dep,k1,k2,tmp[105],ans[105];
bool bj=0;
int gcd(int a,int b)
{
	if(b==0)return a;
	else return gcd(b,a%b);
}
void dfs(int x,int y,int k)
{
	if(k==dep+1)return;
	if(k==dep&&x==1&&y>tmp[k-1])
	{
		tmp[k]=y;
	   if((!bj)||tmp[k]<ans[k])
	   {
	   for(int i=1;i<=k;i++)ans[i]=tmp[i];
	   	bj=1;
	   }
	   return;
	}
	int Min=max(y/x,tmp[k-1])+1;
	int Max=min(MAXN,(dep-k+1)*(y/x));
    if(bj)Max=min(tmp[dep]-1,Max);
    for(int i=Min;i<=Max;i++)
    {
    	tmp[k]=i;
    	dfs((x*i-y)/gcd(x*i-y,y*i),(y*i)/gcd(x*i-y,y*i),k+1);
	}
    return;
}
int main(){
	cin>>A>>B;
	memset(tmp,0,sizeof(tmp));
	memset(ans,0,sizeof(ans));
	int k;
	k=gcd(A,B);
    A/=k,B/=k;
	tmp[0]=1,dep=1;
	while(1)
	{
		dep++;
		dfs(A,B,1);
		if(bj)
		{
		for(int i=1;i<=dep;i++)cout<<ans[i]<<' ';
		break;
		}
	}
	
	return 0;
}
