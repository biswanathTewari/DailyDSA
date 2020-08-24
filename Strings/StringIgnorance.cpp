/*
https://practice.geeksforgeeks.org/problems/string-ignorance/0
DailyDSA: biZan7X
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

  int t;
  cin>>t;
  cin.ignore();

  while(t--){

    string s;
    getline(cin,s);

    map<char,int> mp;

    string res;

    for(int i=0;i<s.length();i++){

      char x = tolower(s[i]);
      if(mp.find(x) == mp.end()){ //if first occurance
        res.push_back(s[i]);
        mp[x] = 1;
      }
      else{
        if(mp[x] == 0){ //allowed
          res.push_back(s[i]);
          mp[x] = 1;
        }
        else mp[x] = 0; //mp[x] = 1 i.e., the alternate occurance .
      }

    }

    cout<<res<<endl;

  }

  return 0;
}
