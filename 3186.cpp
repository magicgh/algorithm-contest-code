#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
   int position=0,catch_pos=-1,cnt=0;
   string word,sentence;
   getline(cin,word);
   getline(cin,sentence);
   word=" "+word+" ";
   sentence=" "+sentence+" ";
   for(int i=0;i<word.size();i++)word[i]=toupper(word[i]);
   for(int i=0;i<sentence.size();i++)sentence[i]=toupper(sentence[i]);
   position=catch_pos=sentence.find(word);
   while(position!=-1)
   {
   position=sentence.find(word,position+1);
   cnt++;
   }
   if(catch_pos!=-1)cout<<cnt<<' '<<catch_pos<<endl;
   else puts("-1");
   return 0;
}