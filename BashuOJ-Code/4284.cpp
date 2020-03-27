#include<iostream>
using namespace std;
int map[6][6]={
	{0,0,1,1,0},
	{1,0,0,1,0},
	{0,1,0,0,1},
	{0,0,1,0,1},
	{1,1,0,0,0}
};
int na,nb,n,a[205]={0},b[205]={0},ans1=0,ans2=0,x,y;
int main()
{
    int i;
    cin>>n>>na>>nb;
    for(i=0;i<na;i++)cin>>a[i];
    for(i=0;i<nb;i++)cin>>b[i];
    for(i=0;i<n;i++)
	{
		x=a[i%na],y=b[i%nb];
		if(map[x][y])ans1++;
		if(map[y][x])ans2++;
	}
cout<<ans1<<' '<<ans2;
return 0;
}
