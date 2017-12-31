#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <algorithm>
using namespace std;
char Old[15][15],Ans[15][15],Temp[15][15],Mark=0;
int n;
bool Check(int Status)
{
	int i,j,bj=0;
	for(i=1;i<=n;i++)
	 for(j=1;j<=n;j++)
	 {
	 	if(Temp[i][j]!=Ans[i][j]){bj=1;break;}
	 }
	 if(bj==0){cout<<Status<<endl;Mark=1;return 1;}
	 else return 0;
}
void Turn_90()
{
	int i,j;
	for(i=1;i<=n;i++)
	 for(j=1;j<=n;j++)
	 {
	 	Temp[i][j]=Old[n-j+1][i];
	 }
	return;
}
void Turn_180()
{
	int i,j;
	for(i=1;i<=n;i++)
	 for(j=1;j<=n;j++)
	 {
	 	Temp[i][j]=Old[n-i+1][n-j+1];
	 }
	 return;
}
void Turn_270()
{
	int i,j;
	for(i=1;i<=n;i++)
	 for(j=1;j<=n;j++)
	 {
	 	Temp[i][j]=Old[j][n-i+1];
	 }
	 return;
}
void Reflect()
{
	int i,j;
	for(i=1;i<=n;i++)
	 for(j=1;j<=n;j++)
	 {
	 	Temp[i][j]=Old[i][n-j+1];
	 }
	 return;
}
void Clean()
{
    memcpy(Old,Temp,sizeof(Temp));
	memset(Temp,0,sizeof(Temp));
	return;
}
bool Combine()
{
	Reflect();
	Clean();
	Turn_90();
	if(Check(5))return 1;
	Clean();
	Turn_90();
	if(Check(5))return 1;
	Clean();
	Turn_90();
	if(Check(5))return 1;
	return 0;	
}
int main()
{
int i,j,bj=0;
cin>>n;
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)cin>>Old[i][j];
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
cin>>Ans[i][j];
if(Ans[i][j]!=Old[i][j]&&bj==0)bj=1;
}
Turn_90();
if(Check(1))return 0;
Turn_180();
if(Check(2))return 0;
Turn_270();
if(Check(3))return 0;
Reflect();
if(Check(4))return 0;
if(Combine())return 0;
if(bj==0){cout<<6;return 0;}
else cout<<7;
return 0;
}
