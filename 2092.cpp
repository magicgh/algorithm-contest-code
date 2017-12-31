#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<limits>
using namespace std;
const double DOUBLE_MAX=(numeric_limits<double>::max)();
struct node
{
	double x,y;
}a[151];
int n;
double dist[151][151]={0},s[151]={0};
inline double calc(int x,int y)
{
	return sqrt((a[x].x-a[y].x)*(a[x].x-a[y].x)+(a[x].y-a[y].y)*(a[x].y-a[y].y));
}
int main(){
	cin>>n;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)scanf("%lf%lf",&a[i].x,&a[i].y);
	char c;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++)
	   {
	   	cin>>c;
        dist[i][j]=DOUBLE_MAX;
        if(i==j)dist[i][j]=0;
	   	if(c=='1')dist[i][j]=calc(i,j);
	   }
	   	for(int k=1;k<=n;k++)
	   	   for(int i=1;i<=n;i++)
	   	       for(int j=1;j<=n;j++)
	   	       	if(dist[i][k]!=DOUBLE_MAX&&dist[k][j]!=DOUBLE_MAX)dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	   	    double r1=-DOUBLE_MAX,r2=DOUBLE_MAX;
		for(int i=1;i<=n;i++)
		{
		for(int j=1;j<=n;j++)
		if(dist[i][j]!=DOUBLE_MAX)s[i]=max(s[i],dist[i][j]);
		r1=max(r1,s[i]);
	    }
		for(int i=1;i<=n;i++)
		{
		for(int j=1;j<=n;j++)
	    if(dist[i][j]==DOUBLE_MAX)r2=min(r2,s[i]+s[j]+calc(i,j));
	    }
	    printf("%0.6lf",max(r1,r2));
	return 0;
}
