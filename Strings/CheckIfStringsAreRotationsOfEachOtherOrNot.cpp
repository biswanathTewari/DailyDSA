/*
https://practice.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not/0
DailyDSA: biZan7X
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int rotations(string a,string b){

  if(a.length() != b.length())
    return 0;

  a+=a; //this is the trick.. yup just this much..... 

  ll n = b.length();

  for(int i=0;i<a.length();i++)
    if(a.substr(i,n) == b)
      return 1;

  return 0;

}


int main(){

  int t;
  cin>>t;

  while(t--){

    string s1,s2;
    cin>>s1>>s2;

    cout<<rotations(s1,s2)<<endl;

  }

  return 0;
}
