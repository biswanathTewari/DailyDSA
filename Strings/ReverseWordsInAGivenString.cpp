#include<bits/stdc++.h>
using namespace std;


int main(){

  int t;
  cin>>t;

  while(t--){

    string s;
    cin>>s;

    vector<string> v;
    string temp = "";

    for(int i=0;i<s.length();i++){

      if(s[i] != '.')
        temp+=s[i];

      if(s[i] == '.' || i == s.length()-1){
        v.push_back(temp);
        temp = "";
      }

    }

    cout<<v[v.size()-1];

    for(int i = v.size()-2;i>=0;i--){
      cout<<".";
      cout<<v[i];
    }

    cout<<endl;

  }

  return 0;
}
