#include<bits/stdc++.h>
using namespace std;

string encoding(string str){
   string result = "";
   int cnt0=0, cnt1=0;
   for(char ch : str){
      if(ch == '0'){
         if(cnt1>0){
            result += to_string(cnt1);
            cnt1 = 0;
         }
         cnt0++;
      }else{
         if(cnt0>0){
            result += to_string(cnt0);
            cnt0 = 0;
         }
         cnt1++;
      }
   }
   if(cnt0>0)
      result += to_string(cnt0);
   if(cnt1>0)
      result += to_string(cnt1);
   return result; 
}

int main() { 
  string s = "001100001100";
  //cout<<encoding(s)<<endl;
  return 0;
  
} 
