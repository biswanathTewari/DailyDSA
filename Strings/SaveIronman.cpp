/*
https://practice.geeksforgeeks.org/problems/save-ironman/0
DailyDSA: biZan7X
*/

#include<bits/stdc++.h>
using namespace std;


string palin(string s){

  string res;

  for(int i=0;i<s.length();i++){
    if(s[i] >= 'a' && s[i] <= 'z')
      res.push_back(s[i]);

    else if(s[i] >= 'A' && s[i] <= 'Z')
      res.push_back(tolower(s[i]));

    else if(s[i]>= '0' && s[i]<='9')
      res.push_back(s[i]);
  }

  int len = res.length();

  for(int i=0;i<len/2;i++)
    if(res[i] != res[len-1-i])
      return string("NO");

  return string("YES");

}


int main(){

  int t;
  cin>>t;
  cin.ignore();

  while(t--){

    string s;
    getline(cin,s);

    cout<<palin(s)<<endl;

  }
  return 0;
}
