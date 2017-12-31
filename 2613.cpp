#include <iostream>
using namespace std;
int main()
{
    int n, i;
    string s;
    cin>>n;
    for(i=1; i<=n; i++){
        cin>>s;
        if(s[s.length() - 1] % 2)
            cout<<"odd"<<endl;
        else 
            cout<<"even"<<endl;
    }
    //system("pause");
    return 0;
}
