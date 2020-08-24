/*
https://practice.geeksforgeeks.org/problems/most-frequent-word-in-an-array-of-strings/0
DailyDSA: biZan7X
*/

#include<bits/stdc++.h>
using namespace std;


string MFS(string a[],int n){

  map<string,int> mp;
  int count = INT_MIN;

  for(int i=0;i<n;i++){

    mp[a[i]]++;
    count = max(count,mp[a[i]]);

  }

  string res;

  for(int i=0;i<n;i++){ //finding the first last occurance of the highest freq word
    if(mp[a[i]] == count){
      res = a[i];
      mp[a[i]] = -1;
    }
  }

  return res;

}


int main(){

  int t;
  cin>>t;

  while(t--){

    int n;
    cin>>n;

    string a[n];

    for(int i=0;i<n;i++)
      cin>>a[i];

    cout<<MFS(a,n)<<endl;

  }
  return 0;
}
