#include<iostream>
using namespace std;
int main() 
{
char a,b;

cin>>a>>b;
if(a=='S'&&b=='R') cout<<"Fall"; 
if(a=='S'&&b=='P') cout<<"Win"; 
if(a=='S'&&b=='S') cout<<"Equ"; 
if(a=='R'&&b=='P') cout<<"Fall";
if(a=='R'&&b=='P') cout<<"Win";
if(a=='R'&&b=='R') cout<<"Equ";
if(a=='P'&&b=='S') cout<<"Fall";
if(a=='P'&&b=='R') cout<<"Win";
if(a=='P'&&b=='P') cout<<"Equ";
//system("pause");
return 0;
}
