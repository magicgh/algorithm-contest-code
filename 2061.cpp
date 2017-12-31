#include<iostream>
using namespace std;
long long day[8]={0},tian=0;
int month(int a,int b)
{
	if(b==2){
	  if(a%400==0)return 29;
	  if(a%100==0)return 28;
	  if(a%4==0)return 29;
	  return 28;
	}
	if(b==4||b==6||b==9||b==11)return 30;
	return 31;
}
void date(int a)
{
	int i,j;
	for(i=1900;i<1900+a;i++)
	{	for(j=1;j<=12;j++)
		{	day[tian%7]++;
			tian+=month(i,j);
		}
	}
	for(i=0;i<=6;i++)cout<<day[i]<<' ';
}
int main(){
  int n;
  cin>>n;
   date(n);

	return 0;
}
