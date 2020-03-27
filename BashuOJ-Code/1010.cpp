#include<iostream>
#include<cstring>
using namespace std;
char a[25],b[25];
void plant(char a[],char b[],int c)
{
	int i=0;
cout<<b[c-1];
while(a[i]!=b[c-1])i++;
if(i>0)plant(a,b,i);
if(i<c-1)plant(a+i+1,b+i,c-i-1);
}
int main(){
cin>>a>>b;
plant(a,b,strlen(b));
	return 0;
}
