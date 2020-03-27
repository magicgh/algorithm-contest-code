#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
//#define Debug
using namespace std;
const int IB=0x7fffffff;
const int IS=-0x7fffffff;
int n,m,a[105][105]={0},s[105][105];
void DP(int x1,int x2,int y1,int y2,int &Max,int &Min)
{
	 memset(a,0,sizeof(a));
	Max=IS,Min=IB;
	for(int i=x1;i<=x2;i++)
	   for(int j=i;j<=x2;j++)
	      for(int k=y1;k<=y2;k++)
	      {
	      	a[k][1]=IS,a[k][2]=IB;
	      	a[k][1]=max(a[k-1][1],0)+s[j][k]-s[i-1][k];
	      	a[k][2]=min(a[k-1][2],0)+s[j][k]-s[i-1][k];
	      	Max=max(Max,a[k][1]);
	      	Min=min(Min,a[k][2]);
 #ifdef Debug
	      	cout<<k<<":"<<Max<<' '<<Min<<endl;
	      	#endif
		  }
		  #ifdef Debug
		  cout<<"Total"<<":"<<endl;
		 cout<<x1<<' '<<y1<<","<<x2<<' '<<y2<<":"<<' '<<Max<<' '<<Min<<endl;
		 #endif
}
void dfs()
{
	int ans=IS,Min1,Min2,Max1,Max2;
	for(int i=2;i<=n;i++)
	{
		DP(1,i-1,1,m,Max1,Min1);
		DP(i,n,1,m,Max2,Min2);
		ans=max(ans,max(Max1*Max2,Min1*Min2));
		#ifdef Debug
		cout<<ans<<endl;
		#endif
	}
	for(int i=2;i<=m;i++)
	{
		DP(1,n,1,i-1,Max1,Min1);
		DP(1,n,i,m,Max2,Min2);
		ans=max(ans,max(Max1*Max2,Min1*Min2));
		#ifdef Debug
		cout<<ans<<endl;
		#endif
	}
	printf("%d",ans);
}
int main(){
	scanf("%d%d",&n,&m);
	memset(s,0,sizeof(s));
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=m;j++)scanf("%d",&a[i][j]),s[i][j]=s[i-1][j]+a[i][j];
	   #ifdef Debug
	   for(int i=1;i<=m;i++)cout<<s[1][i]<<' ';
	   #endif
	   dfs();
	return 0;
}
