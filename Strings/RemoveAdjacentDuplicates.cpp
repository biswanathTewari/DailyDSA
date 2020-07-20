#include<bits/stdc++.h>
using namespace std;

string terminator(string s){ //eliminates the adjacent duplicates

  string r = "";//new string
  int i=0;

  while(s[i]){ //till the end of the string

    if(s[i] != s[i+1]){ //if the current char does not match with the next char
      r += s[i];
      i++;//increment to next
    }

    if(s[i] && s[i] == s[i+1]){ //if the current char is not a null and it matches with the next char

      while(s[i] == s[i+1]) //bypassing the adjacent duplicates
        i++;

      i++;//increment to next
    }
  }

  int f = 0;

  for(i=0;i+1<r.length();i++)
    if(r[i] == r[i+1]){
      f = 1;
      break;
    }

  if(f) //if still adjacent dupliactes exists
    r = terminator(r);

  return r;
}


int main(){

  int t;
  cin>>t;

  while(t--){

    string s;
    cin>>s;

    string r = terminator(s);

    cout<<r<<endl;

  }

  return 0;
}
