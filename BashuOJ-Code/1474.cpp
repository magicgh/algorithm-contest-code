#include<iostream>
#include<cstring>
using namespace std;
long long f[501][501],v[501],g[501],t[501];
int main() {
	memset(f,0,sizeof(f));
	int a,b,i,j,n,k;
	cin>>a>>b>>n;
	for(i=1; i<=n; i++)cin>>t[i]>>v[i]>>g[i];
	for(i=1; i<=n; i++)
		for(j=a; j>=v[i]; j--)
			for(k=b; k>=g[i]; k--)
				if(f[j][k]<t[i]+f[j-v[i]][k-g[i]])f[j][k]=t[i]+f[j-v[i]][k-g[i]];
	cout<<f[a][b]<<endl;
	return 0;
}
