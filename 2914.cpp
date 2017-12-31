#include<iostream>
#include<cstring>
using namespace std;
int a[200005],b[200005],c[200005];
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
void jian(int a[],int b[])
{  int flag,i; 
   flag=cmp(a,b); 
   if (flag==0) {a[0]=0;return;}
   if(flag==1)   
   {  for(i=1;i<=a[0];i++) 
      {  if(a[i]<b[i]){ a[i+1]--;a[i]+=10;}
         a[i]=a[i]-b[i];
      } 
      while(a[0]>0&&a[a[0]]==0) a[0]--;  
      return;
   } 
   if (flag==-1)
   {  cout<<"-"; 
      for(i=1;i<=b[0];i++)
      {  if(b[i]<a[i]){b[i+1]--;b[i]+=10;} 
         a[i]=b[i]-a[i];
      } 
      a[0]=b[0]; 
      while(a[0]>0&&a[a[0]]==0) a[0]--;
      return;
   } 
}
void numcpy(int p[],int q[],int det)
{  for(int i=1;i<=p[0];i++)q[i+det-1]=p[i];
   q[0]=p[0]+det-1;
}
void chugao(int a[],int b[])
{  int i,j,tmp[200005]; 
   c[0]=a[0]-b[0]+1;
   for(i=c[0];i>0;i--)
   { memset(tmp,0,sizeof(tmp));
      numcpy(b,tmp,i);
      while(cmp(a,tmp)>=0){c[i]++;jian(a,tmp);}
   }
   while(c[0]>0&&c[c[0]]==0)c[0]--;
}
void output(int a[],int b[])
{
	int i;
	if(a[0]==0)cout<<0;
	for(i=a[0];i>0;i--)cout<<a[i];	
	cout<<endl;
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

int main(){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
    input(a,b);
    chugao(a,b);
	output(c,a);
	return 0;
}