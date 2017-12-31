#include<iostream>
using namespace std;
long long huahua[10000]={0},duishou[10000]={0},i=1,j=1,hh[10000]={0},ds[10000]={0};
int main(){
    
    char fenshu;
    for(cin>>fenshu; fenshu!='E';cin>>fenshu)
    {
      if(fenshu=='W'){huahua[i]++;hh[j]++;}  if(fenshu=='L') {duishou[i]++;ds[j]++;}
      if(huahua[i]>=11&&huahua[i]>duishou[i]&&huahua[i]-duishou[i]>1||duishou[i]>=11&&duishou[i]>huahua[i]&&duishou[i]-huahua[i]>1)
      {
        i++;
      } 
      if(hh[j]>=21&&hh[j]>ds[j]&&hh[j]-ds[j]>1||ds[j]>=21&&ds[j]>hh[j]&&ds[j]-hh[j]>1)
      {
        j++;
      }
      
    }
    for(int k=1;k<=i;k++)
    {cout<<huahua[k]<<":"<<duishou[k]<<endl;}
    cout<<endl;
    for(int z=1;z<=j;z++)
    {
      cout<<hh[z]<<":"<<ds[z]<<endl;}
    //system("pause");
    return 0;
    
}
