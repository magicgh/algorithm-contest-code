#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm> 
using namespace std;
int N,NN=0;
int a[50005],b[50005];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct BigInt
{
	int h[105];
	BigInt(){memset(h,0,sizeof(h));h[0]=1;h[1]=0;}
	inline BigInt Init()
	{
		BigInt tmp;
		tmp.h[0]=1;
		tmp.h[1]=1;
		return tmp;
	}
	inline BigInt operator +(BigInt q)
	{
		BigInt ans;
		ans.h[0]=max(this->h[0],q.h[0]);
		for(int i=1;i<=ans.h[0];i++)
		{
		ans.h[i]+=this->h[i]+q.h[i];
		if(ans.h[i]>=10)
		{
			ans.h[i+1]+=ans.h[i]/10;
			ans.h[i]%=10;
		}
		}
		while(ans.h[ans.h[0]+1]>0)ans.h[0]++;
		return ans;
	}
	
	inline BigInt operator -(BigInt q)
	{
		BigInt ans; 
		ans.h[0]=this->h[0];
		for(int i=1;i<=ans.h[0];i++)
		{
		if(this->h[i]<q.h[i])
		{
			this->h[i+1]--;this->h[i]+=10;
		}
		ans.h[i]=this->h[i]-q.h[i];
		}
		while(ans.h[ans.h[0]]==0&&ans.h[0]>1)ans.h[0]--;
		return ans;
	}
	inline void Out()
	{
		for(int i=this->h[0];i>=1;i--)printf("%d",this->h[i]);
	}
};
struct bit
{
	BigInt C[6][50005];
	inline int Lowbit(int x){return x&(-x);}
	inline void Modify(int cnt,int x,BigInt d)
	{
	for(int i=x;i<=N;i+=Lowbit(i))C[cnt][i]=C[cnt][i]+d;
	}
	inline BigInt Sum(int cnt,int x)
	{
	BigInt Ans;
	for(int i=x;i>0;i-=Lowbit(i))Ans=Ans+C[cnt][i];
	return Ans;
	}
};
bit tr;
BigInt ans;
int main(){
		N=GetInt(); 
		for(int i=1;i<=N;i++)a[i]=b[i]=GetInt();
		sort(b+1,b+N+1); 
		NN=unique(b+1,b+N+1)-(b+1);
		BigInt tt=tt.Init();
		for(int i=1;i<=N;i++)
		{
		a[i]=lower_bound(b+1,b+NN+1,a[i])-b;
		tr.Modify(1,a[i],tt);
		for(int j=2;j<=5;j++)tr.Modify(j,a[i],tr.Sum(j-1,a[i]-1));
		}
		for(int i=5;i<=N;i++)ans=ans+tr.Sum(5,i)-tr.Sum(5,i-1);
		ans.Out();
	return 0;
}