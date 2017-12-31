#include<iostream>
#include<cstring>
using namespace std;
int a[3][10005];
void Output()
{
	int i,j;
	for(i=5;i>=0;i--)
	  for(j=1;j<=3;j++)cout<<a[j][i];
	  cout<<' ';
	  for(i=1;i<=3;i++)
	  for(j=5;j>=0;j--)cout<<a[i][j];
	  return;
}
void Binary(int n,int js)
{
	 int i=0,j;
    while(n!=0)
      { 
         a[js][i]=n%2;
         i++;
         n=n/2;
     }
    if(i<5)for(j=i;j<=5;j++)a[js][j]=0;
	return;
}
int main()
{
memset(a,0,sizeof(a));
string t;
int t1,t2,t3;
	cin>>t;
int n0=t.length();	
t1=10*(t[0]-'0')+(t[1]-'0');
t2=10*(t[3]-'0')+(t[4]-'0');
t3=10*(t[6]-'0')+(t[7]-'0');
Binary(t1,1);
Binary(t2,2);
Binary(t3,3);
Output();
return 0;
}
