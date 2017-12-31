#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<climits>
using namespace std;
bool vst[10005];
int a[10005],pos[10005],ans=0;
int n,TotalMin=INT_MAX,b[10005];
int main(){
	while(scanf("%d",&n)&&n!=0)
	{
		memset(a,0,sizeof(a));
		memset(pos,0,sizeof(pos));
		memset(b,0,sizeof(b));
		memset(vst,0,sizeof(vst));
		ans=0,TotalMin=INT_MAX;
		for(int i=1;i<=n;i++)
		{
		scanf("%d",&a[i]);pos[a[i]]=i;ans+=a[i];
		TotalMin=a[i]<TotalMin?a[i]:TotalMin;
		}
		memcpy(b,a,sizeof(a));
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			if(!vst[i])
			{
			int len=1,Min=b[i],j=a[i];vst[i]=1;
			while(!vst[pos[j]])
			{
				len++;
				vst[pos[j]]=1;
				Min=min(Min,j);
				j=a[pos[j]];
			}
			if(len==1)ans-=b[i];
			else ans+=min((len-2)*Min,TotalMin*(len+1)+Min);
		}
		}
		printf("%d\n",ans);
	}
	return 0;
}

