#include<iostream>
using namespace std;
int a[200010];
void qsort(int l,int r)
{ 
     int i,j,mid,p; 
     i=l;j=r;mid=a[(l+r)/2]; 
     while(i<=j)  
     { 
        while(a[i]<mid)i++;  
        while(a[j]>mid)j--;   
            if(i<=j)       
               {
                p=a[i];a[i]=a[j];a[j]=p;
                i++;j--;
               } 
                } 
            if(l<j)qsort(l,j);
            if(i<r)qsort(i,r);
                   }
int main()
        {  
        int n,i,j,t=1;  
        cin>>n; 
        for(i=1;i<=n;i++)cin>>a[i];
        qsort(1,n);
        for(i=2;i<=n;i++){
        if(a[i]!=a[i-1])
        {cout<<a[i-1]<<" "<<t<<endl;t=1;}     
        if(a[i]==a[i-1])t++;}  
        cout<<a[n]<<" "<<t;
        //system("pause"); 
        return 0;
        }

