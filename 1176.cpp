#include<iostream>
#include<cstring>
using namespace std;
int c[3005],d[3005];
void output(int a[])
{
	int i;
	for(i=a[0];i>0;i--)cout<<a[i];
	cout<<endl;
	return;
}
int cmp(int a[],int b[])
{  
int i; 
if(a[0]>b[0])return 1;  
if(a[0]<b[0])return -1; 
for(i=a[0];i>0;i--)  
   {  if(a[i]>b[i])return 1; 
      if(a[i]<b[i])return -1;
} 
return 0;
} 
void MultLow(int a[])  
{  int i,j,len;
   for(i=1;i<=a[0];i++)a[i]=a[i]*2;
   for(i=1;i<=a[0];i++){a[i+1]+=a[i]/10;a[i]%=10;} 
   while(a[a[0]+1]>0)
{
	a[0]++;
	a[a[0]+1]+=a[a[0]]/10;
	a[a[0]]%=10; 
}
   return;
}
void Minus(int a[],int b[])
{  int i; 
    for(i=1;i<=a[0];i++) 
      {  if(a[i]<b[i]){ a[i+1]--;a[i]+=10;}  
         a[i]=a[i]-b[i];
		 }
      while(a[0]>1&&a[a[0]]==0) a[0]--; 
      return;
   } 
 void MultHigh(int a[],int b[])  
{  int i,j,len;
   for(i=1;i<=a[0];i++)
      for(j=1;j<=b[0];j++)d[i+j-1]+=a[i]*b[j];
   d[0]=a[0]+b[0];
   for(i=1;i<=d[0];i++){d[i+1]+=d[i]/10;d[i]%=10;} 
   while(d[0]>1&&d[d[0]]==0)d[0]--;
   return;
}  
void Div(int a[])
{  int i,num=0; 
   for(i=a[0];i>=1;i--)  
{  num=num*10+a[i];   
   a[i]=num/2;   
    num%=2;   
}
   while(a[0]>1&&a[a[0]]==0)a[0]--;
   return;
}
void input(int a[],int b[]) 
{  string s1,s2; 
    int i;
   cin>>s1>>s2;
   a[0]=s1.length(); 
   b[0]=s2.length(); 
   for(i=1;i<=a[0];i++)a[i]=s1[a[0]-i]-'0';
   for(i=1;i<=b[0];i++)b[i]=s2[b[0]-i]-'0'; 
   return;
}
int main()
{
	int a[3005],b[3005];
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	c[0]=c[1]=1;
	input(a,b);
    int f=1;
	while(f)
	{
	if(a[1]%2==0&&b[1]%2==0)
	{
		Div(a);
		Div(b);
		MultLow(c);
	}
	if(a[1]%2==0&&b[1]%2==1)Div(a);
	if(a[1]%2==1&&b[1]%2==0)Div(b);
	else
	{
		f=cmp(a,b);
		if(f==0)break;
		else if(f==1)Minus(a,b);
		else Minus(b,a);
		
	}
	}
	MultHigh(c,a);
	output(d);
	return 0;
}