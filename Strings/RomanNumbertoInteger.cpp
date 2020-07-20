#include<bits/stdc++.h>
using namespace std;



int main(){

  int t;
  cin>>t;

  map<char,int> mp;
  mp['I'] = 1;
  mp['V'] = 5;
  mp['X'] = 10;
  mp['L'] = 50;
  mp['C'] = 100;
  mp['D'] = 500;
  mp['M'] = 1000;

  while(t--){

    string s;
    cin>>s;
    int val = mp[s[0]];

    for(int i=1;i<s.length();i++) //adding each char's value
      if(mp[s[i-1]] < mp[s[i]]) //only catch is that if the previous char had smaller value then it was supposed to be subtracted
        val += mp[s[i]] - (2*mp[s[i-1]]); //we already added the previous , so we are subtracting with its double
      else val+= mp[s[i]];

    cout<<val<<endl;

  }

  return 0;
}
