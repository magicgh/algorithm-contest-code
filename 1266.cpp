#include<iostream>
using namespace std;
int main()
{
long long a=1,b=1,s=3,i,n;//a分子 b分母 s它们的和 
cin>>n;
if(n==1)//在n等于1的情况下做特殊处理。 
{
a=1;b=1;
}
else
for(i=1;i<n;i++)//n-1的循环 
{
                
                
  if(s%2==1) //情况1 a++ b-- 
  {
  if(a==1)//特殊情况 a为1 和就会加1 因为b++ （1/2就变成了1/3，1/3属于和是偶数的b不为0情况 按照规律应是a++;b--;结果是1/2） 
  {
   
   b++;
   s++;
}
else// 情况1 a++ b-- 
{
    a--;
    b++;
}
}
else//情况2 a-- b++ 
{
if(b==1)//特殊情况 b为1 和也会加1 因为a++ （2/1变成3/1） 
{
  a++;
  
  s++;
}
else//情况2 a-- b++
{
  a++;
  b--;
}

}
}
cout<<a<<"/"<<b;
//system("pause");
return 0;
}
