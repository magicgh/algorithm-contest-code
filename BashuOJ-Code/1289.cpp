#include<iostream>
#include<cstring>
using namespace std;
int n,w[1005],a[105][105],c[1005],f[1005],i,j;
void dg(int k)
{
	if(c[k])dg(c[k]);
	if(k==j)cout<<k<<endl;
	else cout<<k<<'-';
	return;
}
int main()
{
	cin>>n;
	memset(a,0,sizeof(a));
	memset(w,0,sizeof(w));
	memset(c,0,sizeof(c));
	memset(f,-1,sizeof(f));
	for(i=1; i<=n; i++){cin>>w[i];f[i]=w[i];}
	for(i=1; i<n; i++)
		for(j=i+1;j<=n; j++)cin>>a[i][j];
	for(i=2; i<=n; i++)
		for(j=1; j<i; j++)
			if(a[j][i]&&f[i]<f[j]+w[i]){f[i]=f[j]+w[i];c[i]=j;}
	int maxn=-0x7fffffff/2;
	for(i=1; i<=n; i++)
		if(f[i]>maxn)maxn=f[i],j=i;
	dg(j);
	cout<<"max="<<maxn<<endl;
	return 0; }